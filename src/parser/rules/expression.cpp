#include "expression.hpp"


std::vector<AnySymbol> parse_rules::expression(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_EXPR)
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::LITERAL_EXPR)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_EXPR)
            }; 
        }},
        {TE::matchIncrement, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_EXPR)
            }; 
        }},
        {TE::matchDecrement, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::UNARY_EXPR)
            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::LPAREN),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::terminal(lexer::claudio::RPAREN)
            }; 
        }},
    };

    return findProductionRule(productionRules, nextToken);
}
