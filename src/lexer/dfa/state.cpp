#include "state.hpp"

// Constructor with state name and transitions
State::State(const std::string& stateName, const Transitions& transitions)
    : _stateName(stateName), _transitions(transitions), _final(false), _initial(false) {}

// Getter for state name
std::string State::getStateName() const {
    return _stateName;
}

// Getter for initial state flag
bool State::isInitialState() const {
    return _initial;
}

// Getter for final state flag
bool State::isFinalState() const {
    return _final;
}

// Setter for state name
void State::setName(const std::string& name) {
    _stateName = name;
}

// Method to add a transition
void State::addTransition(const char in, const std::string& state) {
    _transitions[in] = state;
}

// Setter for final state flag
void State::setFinalState(bool value) {
    _final = value;
}

// Setter for initial state flag
void State::setInitialState(bool value) {
    _initial = value;
}

// Method to evaluate the next state for a given word
std::string State::nextStateForWord(const char word) const{
    return _transitions.at(word);
}