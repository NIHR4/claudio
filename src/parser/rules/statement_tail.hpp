#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> statementTail(antlr4::Token *nextToken);
}