#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> unaryExpression(antlr4::Token *nextToken);
}