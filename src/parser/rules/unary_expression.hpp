#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchUnaryExpression(antlr4::Token *nextToken);
}