#pragma once
#include "common.hpp"

namespace parse_rules {
    std::vector<SymbolMix> matchIdentifier(antlr4::Token *nextToken);
}