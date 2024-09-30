#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string_view>

#include "exceptions/file_not_open.hpp"
#include <chrono>

#include "io/normalize.hpp"
#include "io/nowhitespace.hpp"
#include "io/line.hpp"
int main(int argc, char** argv){

    std::istringstream iss("if    (hello    ==    \"hello world\");");
    SourceLine line;
    iss >> line;
    std::cout << line.str() << "\n";
    std::cout << line.originalStr() << "\n";
    std::cout << line.originalStr()[line.getIndexMap()[24]] << "\n";
    //std::cout << io::nowhitespace("if    (hello    ==    \"hello world\");");
    
}
