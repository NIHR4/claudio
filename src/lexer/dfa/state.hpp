#pragma once
#include <vector>
#include <string>

#include <unordered_map>
#include <utility>


class State {
public:
    //input char, next state
    using Transitions = std::unordered_map<char, std::string>; 
    
    //ctors
    State(const std::string& stateName, const Transitions& transitions);
    State() = default;

    //trivial getter
    std::string getStateName() const;
    bool isInitialState() const;
    bool isFinalState() const;

    //trivial setters
    void setName(const std::string& name);
    void addTransition(const char in, const std::string& state);
    void setFinalState(bool value);
    void setInitialState(bool value);    
    
    //evaluate
    std::string nextStateForWord(const char word) const;


private:
    std::string _stateName;
    Transitions _transitions;
    bool _final;
    bool _initial;
};