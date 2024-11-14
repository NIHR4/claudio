#include "while_statement.hpp"


std::vector<AnySymbol> parse_rules::whileStatement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchWhile, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::WHILE),
                tag::terminal(lexer::claudio::LPAREN),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::RPAREN),
                tag::nonterminal(Symbols::STATEMENT)
            }; 
        }},
    };    
    return findProductionRule(productionRules, nextToken);
}
