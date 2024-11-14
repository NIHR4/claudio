#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> forStatement(antlr4::Token *nextToken);
}