#include "for_statement.hpp"


std::vector<AnySymbol> parse_rules::forStatement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchFor, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::FOR),
                tag::terminal(lexer::claudio::LPAREN),
                tag::nonterminal(Symbols::ASSIGNMENT_STATEMENT),
                tag::terminal(lexer::claudio::SEMICOLON),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::SEMICOLON),
                tag::nonterminal(Symbols::INCREMENT_EXPR),
                tag::terminal(lexer::claudio::RPAREN),
                tag::nonterminal(Symbols::STATEMENT)

            }; 
        }},
    };    
    return findProductionRule(productionRules, nextToken);
    
}
