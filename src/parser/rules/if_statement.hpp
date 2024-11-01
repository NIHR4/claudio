#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchIfStatement(antlr4::Token *nextToken);
    std::vector<SymbolMix> matchIfStatementPrime(antlr4::Token *nextToken);
}