#include "program.hpp"


namespace parse_rules {
    std::vector<SymbolMix> matchProgram(antlr4::Token *nextToken)
    {
        const auto tokenType = static_cast<size_t>(nextToken->getType());
        const std::vector<ProductionRule> productionRules
        {
            {TE::MatchIdentifier, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //identifier
            {TE::MatchDigit, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //numbers
            {TE::MatchIf, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //if-statement
            {TE::MatchWhile, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //while-statement
            {TE::MatchFor, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //for-statement
            {TE::MatchProcedure, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}},  //procedure
            {TE::MatchReturn, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //return
            {TE::MatchBreak, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, //break
            {TE::MatchLParen, [](antlr4::Token*) -> std::vector<SymbolMix> {return {Symbols::STATEMENT_LIST};}}, // lparen
            {TE::MatchEOF, [](antlr4::Token*) -> std::vector<SymbolMix> {return {};}}, // eof


        };
         // Find the matching production rule.
        auto it = std::find_if(productionRules.begin(), productionRules.end(),
        [&tokenType](const ProductionRule& rule) {
            return rule.matcher(tokenType);
        });

         // Call the production if a match is found.
        if (it != productionRules.end()) return it->production(nextToken);
        else throw std::runtime_error("no production rules match");

    }
}
