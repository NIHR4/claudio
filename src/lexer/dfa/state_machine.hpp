#pragma once
#include <unordered_map>
#include <string>
#include "state.hpp"

namespace lexer
{
    class StateMachine{
    private:
        std::unordered_map<std::string, State> _transitionMap;
        State* _currentState;
        State* _initalState;
    public:
        void reset();
        void addState(State& state);
        void evaluateWord(const char character);
        State* currentState();
    };    
} // namespace lexer

