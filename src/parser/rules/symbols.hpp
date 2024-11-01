#include <variant>

enum class Symbols{
    PROGRAM,
    STATEMENT_LIST,
    STATEMENT,
    EXPRESSION,
    BINARY_EXPR,
    BINARY_EXPR_P,
    UNARY_EXPR,
    TERM,
    TERM_P,
    LITERAL_EXPR,
    IDENTIFIER,
    INCREMENT_EXPR,
    ASSIGNMENT_STATEMENTT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    PROCEDURE_STATEMENT,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    START,
};

template<typename HoldsT>
struct SymbolBase{
    HoldsT val;
    SymbolBase(HoldsT pVal) : val(pVal) {}
    SymbolBase() = default;
};

using tagNonTerminalSymb = SymbolBase<typename Symbols>;
using tagTerminalSymb =  SymbolBase<size_t>;
using SymbolMix = std::variant<tagNonTerminalSymb, tagTerminalSymb>; 
