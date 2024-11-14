#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> expressionTail(antlr4::Token *nextToken);
}