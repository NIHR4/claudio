#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchProcedureStatement(antlr4::Token *nextToken);
}