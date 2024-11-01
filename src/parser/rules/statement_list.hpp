#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchStatementList(antlr4::Token *nextToken);
}