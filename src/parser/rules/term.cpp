#include "term.hpp"


std::vector<AnySymbol> parse_rules::term(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchIdentifier, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
            }; 
        }},
        {TE::matchNumber, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
            }; 
        }},
        {TE::matchLParen, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
            }; 
        }},
    };  
    
    return findProductionRule(productionRules, nextToken);
}

std::vector<AnySymbol> parse_rules::termPrime(antlr4::Token *nextToken) {
    const std::vector<ProductionRule> productionRules {
        {TE::matchPlus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
        {TE::matchMinus, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                //empty
            }; 
        }},
        {TE::matchMul, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::MUL),
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
            }; 
        }},
        {TE::matchDiv, [](antlr4::Token *) -> std::vector<AnySymbol> {
            return {
                tag::terminal(lexer::claudio::DIV),
                tag::nonterminal(Symbols::FACTOR),
                tag::nonterminal(Symbols::TERM_P)
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
        }}
    };
        
    return findProductionRule(productionRules, nextToken);
}
