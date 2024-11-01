#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchAssignmentStatement(antlr4::Token *nextToken);
}