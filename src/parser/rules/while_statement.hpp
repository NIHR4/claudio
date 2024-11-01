#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchWhileStatement(antlr4::Token *nextToken);
}