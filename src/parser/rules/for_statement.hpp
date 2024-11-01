#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchForStatement(antlr4::Token *nextToken);
}