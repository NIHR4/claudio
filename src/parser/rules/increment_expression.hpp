#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> incrementExpression(antlr4::Token *nextToken);
}