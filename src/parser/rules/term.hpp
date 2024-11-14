#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> term(antlr4::Token *nextToken);
    std::vector<AnySymbol> termPrime(antlr4::Token *nextToken);
}