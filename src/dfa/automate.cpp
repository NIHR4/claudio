#include "automata.hpp"
#include <algorithm>
#include <stdexcept>

void DFA::evaluateString(const std::string& inString) {
    if ( _currentState == nullptr ) {
        for(auto& el : _statesMemo) {
            if(el.second.isInitialState()) {
                _currentState = &el.second;
                break;
            }
        }
        if(_currentState == nullptr) throw std::runtime_error("no initial state");
    }
   
    for(char ch : inString) {
        std::string next = _currentState->evaluate(ch);
        _currentState = &_statesMemo.at(next);
    }
}


void DFA::addState(const State& state) {
    _statesMemo[state.getStateName()] = state;
}