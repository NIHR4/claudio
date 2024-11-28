#pragma once
#include <variant>
#include <string>
#include "../lexer/claudio.h"

enum class Symbols{
    START,
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
    ASSIGNMENT_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    PROCEDURE_STATEMENT,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    ASSIGNMENT_TAIL,
    EXPRESSION_TAIL,
    BINARY_OP,
    UNARY_OP,
    FACTOR,
    STATEMENT_TAIL,
    INTEGER_LITERAL,
    STRING_LITERAL,
    IF_STATEMENT_PRIME,
    PARAMETER_LIST,
    TYPE
    

};

namespace tag
{
    namespace impl
    {
        template <typename T>
        struct BaseSymbol
        {
            using type = typename T;
            T val;
            explicit BaseSymbol(T pVal) : val(pVal) {}
            BaseSymbol() = default;
        };

        template<typename T>
        struct tagNonTerminalSymbol : BaseSymbol<T>{
            explicit tagNonTerminalSymbol(T arg) : BaseSymbol<T>(arg) {}
            tagNonTerminalSymbol() : BaseSymbol<T>() {}
        };
        

        template<typename T>
        struct tagTerminalSymbol : BaseSymbol<T>{
            explicit tagTerminalSymbol(T arg) : BaseSymbol<T>(arg) {}
            tagTerminalSymbol() : BaseSymbol<T>() {}
        };
    }

    //current
    using term =  impl::tagTerminalSymbol<size_t>;
    using nterm = impl::tagNonTerminalSymbol<Symbols>;

}

using AnySymbol = std::variant<std::monostate, tag::term,  tag::nterm>; 



std::string symbolToString(Symbols symbol);
std::string tokenToString(int token);

