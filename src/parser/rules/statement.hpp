#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchStatement(antlr4::Token *nextToken);
}