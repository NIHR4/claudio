#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> statement(antlr4::Token *nextToken);
}