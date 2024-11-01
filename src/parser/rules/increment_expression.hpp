#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchIncrementExpr(antlr4::Token *nextToken);
}