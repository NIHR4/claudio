#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> literalExpression(antlr4::Token *nextToken);
}