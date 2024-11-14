#pragma once
#include "../common.hpp"

namespace parse_rules {
    std::vector<AnySymbol> assignmentStatement(antlr4::Token *nextToken);
}