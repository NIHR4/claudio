#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchTerm(antlr4::Token *nextToken);
    std::vector<SymbolMix> matchTermPrime(antlr4::Token *nextToken);
}