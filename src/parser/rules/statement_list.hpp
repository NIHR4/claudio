#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> statementList(antlr4::Token *nextToken);
}