#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> returnStatement(antlr4::Token *nextToken);
}