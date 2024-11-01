#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchBreakStatement(antlr4::Token *nextToken);
}