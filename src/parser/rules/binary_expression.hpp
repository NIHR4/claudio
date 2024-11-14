#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> binaryExpression(antlr4::Token *nextToken);
    std::vector<AnySymbol> binaryExpressionPrime(antlr4::Token *nextToken);
}