#include "if_statement.hpp"


std::vector<AnySymbol> parse_rules::ifStatement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIf, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::IF),
                tag::terminal(lexer::claudio::LPAREN),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::RPAREN),
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::IF_STATEMENT_PRIME),
            }; 
        }},
    };    

    return findProductionRule(productionRules, nextToken);
}

std::vector<AnySymbol> parse_rules::ifStatementPrime(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchIf, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchElse, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::ELSE),
                tag::nonterminal(Symbols::STATEMENT)
            }; 
        }},
        {TE::matchWhile, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchFor, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchProcedure, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchBreak, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchRBrace, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
        {TE::matchEOF, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                
            }; 
        }},
    };    

    return findProductionRule(productionRules, nextToken);
}
