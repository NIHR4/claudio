#pragma once
#include "state.hpp"
#include <unordered_map>

class DFA {
private:
    std::unordered_map<std::string, State> _statesMemo;
    State* _currentState = nullptr;
public:
    void evaluateString(const std::string& inString);
    void addState(const State& state);
    std::string stopState() const {
        return _currentState->getStateName();
    }
};