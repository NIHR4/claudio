#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> whileStatement(antlr4::Token *nextToken);
}