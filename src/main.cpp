#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string_view>

#include "exceptions/file_not_open.hpp"
#include <chrono>
#include "lexer/claudio.h"
#include "antlr4-runtime.h"
#include <fstream>
#include <sstream>
#include <clipp.h>
#include <format>
#include "parser/parser.hpp"
#include "parser/symbols.hpp"
#include "lexer/symbol_table.hpp"
#include "lexer/lexer.hpp"
#include "semantic/decorator.hpp"




void compile(std::istream& inputStream){
    
    //Lexical analysis
    antlr4::ANTLRInputStream input(inputStream);
    lexer::ClaudioLexer lex(&input);
    antlr4::CommonTokenStream tokenStream(&lex);
    tokenStream.fill();


    //Lexer output logging
    std::cout << "Lexer output:\n";
    auto symTable = generateSymbolTable(tokenStream.getTokens());
    printSymbolTable(symTable);
    std::cout << "\n\n";
    for(auto& token : tokenStream.getTokens()){
        std::cout << std::format("Character: {}. Type={}\n", token->getText(), tokenToString(token->getType()));
    }
    
    //Syntactic analysis
    auto parseTree = parser::parse(tokenStream);

    //Semantic
    AST ast;
    //AST tree generation crashes the program
    //convertToAST(parseTree, parseTree.begin(), ast);

}


#include <Windows.h>

int main(int argc, char** argv){
    std::string inPath;
    std::string outPath;
    SetConsoleOutputCP(65001);
    
    auto cli = (
        clipp::value("Input file", inPath),
        clipp::required("-o", "--output") & clipp::value("output file",  outPath)
    );
    
    //parse command line commands
    
 
    
    if(!clipp::parse(argc, argv, cli)) {
        std::cout << "Incorrect usage:\n" << clipp::make_man_page(cli, "claudio");
        return 0;
    }
    std::ifstream inputFileStream(inPath);
    
    try{
        //check the file is open for reading
        if(inputFileStream.fail()){
            throw file_not_open{std::format("File '{}' is not open for reading", inPath)};
        }
        
        
        //begin compilation
        using clock = std::chrono::high_resolution_clock;
        auto compStart = clock::now();
        compile(inputFileStream);
        auto compEnd = clock::now();
        std::cout << "Build succeeded in " << std::chrono::duration_cast<std::chrono::milliseconds>(compEnd-compStart).count() << "ms\n";
        return 0;
    }catch(const file_not_open& ex){
        std::cerr << "Error: " << ex.what() << "\n";
    }catch(const std::runtime_error& ex){
        std::cerr << "\n\nEXCEPTION: "<< ex.what();
    }

    std::cerr << "\n\nProgram terminated abruptly";
    return -1;
    
}