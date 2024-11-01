#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchBinaryExpression(antlr4::Token *nextToken);
    std::vector<SymbolMix> matchBinaryExpressionPrime(antlr4::Token *nextToken);
}