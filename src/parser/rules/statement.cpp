#include "statement.hpp"


std::vector<AnySymbol> parse_rules::statement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::ID),
                tag::nonterminal(Symbols::STATEMENT_TAIL),
                tag::terminal(lexer::claudio::SEMICOLON)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::SEMICOLON)
            }; 
        }},
        {TE::matchIf, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::IF_STATEMENT)
            }; 
        }},
        {TE::matchWhile, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::WHILE_STATEMENT)
            }; 
        }},
        {TE::matchFor, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::FOR_STATEMENT)
            }; 
        }},
        {TE::matchProcedure, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::PROCEDURE_STATEMENT)
            }; 
        }},
        {TE::matchReturn, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::RETURN_STATEMENT)
            }; 
        }},
        {TE::matchBreak, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BREAK_STATEMENT)
            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
    };  

    assert(productionRules.size() == 9);
    
    return findProductionRule(productionRules, nextToken);
}
