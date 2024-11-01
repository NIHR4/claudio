
// Generated from claudio.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace lexer {


class  claudio : public antlr4::Lexer {
public:
  enum {
    INT64 = 1, BYTE = 2, FLOAT = 3, VOID = 4, BOOL = 5, STRING = 6, IF = 7, 
    ELSE = 8, WHILE = 9, FOR = 10, BREAK = 11, FUNCTION = 12, ROUTINE = 13, 
    RETURN = 14, LPAREN = 15, RPAREN = 16, LBRACE = 17, RBRACE = 18, LBRACKET = 19, 
    RBRACKET = 20, MINUS = 21, PLUS = 22, MUL = 23, DIV = 24, INCREMENT = 25, 
    DECREMENT = 26, GE = 27, LE = 28, EQ = 29, ASSIGN = 30, NOT = 31, NEQ = 32, 
    SEMICOLON = 33, COMMA = 34, ID = 35, INT_LITERAL = 36, STRING_LITERAL = 37, 
    WS = 38, COMMENT = 39
  };

  explicit claudio(antlr4::CharStream *input);

  ~claudio() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace lexer
