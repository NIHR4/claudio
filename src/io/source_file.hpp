#pragma once
#include <string>
#include <istream>
#include <iterator>
#include <vector>
#include "nowhitespace.hpp"

class SourceFile{
private:
    std::string m_rawFileContents;
    std::string m_processedContent;
   
    
public:
    friend void operator>>(std::istream& lhs, SourceFile& rhs){
        
        // Read file contents into memory
        rhs.m_rawFileContents = std::string(
            (std::istreambuf_iterator<char>(lhs)),
            (std::istreambuf_iterator<char>())
        );

        //Format
        auto& file = rhs.m_rawFileContents;
        rhs.m_processedContent = io::nowhitespace(file);
    }

    
};