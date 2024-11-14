#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> program(antlr4::Token *nextToken);
}