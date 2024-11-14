#include "statement_tail.hpp"


std::vector<AnySymbol> parse_rules::statementTail(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchPlus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchMul, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchDiv, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchLessThan, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchGreaterThan, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
        {TE::matchAssign, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::EXPRESSION_TAIL)
            }; 
        }},
    };
    
    return findProductionRule(productionRules, nextToken);   
}
