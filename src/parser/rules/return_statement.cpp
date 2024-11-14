#include "return_statement.hpp"


std::vector<AnySymbol> parse_rules::returnStatement(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchReturn, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::RETURN),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
    };    
    return findProductionRule(productionRules, nextToken);
}
