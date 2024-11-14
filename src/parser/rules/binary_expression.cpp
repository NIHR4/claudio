#include "binary_expression.hpp"


std::vector<AnySymbol> parse_rules::binaryExpression(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION)
            }; 
        }},
    };

    const auto tokenType = static_cast<size_t>(nextToken->getType());
    auto it = std::find_if(productionRules.begin(), productionRules.end(),
        [&tokenType](const ProductionRule& rule) {
        return rule.matcher(tokenType);
        }
    );
    if (it != productionRules.end()) return it->production(nextToken);
    else throw std::runtime_error("no production rules match");    
}

std::vector<AnySymbol> parse_rules::binaryExpressionPrime(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchPlus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchMul, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchDiv, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchLessThan, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchGreaterThan, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchEq, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchNotEq, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::BINARY_OP),
                tag::nonterminal(Symbols::EXPRESSION),
                tag::nonterminal(Symbols::BINARY_EXPR_P),
            }; 
        }},
        {TE::matchRParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
        {TE::matchSemicolon, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
        
    };

    return findProductionRule(productionRules, nextToken);
}
