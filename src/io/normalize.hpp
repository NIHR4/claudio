#include <istream>
#include <string>
#include <sstream>
#include "../definitions/characters_maps.hpp"

// class LineEndingNormalizer{
// public:
/*friend std::istream& operator>> (std::istream& is, std::string& line){
    std::string temp;
    std::getline(is, temp);
    line.clear();
    for(std::size_t i=0; i < temp.size(); ++i){
        //Remove Carriage Return characters
        if(temp[i] == Character::RC){
            line += Character::LF;
            if(i + 1 < temp.size() && temp[i+1] == '\n'){
                i++;
            }
        }else{
            line += temp;
        }
    }
    return is;

    std::skipws
}*/
//};*

namespace io
{
    /*struct normalize {
       friend std::istream& operator>>(std::istream& is, std::string& target) {
           std::getline(is, target);
           // Normalize: trim whitespace from both ends
           auto start = target.find_first_not_of(" \t\n");
           auto end = target.find_last_not_of(" \t\n");
           if (start != std::string::npos && end != std::string::npos) {
               target = target.substr(start, end - start + 1);
           } else {
               target.clear();
           }
           return is;
       }*/
    
    inline std::string normalizeLineEndings(const std::string &inStr)
    {
        std::string outStr;
        std::istringstream ss(inStr);
        std::string line;
        while (std::getline(ss, line))
        {
            if(!line.empty() && line.back() == '\r') line.pop_back();
            outStr += line + '\n';
        }
        return outStr;
    }
}