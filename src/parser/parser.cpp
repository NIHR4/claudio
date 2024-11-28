#pragma once

#include "parser.hpp"
#include <functional>
#include <utility>
#include <variant>
#include <algorithm>

#include "../lexer/claudio.h"
#include "common.hpp"

//parsing rules
#include "productions/productions.hpp"
#include "productions/tracer.hpp"
#include <iostream>
#define NOCASCADE(_EXPR_) _EXPR_ ; break;



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

void parser::parse(antlr4::CommonTokenStream &tokenStream)
{
    
    std::stack<AnySymbol> symbolStack;
    size_t inputIdx=0;

    symbolStack.push(tag::term(lexer::claudio::EOF));
    symbolStack.push(tag::nterm(Symbols::PROGRAM));
    while (!symbolStack.empty())
    {
        auto currentSymbol = symbolStack.top();
        symbolStack.pop();
        
        //Current token in the input stream
        antlr4::Token *token = tokenStream.get(inputIdx);

        //Parse Non-Terminal Symbols
        if(std::holds_alternative<tag::nterm>(currentSymbol)) {
            
            handleNonTerminals(symbolStack, currentSymbol, token);

        }
        //Parse Terminal Symbols
        else if(std::holds_alternative<tag::term>(currentSymbol)){
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
        std::cout << "Syntax is valid!";
    }


}