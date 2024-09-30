#include "nowhitespace.hpp"
#include <vector>
#include <algorithm>
#include <ranges>
#include <sstream>


std::string io::nowhitespace(const std::string &inStr)
{
    std::string outStr;
    std::istringstream ss(inStr);
    std::string line;
    const auto isQuote = [](char c) {return (c == '\'' || c == '"');};
    const auto isSpace = [](char c) {return std::isspace(c) != 0;};
    bool skip=false;
    while (std::getline(ss, line))
    {
        //empty line
        if(line.empty()) {
            continue;
        }

        //line is only whitespace
        if(std::all_of(line.cbegin(), line.cend(), isSpace)){
            continue;
        }

        bool lineStart = true;
        for(std::size_t i=0; i < line.length(); i++) {
            //quote character check
            if(isQuote(line[i])) {
                skip = !skip;
                continue;
            }

            
            if(i + 1 != line.length() && (line[i] == ' ' && isSpace(line[i+1]))){
                auto start = line.begin() + i;
                auto it = std::find_if_not(start, line.end(), isSpace);
                if(!lineStart) it -= 1;
                const std::size_t removed = std::distance(start, it);
                line.erase(start, it);
                i = 0;
            }
            lineStart = false;
        
        }

        outStr += line;

    }
    return outStr;
}
