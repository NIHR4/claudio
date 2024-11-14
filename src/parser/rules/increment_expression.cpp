#include "increment_expression.hpp"


std::vector<AnySymbol> parse_rules::incrementExpression(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::ID),
                tag::terminal(lexer::claudio::INCREMENT)
            }; 
        }},
    };    

    return findProductionRule(productionRules, nextToken);
}
