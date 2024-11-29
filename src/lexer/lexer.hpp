#pragma once
#include "claudio.h"

namespace lexer
{
    class ClaudioLexer : public claudio
    {
    public:
        using claudio::claudio;
        void notifyListeners(const antlr4::LexerNoViableAltException &e) override;
    };
}