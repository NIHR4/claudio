#include "productions.hpp"
#include <stdexcept>
#include "base.hpp"

std::string Programa::getName() const
{
    return "Programa";
}

std::vector<AnySymbol> Programa::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::BREAK:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::FOR:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::FUNCTION:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::IF:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::RETURN:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::WHILE:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::INT_LITERAL:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::STRING_LITERAL:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::LPAREN:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::INT64:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::BYTE:
        return {
            tag::nterm(Symbols::STATEMENT_LIST)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Statementlist::getName() const
{
    return "Statementlist";
}

std::vector<AnySymbol> Statementlist::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::BREAK:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::FOR:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::FUNCTION:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::IF:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::RETURN:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::WHILE:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::INT_LITERAL:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::STRING_LITERAL:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    case lex::LPAREN:
        return {
            tag::nterm(Symbols::STATEMENT),
            tag::nterm(Symbols::STATEMENT_LIST)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Statement::getName() const
{
    return "Statement";
}

std::vector<AnySymbol> Statement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::term(lex::ID),
            tag::nterm(Symbols::STATEMENT_TAIL)};
    case lex::BREAK:
        return {
            tag::term(lex::BREAK)};
    case lex::FOR:
        return {
            tag::term(lex::FOR)};
    case lex::FUNCTION:
        return {
            tag::nterm(Symbols::PROCEDURE_STATEMENT)};
    case lex::IF:
        return {
            tag::term(lex::IF)};
    case lex::RETURN:
        return {
            tag::term(lex::RETURN)};
    case lex::WHILE:
        return {
            tag::term(lex::WHILE)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string StatementTail::getName() const
{
    return "StatementTail";
}

std::vector<AnySymbol> StatementTail::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::PLUS:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::MINUS:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::MUL:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::DIV:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::GR_THAN:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::LS_THAN:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::EQ:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::NEQ:
        return {
            tag::nterm(Symbols::EXPRESSION)};
    case lex::ASSIGN:
        return {
            tag::term(lex::ASSIGN),
            tag::nterm(Symbols::EXPRESSION)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Expression::getName() const
{
    return "Expression";
}

std::vector<AnySymbol> Expression::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::nterm(Symbols::BINARY_EXPR)};
    case lex::MINUS:
        return {
            tag::nterm(Symbols::UNARY_EXPR)};
    case lex::INT_LITERAL:
        return {
            tag::nterm(Symbols::LITERAL_EXPR)};
    case lex::STRING_LITERAL:
        return {
            tag::nterm(Symbols::LITERAL_EXPR)};
    case lex::LPAREN:
        return {
            tag::term(lex::LPAREN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::RPAREN)};
    case lex::INCREMENT:
        return {
            tag::nterm(Symbols::UNARY_EXPR)};
    case lex::DECREMENT:
        return {
            tag::nterm(Symbols::UNARY_EXPR)};
    case lex::NOT:
        return {
            tag::nterm(Symbols::UNARY_EXPR)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string ExpressionTail::getName() const
{
    return "ExpressionTail";
}

std::vector<AnySymbol> ExpressionTail::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::PLUS:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::MINUS:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::MUL:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::DIV:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::GR_THAN:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::LS_THAN:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::EQ:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    case lex::NEQ:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::EXPRESSION)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string BinaryExpression::getName() const
{
    return "BinaryExpression";
}

std::vector<AnySymbol> BinaryExpression::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    case lex::STRING_LITERAL:
        return {
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string BinaryExpressionPrime::getName() const
{
    return "BinaryExpressionPrime";
}

std::vector<AnySymbol> BinaryExpressionPrime::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::PLUS:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    case lex::MINUS:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    case lex::MUL:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    case lex::DIV:
        return {
            tag::nterm(Symbols::BINARY_OP),
            tag::nterm(Symbols::TERM),
            tag::nterm(Symbols::BINARY_EXPR_P)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string UnaryExpression::getName() const
{
    return "UnaryExpression";
}

std::vector<AnySymbol> UnaryExpression::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::MINUS:
        return {
            tag::nterm(Symbols::UNARY_OP),
            tag::nterm(Symbols::EXPRESSION)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string LiteralExpression::getName() const
{
    return "LiteralExpression";
}

std::vector<AnySymbol> LiteralExpression::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::INT_LITERAL:
        return {
            tag::term(lex::INT_LITERAL),
            tag::nterm(Symbols::LITERAL_EXPR)};
    case lex::STRING_LITERAL:
        return {
            tag::term(lex::STRING_LITERAL)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Term::getName() const
{
    return "Term";
}

std::vector<AnySymbol> Term::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::nterm(Symbols::FACTOR),
            tag::nterm(Symbols::TERM_P)};
    case lex::STRING_LITERAL:
        return {
            tag::nterm(Symbols::FACTOR),
            tag::nterm(Symbols::TERM_P)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string TermPrime::getName() const
{
    return "TermPrime";
}

std::vector<AnySymbol> TermPrime::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::MUL:
        return {
            tag::term(lex::MUL),
            tag::nterm(Symbols::FACTOR),
            tag::nterm(Symbols::TERM_P)};
    case lex::DIV:
        return {
            tag::term(lex::DIV),
            tag::nterm(Symbols::FACTOR),
            tag::nterm(Symbols::TERM_P)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Factor::getName() const
{
    return "Factor";
}

std::vector<AnySymbol> Factor::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::term(lex::ID)};
    case lex::STRING_LITERAL:
        return {
            tag::term(lex::LS_THAN),
            tag::term(lex::GR_THAN)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string IfStatement::getName() const
{
    return "IfStatement";
}

std::vector<AnySymbol> IfStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::IF:
        return {
            tag::term(lex::IF),
            tag::term(lex::LPAREN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::RPAREN),
            tag::nterm(Symbols::STATEMENT),
            tag::term(lex::IF)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string IfStatementPrime::getName() const
{
    return "IfStatementPrime";
}

std::vector<AnySymbol> IfStatementPrime::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ELSE:
        return {
            tag::term(lex::ELSE),
            tag::nterm(Symbols::STATEMENT)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string WhileStatement::getName() const
{
    return "WhileStatement";
}

std::vector<AnySymbol> WhileStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::WHILE:
        return {
            tag::term(lex::WHILE),
            tag::term(lex::LPAREN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::RPAREN),
            tag::nterm(Symbols::STATEMENT),
            tag::term(lex::WHILE)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string ForStatement::getName() const
{
    return "ForStatement";
}

std::vector<AnySymbol> ForStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::FOR:
        return {
            tag::term(lex::FOR),
            tag::term(lex::LPAREN),
            tag::nterm(Symbols::ASSIGNMENT_STATEMENT),
            tag::term(lex::SEMICOLON),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::SEMICOLON),
            tag::nterm(Symbols::INCREMENT_EXPR),
            tag::term(lex::RPAREN),
            tag::term(lex::LBRACE),
            tag::nterm(Symbols::STATEMENT),
            tag::term(lex::RBRACE)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string BreakStatement::getName() const
{
    return "BreakStatement";
}

std::vector<AnySymbol> BreakStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::BREAK:
        return {
            tag::term(lex::BREAK),
            tag::term(lex::SEMICOLON)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string ReturnStatement::getName() const
{
    return "ReturnStatement";
}

std::vector<AnySymbol> ReturnStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::RETURN:
        return {
            tag::term(lex::RETURN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::SEMICOLON)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string ProcedureStatement::getName() const
{
    return "ProcedureStatement";
}

std::vector<AnySymbol> ProcedureStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::FUNCTION:
        return {
            tag::term(lex::FUNCTION),
            tag::term(lex::ID),
            tag::term(lex::LPAREN),
            tag::nterm(Symbols::PARAMETER_LIST),
            tag::term(lex::RPAREN),
            tag::term(lex::LBRACE),
            tag::nterm(Symbols::STATEMENT),
            tag::term(lex::MUL),
            tag::term(lex::RBRACE)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string AssignmentStatement::getName() const
{
    return "AssignmentStatement";
}

std::vector<AnySymbol> AssignmentStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::term(lex::ID),
            tag::term(lex::ASSIGN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::SEMICOLON)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string DeclarationStatement::getName() const
{
    return "DeclarationStatement";
}

std::vector<AnySymbol> DeclarationStatement::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::INT64:
        return {
            tag::nterm(Symbols::TYPE),
            tag::term(lex::ID),
            tag::term(lex::ASSIGN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::SEMICOLON)};
    case lex::BYTE:
        return {
            tag::nterm(Symbols::TYPE),
            tag::term(lex::ID),
            tag::term(lex::ASSIGN),
            tag::nterm(Symbols::EXPRESSION),
            tag::term(lex::SEMICOLON)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string BinaryOperator::getName() const
{
    return "BinaryOperator";
}

std::vector<AnySymbol> BinaryOperator::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::PLUS:
        return {
            tag::term(lex::PLUS)};
    case lex::MINUS:
        return {
            tag::term(lex::MINUS)};
    case lex::MUL:
        return {
            tag::term(lex::MUL)};
    case lex::DIV:
        return {
            tag::term(lex::DIV)};
    case lex::GR_THAN:
        return {
            tag::term(lex::GR_THAN)};
    case lex::LS_THAN:
        return {
            tag::term(lex::LS_THAN)};
    case lex::EQ:
        return {
            tag::term(lex::EQ)};
    case lex::NEQ:
        return {
            tag::term(lex::NEQ)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string UnaryOperator::getName() const
{
    return "UnaryOperator";
}

std::vector<AnySymbol> UnaryOperator::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::MINUS:
        return {
            tag::term(lex::MINUS)};
    case lex::INCREMENT:
        return {
            tag::term(lex::PLUS),
            tag::term(lex::PLUS)};
    case lex::DECREMENT:
        return {
            tag::term(lex::MINUS),
            tag::term(lex::MINUS)};
    case lex::NOT:
        return {
            tag::term(lex::NOT)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string IncrementExpression::getName() const
{
    return "IncrementExpression";
}

std::vector<AnySymbol> IncrementExpression::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::ID:
        return {
            tag::term(lex::ID),
            tag::term(lex::PLUS),
            tag::term(lex::PLUS)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string Type::getName() const
{
    return "Type";
}

std::vector<AnySymbol> Type::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::INT64:
        return {
            tag::term(lex::INT64)};
    case lex::BYTE:
        return {
            tag::term(lex::BYTE)};
    }
    throw std::runtime_error{"no symbols matched"};
}

std::string ParameterList::getName() const
{
    return "ParameterList";
}

std::vector<AnySymbol> ParameterList::create(size_t token)
{
    using lex = lexer::claudio;
    switch (token)
    {
    case lex::RPAREN:
        return {

        };
    }
    throw std::runtime_error{"no symbols matched"};
}
