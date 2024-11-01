#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchReturnStatement(antlr4::Token *nextToken);
}