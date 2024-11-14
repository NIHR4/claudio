#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> expression(antlr4::Token *nextToken);
}