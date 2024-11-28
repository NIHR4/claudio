#pragma once 
#include <istream>
#include <string>
#include "nowhitespace.hpp"
#include <vector>




class SourceLine {
private:
    std::string m_original;
    std::string m_transformed;
    std::vector<int> m_indexMap;
    static std::vector<int> createNewIndexMap(const std::string& original, const std::string& transformed);

public:
    friend std::istream& operator>>(std::istream& lhs, SourceLine& rhs) {
        std::string line;
        std::getline(lhs, line);
        std::string transformed = io::nowhitespace(line);
        
        //Assign values
        rhs.m_original = line;
        rhs.m_transformed = transformed;
        rhs.m_indexMap = SourceLine::createNewIndexMap(line, transformed);
        return lhs;
    }

    const std::string& str() const {
        return m_transformed;
    }


    const std::string& originalStr() const {
        return m_original;
    }

    //returns a vector that maps the index of
    //a transformed string back into its original position
    const std::vector<int>& getOriginalIndexMapping() {
        return m_indexMap;
    }

};