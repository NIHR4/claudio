#include "state_machine.hpp"
#include <stdexcept>

namespace lexer{ 
    
    void StateMachine::reset() {
        _currentState = _initalState;
        if (_initalState == nullptr) throw std::runtime_error{"invalid state: no initial state"};
    }
    
    void StateMachine::addState(State& state){
        const std::string name = state.getStateName();
        auto [it, result] = _transitionMap.emplace(name, std::move(state));
        auto [name, ref] = *it;
        if(ref.isFinalState()) _currentState = &ref;
    }
    
    void StateMachine::evaluateWord(const char character) {
        if (_currentState == nullptr) throw std::runtime_error{"invalid state:  currentState is null"};
        const auto next = _currentState->nextStateForWord(character);
        _currentState = &_transitionMap.at(next);
    }
    
    State* StateMachine::currentState() {
        if (_currentState == nullptr) throw std::runtime_error{"invalid state:  currentState is null"};
        return _currentState;
    }
}