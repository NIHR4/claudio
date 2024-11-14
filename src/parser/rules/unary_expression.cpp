#include "unary_expression.hpp"


std::vector<AnySymbol> parse_rules::unaryExpression(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
        {TE::matchIncrement, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
        {TE::matchDecrement, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
    };

    return findProductionRule(productionRules, nextToken); 
}
