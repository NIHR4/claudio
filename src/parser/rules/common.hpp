#pragma once
#include "symbols.hpp"
#include "../../lexer/claudio.h"
#include <functional>
#include <vector>
// Terminal-symbol evaluator
namespace TE
{
    using namespace lexer;
    inline bool MatchIdentifier(size_t tok) { return tok == claudio::ID;  }
    inline bool MatchDigit(size_t tok) { return tok == claudio::INT_LITERAL; }
    inline bool MatchIf(size_t tok) { return tok == claudio::IF; }
    inline bool MatchIfNot(size_t tok) { return tok == claudio::NEQ; }
    inline bool MatchWhile(size_t tok) { return tok == claudio::WHILE; }
    inline bool MatchFor(size_t tok) { return tok == claudio::FOR; } 
    inline bool MatchProcedure(size_t tok) { return tok == claudio::FUNCTION; }
    inline bool MatchReturn(size_t tok) { return tok == claudio::RETURN; }
    inline bool MatchBreak(size_t tok) { return tok == claudio::BREAK; }
    inline bool MatchLParen(size_t tok) { return tok == claudio::LPAREN;}
    inline bool MatchEOF(size_t tok) { return tok == claudio::EOF;}
    inline bool MatchMinus(size_t tok) { return tok == claudio::MINUS;}
    inline bool MatchLBrace(size_t tok) { return tok == claudio::LBRACE;}
    inline bool MatchRBrace(size_t tok) { return tok == claudio::RBRACE;}
}

namespace parse_rules
{
    struct ProductionRule {
        using Production = std::function<std::vector<SymbolMix>(antlr4::Token *)>;
        bool (*matcher)(size_t);
        Production production;
    };
}