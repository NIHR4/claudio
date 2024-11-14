#pragma once
#include "symbols.hpp"
#include "../lexer/claudio.h"
#include <functional>
#include <vector>
// Terminal-symbol Evaluator
namespace TE
{
    using namespace lexer;
    inline bool matchIdentifier(size_t tok) { return tok == claudio::ID;  }
    inline bool matchNumber(size_t tok) { return tok == claudio::INT_LITERAL; }
    inline bool matchIf(size_t tok) { return tok == claudio::IF; }
    inline bool matchIfNot(size_t tok) { return tok == claudio::NEQ; }
    inline bool matchWhile(size_t tok) { return tok == claudio::WHILE; }
    inline bool matchFor(size_t tok) { return tok == claudio::FOR; } 
    inline bool matchProcedure(size_t tok) { return tok == claudio::FUNCTION; }
    inline bool matchReturn(size_t tok) { return tok == claudio::RETURN; }
    inline bool matchBreak(size_t tok) { return tok == claudio::BREAK; }
    inline bool matchLParen(size_t tok) { return tok == claudio::LPAREN;}
    inline bool matchRParen(size_t tok) { return tok == claudio::RPAREN;}
    inline bool matchEOF(size_t tok) { return tok == claudio::EOF;}
    inline bool matchMinus(size_t tok) { return tok == claudio::MINUS;}
    inline bool matchLBrace(size_t tok) { return tok == claudio::LBRACE;}
    inline bool matchRBrace(size_t tok) { return tok == claudio::RBRACE;}
    inline bool matchPlus(size_t tok) { return tok == claudio::PLUS;}
    inline bool matchMul(size_t tok) { return tok == claudio::MUL;}
    inline bool matchDiv(size_t tok) { return tok == claudio::DIV;}
    inline bool matchGreaterThan(size_t tok) { return tok == claudio::GR_THAN;}
    inline bool matchLessThan(size_t tok) { return tok == claudio::LS_THAN;}
    inline bool matchEq(size_t tok) {return tok == claudio::EQ;}
    inline bool matchNotEq(size_t tok) {return tok == claudio::NEQ;}
    inline bool matchIncrement(size_t tok) {return tok == claudio::INCREMENT;}
    inline bool matchDecrement(size_t tok) {return tok == claudio::DECREMENT;}
    inline bool matchSemicolon(size_t tok) {return tok == claudio::SEMICOLON;}
    inline bool matchStrLiteral(size_t tok) {return tok == claudio::STRING_LITERAL;}
    inline bool matchAssign(size_t tok) { return tok == claudio::ASSIGN;}
    inline bool matchElse(size_t tok) {return tok == claudio::ELSE;}
    


}

namespace parse_rules
{
    struct ProductionRule {
        using Production = std::function<std::vector<AnySymbol>(antlr4::Token *)>;
        //fields
        bool (*matcher)(size_t);
        Production production;
    };
    typedef bool(*MatcherPtr)(size_t);
    std::string getMatcherName(MatcherPtr ptr);
    std::vector<AnySymbol> findProductionRule(const std::vector<ProductionRule>& rules, antlr4::Token * token, std::string originator="undefined");
}

