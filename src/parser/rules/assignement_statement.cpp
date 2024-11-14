#include "assignement_statement.hpp"


std::vector<AnySymbol> parse_rules::assignmentStatement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::ID),
                tag::terminal(lexer::claudio::ASSIGN),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::SEMICOLON)
            }; 
        }},
    };    
    return findProductionRule(productionRules, nextToken);
}
