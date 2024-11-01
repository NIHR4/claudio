#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchProgram(antlr4::Token *nextToken);
}