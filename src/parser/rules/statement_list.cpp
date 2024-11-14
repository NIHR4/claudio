#include "statement_list.hpp"


std::vector<AnySymbol> parse_rules::statementList(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchIf, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchWhile, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchFor, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchProcedure, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchReturn, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST),
                tag::terminal(lexer::claudio::SEMICOLON)
            }; 
        }},
        {TE::matchBreak, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST),
                tag::terminal(lexer::claudio::SEMICOLON)

            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STATEMENT),
                tag::nonterminal(Symbols::STATEMENT_LIST)
            }; 
        }},
        {TE::matchRBrace, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
        {TE::matchEOF, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
    };
    
    assert(productionRules.size() == 12);
    
    return findProductionRule(productionRules, nextToken);
}
