#pragma once
#include "StateMachine.hpp"

namespace lexer {
    class FsmFactory{
    public:
        static StateMachine create();
    };
}
