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

#include "lexer/claudio.h"
#include "antlr4-runtime.h"
#include <fstream>
#include <sstream>



int main(int argc, char** argv){
 
    std::istringstream ifs("if (10 == val) { exit(); }");
    antlr4::ANTLRInputStream input(ifs);
    claudio lexer(&input);

    antlr4::CommonTokenStream tokenStream(&lexer);
    tokenStream.fill();
    auto tokens = tokenStream.getTokens();
    for(auto tok : tokens) {
        std::cout << "token: " << tok->getText() << "\n";
    }
    std::cout << "done!";
}
