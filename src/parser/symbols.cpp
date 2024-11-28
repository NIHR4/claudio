#include "symbols.hpp"


std::string symbolToString(Symbols symbol) {
    switch (symbol) {
        case Symbols::START: return "START";
        case Symbols::PROGRAM: return "PROGRAM";
        case Symbols::STATEMENT_LIST: return "STATEMENT_LIST";
        case Symbols::STATEMENT: return "STATEMENT";
        case Symbols::EXPRESSION: return "EXPRESSION";
        case Symbols::BINARY_EXPR: return "BINARY_EXPR";
        case Symbols::BINARY_EXPR_P: return "BINARY_EXPR_P";
        case Symbols::UNARY_EXPR: return "UNARY_EXPR";
        case Symbols::TERM: return "TERM";
        case Symbols::TERM_P: return "TERM_P";
        case Symbols::LITERAL_EXPR: return "LITERAL_EXPR";
        case Symbols::IDENTIFIER: return "IDENTIFIER";
        case Symbols::INCREMENT_EXPR: return "INCREMENT_EXPR";
        case Symbols::ASSIGNMENT_STATEMENT: return "ASSIGNMENT_STATEMENT";
        case Symbols::IF_STATEMENT: return "IF_STATEMENT";
        case Symbols::WHILE_STATEMENT: return "WHILE_STATEMENT";
        case Symbols::FOR_STATEMENT: return "FOR_STATEMENT";
        case Symbols::PROCEDURE_STATEMENT: return "PROCEDURE_STATEMENT";
        case Symbols::RETURN_STATEMENT: return "RETURN_STATEMENT";
        case Symbols::BREAK_STATEMENT: return "BREAK_STATEMENT";
        case Symbols::ASSIGNMENT_TAIL: return "ASSIGNMENT_TAIL";
        case Symbols::EXPRESSION_TAIL: return "EXPRESSION_TAIL";
        case Symbols::BINARY_OP: return "BINARY_OP";
        case Symbols::UNARY_OP: return "UNARY_OP";
        case Symbols::FACTOR: return "FACTOR";
        case Symbols::STATEMENT_TAIL: return "STATEMENT_TAIL";
        case Symbols::INTEGER_LITERAL: return "INTEGER_LITERAL";
        case Symbols::STRING_LITERAL: return "STRING_LITERAL";
        case Symbols::IF_STATEMENT_PRIME: return "IF_STATEMENT_PRIME";
        case Symbols::PARAMETER_LIST: return "PARAMETER_LIST";
        case Symbols::TYPE: return "TYPE";
        case Symbols::DECLARATION_STATEMENT: return "DECLARATION_STATEMENT";
        default: return "UNKNOWN_SYMBOL";
    }
}



std::string tokenToString(int token) {
    using lex = lexer::claudio;
    switch (token) {
        case lex::INT64: return "INT64";
        case lex::BYTE: return "BYTE";
        case lex::FLOAT: return "FLOAT";
        case lex::VOID: return "VOID";
        case lex::BOOL: return "BOOL";
        case lex::STRING: return "STRING";
        case lex::IF: return "IF";
        case lex::ELSE: return "ELSE";
        case lex::WHILE: return "WHILE";
        case lex::FOR: return "FOR";
        case lex::BREAK: return "BREAK";
        case lex::FUNCTION: return "FUNCTION";
        case lex::ROUTINE: return "ROUTINE";
        case lex::RETURN: return "RETURN";
        case lex::LPAREN: return "LPAREN";
        case lex::RPAREN: return "RPAREN";
        case lex::LBRACE: return "LBRACE";
        case lex::RBRACE: return "RBRACE";
        case lex::LBRACKET: return "LBRACKET";
        case lex::RBRACKET: return "RBRACKET";
        case lex::MINUS: return "MINUS";
        case lex::PLUS: return "PLUS";
        case lex::MUL: return "MUL";
        case lex::DIV: return "DIV";
        case lex::INCREMENT: return "INCREMENT";
        case lex::DECREMENT: return "DECREMENT";
        case lex::GE: return "GE";
        case lex::LE: return "LE";
        case lex::EQ: return "EQ";
        case lex::ASSIGN: return "ASSIGN";
        case lex::GR_THAN: return "GR_THAN";
        case lex::LS_THAN: return "LS_THAN";
        case lex::NOT: return "NOT";
        case lex::NEQ: return "NEQ";
        case lex::SEMICOLON: return "SEMICOLON";
        case lex::COMMA: return "COMMA";
        case lex::ID: return "ID";
        case lex::INT_LITERAL: return "INT_LITERAL";
        case lex::STRING_LITERAL: return "STRING_LITERAL";
        case lex::WS: return "WS";
        case lex::COMMENT: return "COMMENT";
        case lex::EOF: return "<EOF>";
        default: return "UNKNOWN_TOKEN";
    }
}

