#include "literal_expression.hpp"


std::vector<AnySymbol> parse_rules::literalExpression(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::INTEGER_LITERAL)
            }; 
        }},
        {TE::matchStrLiteral, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::STRING_LITERAL)
            }; 
        }},
    };

    return findProductionRule(productionRules, nextToken);

}
