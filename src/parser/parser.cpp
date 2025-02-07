#pragma once

#include "parser.hpp"
#include <functional>
#include <utility>
#include <variant>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "productions/productions.hpp"
#include "productions/tracer.hpp"
#include "symbols.hpp"
#include "treehh/tree.hh"
#include "../utils/overload.hpp"


class FactoriesMgr{
private:
    
    std::unordered_map<Symbols, std::unique_ptr<IBaseProductionFactory>> _factories;

    void initializeFactories() {
        _factories[Symbols::PROGRAM] = std::make_unique<Tracer>(std::make_unique<Programa>());
        _factories[Symbols::STATEMENT_LIST] = std::make_unique<Tracer>(std::make_unique<Statementlist>());
        _factories[Symbols::STATEMENT] = std::make_unique<Tracer>(std::make_unique<Statement>());
        _factories[Symbols::STATEMENT_TAIL] = std::make_unique<Tracer>(std::make_unique<StatementTail>());
        _factories[Symbols::EXPRESSION] = std::make_unique<Tracer>(std::make_unique<Expression>());
        _factories[Symbols::EXPRESSION_TAIL] = std::make_unique<Tracer>(std::make_unique<ExpressionTail>());
        _factories[Symbols::BINARY_EXPR] = std::make_unique<Tracer>(std::make_unique<BinaryExpression>());
        _factories[Symbols::BINARY_EXPR_P] = std::make_unique<Tracer>(std::make_unique<BinaryExpressionPrime>());
        _factories[Symbols::UNARY_EXPR] = std::make_unique<Tracer>(std::make_unique<UnaryExpression>());
        _factories[Symbols::LITERAL_EXPR] = std::make_unique<Tracer>(std::make_unique<LiteralExpression>());
        _factories[Symbols::TERM] = std::make_unique<Tracer>(std::make_unique<Term>());
        _factories[Symbols::TERM_P] = std::make_unique<Tracer>(std::make_unique<TermPrime>());
        _factories[Symbols::FACTOR] = std::make_unique<Tracer>(std::make_unique<Factor>());
        _factories[Symbols::IF_STATEMENT] = std::make_unique<Tracer>(std::make_unique<IfStatement>());
        _factories[Symbols::IF_STATEMENT_PRIME] = std::make_unique<Tracer>(std::make_unique<IfStatementPrime>());
        _factories[Symbols::WHILE_STATEMENT] = std::make_unique<Tracer>(std::make_unique<WhileStatement>());
        _factories[Symbols::FOR_STATEMENT] = std::make_unique<Tracer>(std::make_unique<ForStatement>());
        _factories[Symbols::PROCEDURE_STATEMENT] = std::make_unique<Tracer>(std::make_unique<ProcedureStatement>());
        _factories[Symbols::RETURN_STATEMENT] = std::make_unique<Tracer>(std::make_unique<ReturnStatement>());
        _factories[Symbols::BREAK_STATEMENT] = std::make_unique<Tracer>(std::make_unique<BreakStatement>());
        _factories[Symbols::ASSIGNMENT_STATEMENT] = std::make_unique<Tracer>(std::make_unique<AssignmentStatement>());
        _factories[Symbols::BINARY_OP] = std::make_unique<Tracer>(std::make_unique<BinaryOperator>());
        _factories[Symbols::UNARY_OP] = std::make_unique<Tracer>(std::make_unique<UnaryOperator>());
        _factories[Symbols::INCREMENT_EXPR] = std::make_unique<Tracer>(std::make_unique<IncrementExpression>());
        _factories[Symbols::TYPE] = std::make_unique<Tracer>(std::make_unique<Type>());
        _factories[Symbols::PARAMETER_LIST] = std::make_unique<Tracer>(std::make_unique<ParameterList>());
        _factories[Symbols::DECLARATION_STATEMENT] = std::make_unique<Tracer>(std::make_unique<DeclarationStatement>());

    }

public:
    static FactoriesMgr& get() {
        static FactoriesMgr instance;
        return instance;
    }

    FactoriesMgr() {
        initializeFactories();
    }

    IBaseProductionFactory* factoryForSymbol(Symbols symbol) {
        return _factories.at(symbol).get();
    }


};


