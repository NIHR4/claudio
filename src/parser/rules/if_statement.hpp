#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> ifStatement(antlr4::Token *nextToken);
    std::vector<AnySymbol> ifStatementPrime(antlr4::Token *nextToken);
}