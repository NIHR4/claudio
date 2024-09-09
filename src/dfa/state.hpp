#pragma once
#include <vector>
#include <string>

#include <unordered_map>
#include <utility>


class State {
public:
    /*<input, state>*/
    using Transitions = std::unordered_map<char, std::string>; 
    
    //ctors
    State(const std::string& stateName, const Transitions& transitions)  : 
        _stateName(stateName), _transitions(transitions) {}
    
    State() = default;

    //trivial getter/setters
    std::string getStateName() const { return _stateName; }

    void setName(const std::string& name) {
        _stateName = name;
    }
    
    void addTransition(const char in, const std::string& state) {
        _transitions[in] = state;
    }

    void setFinalState(bool value) {
        _final = value;
    }

    void setInitialState(bool value) {
        _initial = value;
    }
    
    bool isInitialState() const {
        return _initial;
    }

    bool isFinalState() const {
        return _final;
    }

    //returns the next state
    std::string evaluate(const char in){
        return _transitions.at(in);
    }


private:
    std::string _stateName;
    Transitions _transitions;
    bool _final;
    bool _initial;
};