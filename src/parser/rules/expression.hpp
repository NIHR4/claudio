#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchExpression(antlr4::Token *nextToken);
}