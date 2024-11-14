#include "program.hpp"


std::vector<AnySymbol> parse_rules::program(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchIf, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchWhile, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchFor, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchProcedure, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchReturn, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchBreak, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchEOF, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty production
            }; 
        }},        
    };

    return findProductionRule(productionRules, nextToken);
}