void handleNonTerminals(std::stack<AnySymbol> &stack, AnySymbol &currentSymbol, antlr4::Token* token)
{
    auto symbol = std::get<tag::nterm>(currentSymbol).val;

    auto production = FactoriesMgr::get().factoryForSymbol(symbol)->create(token->getType());
    if(production.empty()) return;
    // update the stack
    std::for_each(
        production.rbegin(),
        production.rend(),
        [&stack](AnySymbol symbol)
        {
            stack.push(symbol);
        });
}


void printStack(std::stack<AnySymbol>& stack) {
    auto sCopy = stack;
    std::cout << "=======================\n";
    std::cout << "STACK TRACE:\n";
    for(int i=0; sCopy.size() > 0; i++){
        auto element = sCopy.top();
        if(std::holds_alternative<tag::nterm>(element)) {
            auto value = std::get<tag::nterm>(element) ;
            //std::cout << i << ")" << dye::aqua(value.val) << " (NT)\n";
            std::cout << i << "] " << symbolToString(value.val) << " (NT)\n";
        }
        else if(std::holds_alternative<tag::term>(element)) {
            auto value = std::get<tag::term>(element) ;
            std::cout << i << "] " << tokenToString(value.val) << " (T)\n";

        }

        sCopy.pop();
    }
    std::cout << "=======================\n";
}





void printSyntaxTree(tree<AnySymbol>& parseTree) {
    auto it = parseTree.begin();
    auto end = parseTree.end();
    
    while (it != end) {
        // Print indentation for the current depth, with vertical bars for structure
        for (int i = 0; i < parseTree.depth(it) - 1; ++i) {
            std::cout << "│  ";
        }

        // Add a connector to indicate the hierarchy
        if (parseTree.depth(it) > 0) {
            std::cout << "├──";
        }

        // Use std::visit to handle different symbol types
        std::visit(overloaded{
            [](tag::nterm& arg) { std::cout << "[Non-Terminal] " << symbolToString(arg.val) << "\n"; },
            [](tag::term& arg) { std::cout << "[Terminal] " << tokenToString(arg.val) << "\n"; },
            [](auto const& arg) {} // Handle any other cases gracefully
        }, *it);

        ++it;
    }
}



tree<AnySymbol> parser::parse(antlr4::CommonTokenStream &tokenStream)
{
    

    std::stack<AnySymbol> symbolStack;
    size_t inputIdx=0;
    
    symbolStack.push(tag::term(lexer::claudio::EOF));
    symbolStack.push(tag::nterm(Symbols::PROGRAM));
    tree<AnySymbol> parseTree(symbolStack.top());
    tree<AnySymbol>::iterator currentNode = parseTree.begin();
    
    while (inputIdx<tokenStream.size())
    {
        printStack(symbolStack);
        auto currentSymbol = symbolStack.top();
        symbolStack.pop();
        
        //Current token in the input stream
        antlr4::Token *token = tokenStream.get(inputIdx);
        std::cout << "Lookahead symbol: " << token->getText() << ". Type=" <<  tokenToString(token->getType())<< "\n";
    
        //Parse Non-Terminal Symbols
        if(std::holds_alternative<tag::nterm>(currentSymbol)) {
            
            if(std::get<tag::nterm>(currentSymbol).val != Symbols::PROGRAM){
                auto nextIt = parseTree.append_child(currentNode, currentSymbol);
                currentNode = nextIt;
            }
            
            try{
                handleNonTerminals(symbolStack, currentSymbol, token);
            }catch(std::runtime_error& ex) {
                std::cerr << std::format("\n\nSyntax error in line {}, position {}\n", token->getLine(), token->getCharPositionInLine());
                throw ex;
            }
            

        }
        //Parse Terminal Symbols
        else if(std::holds_alternative<tag::term>(currentSymbol)){
            parseTree.append_child(currentNode, currentSymbol);
            currentNode--;
            
            
            auto terminalSymbol = std::get<tag::term>(currentSymbol).val;
            if(terminalSymbol == token->getType()) {
                //Skip terminal
                inputIdx++;
                
            }
        }
       
    }
    
    if (inputIdx != tokenStream.size()) {
        throw std::runtime_error("Extra tokens in input.");
    }else{
        
        std::cout << "Parse tree:\n";
        printSyntaxTree(parseTree);
        
        std::cout << "Syntax is valid!";
        
    }
     return parseTree;

}