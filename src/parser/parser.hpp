#pragma once
#include <antlr4-runtime.h>
#include <treehh/tree.hh>
#include "symbols.hpp"
namespace parser {  
    tree<AnySymbol> parse(antlr4::CommonTokenStream& stream);
}