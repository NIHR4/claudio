#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string_view>

#include "lexer/claudio.h"
#include "antlr4-runtime.h"
#include <fstream>
#include <sstream>
#include <clipp.h>
#include <format>
#include "parser/parser.hpp"

/*int main(int argc, char** argv){
 
    std::istringstream ifs("if (10 == val) { exit(); }");
    antlr4::ANTLRInputStream input(ifs);
    lexer::claudio lexer(&input);

    antlr4::CommonTokenStream tokenStream(&lexer);
    tokenStream.fill();
    auto tokens = tokenStream.getTokens();
    for(auto tok : tokens) {
        std::cout << "token: " << tok->getText() << "\n";
    }
    std::cout << "done!";
}*/


void compile(const std::string inPath, const std::string& outPath){
    
    //Lexical analysis
    std::ifstream ifs(inPath);
    antlr4::ANTLRInputStream input(ifs);
    lexer::claudio lex(&input);
    antlr4::CommonTokenStream tokenStream(&lex);
    tokenStream.fill();


    //Syntactic analysis
    parser::parse(tokenStream);


}




int main(int argc, char** argv){
    std::string inPath;
    std::string outPath;
    
    auto cli = (
        clipp::value("Input file", inPath),
        clipp::required("-o", "--output") & clipp::value("output file",  outPath)
    );
    
    //parse command line commands
    if(!clipp::parse(argc, argv, cli)) {
        std::cout << "Incorrect usage:\n" << clipp::make_man_page(cli, "claudio");
        return 0;
    }

    //inPath = R"(C:\Users\andre\Coding\School\Compiladores\claudio\out\build\default\Debug\source.cla)";
    
    try{
        //begin compilation
        using clock = std::chrono::high_resolution_clock;
        auto compStart = clock::now();
        compile(inPath, outPath);
        auto compEnd = clock::now();
        std::cout << "Build succeeded in " << std::chrono::duration_cast<std::chrono::milliseconds>(compEnd-compStart).count() << "ms\n";
        return 0;
    }catch(const std::runtime_error& ex){
        std::cerr << ex.what();
    }

    std::cerr << "\n\nProgram terminated abruptly";
    return -1;
    
}