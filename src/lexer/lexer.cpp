#include "lexer.hpp"

using namespace lexer;
void ClaudioLexer::notifyListeners(const antlr4::LexerNoViableAltException &e)
{
    std::string text = getText(); // Get the offending text
        size_t line = getLine();      // Get the line number
        size_t charPositionInLine = getCharPositionInLine(); // Get position in line

        std::cerr << "Lexer error at line " << line << ":" << charPositionInLine
                  << " - Unrecognized token: " << text << std::endl;
    throw std::runtime_error{"unrecognized token"};
}
