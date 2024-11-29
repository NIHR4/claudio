#pragma once
#include <string>
#include <vector>
#include <antlr4-runtime.h>
#include "claudio.h"
#include <iomanip>

struct IdentifierData {
    std::string value;
    size_t line;
    size_t position;
};


inline std::vector<IdentifierData> generateSymbolTable(const std::vector<antlr4::Token*>& tokens) {
    std::vector<IdentifierData> res;
    for(auto& t : tokens) {
        if(t->getType() == lexer::claudio::ID) {
            res.push_back(IdentifierData{t->getText(), t->getLine(), t->getCharPositionInLine()});
        }
    }
    return res;
}

inline void printSymbolTable(const std::vector<IdentifierData>& in) {
    // Table header
    std::cout << std::left << std::setw(20) << "Identifier" 
              << std::setw(10) << "Line" 
              << std::setw(10) << "Position" << std::endl;

    // Divider
    std::cout << std::string(40, '-') << std::endl;

    // Table rows
    for (const auto& data : in) {
        std::cout << std::left << std::setw(20) << data.value
                  << std::setw(10) << data.line
                  << std::setw(10) << data.position << std::endl;
    }
}
