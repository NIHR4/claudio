#pragma once

#include "parser.hpp"
#include <functional>
#include <utility>
#include <variant>
#include <algorithm>

#include "../lexer/claudio.h"
#include "common.hpp"

//parsing rules
#include "rules/program.hpp"
#include "rules/statement_list.hpp"
#include "rules/statement.hpp"
#include "rules/expression.hpp"
#include "rules/statement_tail.hpp"
#include "rules/expression_tail.hpp"
#include "rules/binary_expression.hpp"
#include "rules/unary_expression.hpp"
#include "rules/term.hpp"
#include "rules/literal_expression.hpp"
#include "rules/increment_expression.hpp"
#include "rules/assignement_statement.hpp"
#include "rules/if_statement.hpp"
#include "rules/while_statement.hpp"
#include "rules/for_statement.hpp"
#include "rules/return_statement.hpp"
#define NOCASCADE(_EXPR_) _EXPR_ ; break;

void handleNonTerminals(std::stack<AnySymbol> &stack, AnySymbol &currentSymbol, antlr4::Token* token)
{
    auto symbol = std::get<tag::nonterminal>(currentSymbol).val;
    std::vector<AnySymbol> production;

    //Get production for symbol-token pair
    switch (symbol)
    {
        case Symbols::PROGRAM: NOCASCADE(production=parse_rules::program(token))
        case Symbols::STATEMENT_LIST: NOCASCADE(production=parse_rules::statementList(token))
        case Symbols::STATEMENT: NOCASCADE(production=parse_rules::statement(token))
        case Symbols::EXPRESSION: NOCASCADE(production=parse_rules::expression(token))
        case Symbols::STATEMENT_TAIL: NOCASCADE(production=parse_rules::statementTail(token))
        case Symbols::EXPRESSION_TAIL: NOCASCADE(production=parse_rules::expressionTail(token))
        case Symbols::BINARY_EXPR: NOCASCADE(production=parse_rules::binaryExpression(token))
        case Symbols::BINARY_EXPR_P: NOCASCADE(production=parse_rules::binaryExpressionPrime(token))
        case Symbols::UNARY_EXPR: NOCASCADE(production=parse_rules::unaryExpression(token))
        case Symbols::TERM: NOCASCADE(production=parse_rules::term(token))
        case Symbols::TERM_P: NOCASCADE(production=parse_rules::termPrime(token))
        case Symbols::LITERAL_EXPR: NOCASCADE(production=parse_rules::literalExpression(token))
        case Symbols::INCREMENT_EXPR: NOCASCADE(production=parse_rules::incrementExpression(token))
        case Symbols::ASSIGNMENT_STATEMENT: NOCASCADE(production=parse_rules::assignmentStatement(token))
        case Symbols::IF_STATEMENT: NOCASCADE(production=parse_rules::ifStatement(token))
        case Symbols::IF_STATEMENT_PRIME: NOCASCADE(production=parse_rules::ifStatementPrime(token))
        case Symbols::WHILE_STATEMENT: NOCASCADE(production=parse_rules::whileStatement(token))
        case Symbols::FOR_STATEMENT: NOCASCADE(production=parse_rules::forStatement(token))
        case Symbols::RETURN_STATEMENT: NOCASCADE(production=parse_rules::returnStatement(token))
    }

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

    symbolStack.push(tag::terminal(lexer::claudio::EOF));
    symbolStack.push(tag::nonterminal(Symbols::PROGRAM));
    while (!symbolStack.empty())
    {
        auto currentSymbol = symbolStack.top();
        symbolStack.pop();
        
        //Current token in the input stream
        antlr4::Token *token = tokenStream.get(inputIdx);

        //Parse Non-Terminal Symbols
        if(std::holds_alternative<tag::nonterminal>(currentSymbol)) {
            
            handleNonTerminals(symbolStack, currentSymbol, token);

        }
        //Parse Terminal Symbols
        else if(std::holds_alternative<tag::terminal>(currentSymbol)){
            auto terminalSymbol = std::get<tag::terminal>(currentSymbol).val;
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