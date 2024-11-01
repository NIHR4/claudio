#include "statement_list.hpp"

std::vector<SymbolMix> parse_rules::matchStatementList(antlr4::Token *nextToken)
{
    const auto tokenType = static_cast<size_t>(nextToken->getType());
    const std::vector<ProductionRule> productionRules{
        //identifiers
        {TE::MatchIdentifier, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //number
        {TE::MatchDigit, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //operator - 
        {TE::MatchMinus, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //if-statement
        {TE::MatchIf, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //while-statement
        {TE::MatchWhile, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //for-statement
        {TE::MatchFor, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //procedure-statement
        {TE::MatchProcedure, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //return-statement
        {TE::MatchReturn, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //break-statement
        {TE::MatchBreak, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //left-parenthesees
        {TE::MatchLParen, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {
                Symbols::STATEMENT,
                Symbols::STATEMENT_LIST
            }; 
        }},
        //right-brace
        {TE::MatchRBrace, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {}; 
        }},
        //eof
        {TE::MatchEOF, [](antlr4::Token *) -> std::vector<SymbolMix> {
                return {}; 
        }},
        
    
    };
    // Find the matching production rule.
    auto it = std::find_if(productionRules.begin(), productionRules.end(),
    [&tokenType](const ProductionRule& rule) {
        return rule.matcher(tokenType);
    });

    throw std::runtime_error("no production rules match");
}

