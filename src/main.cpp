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
#include <clipp.h>
#include <format>
#include "parser/parser.hpp"



void compile(std::istream& inputStream){
    
    //Lexical analysis
    antlr4::ANTLRInputStream input(inputStream);
    lexer::claudio lex(&input);
    antlr4::CommonTokenStream tokenStream(&lex);
    tokenStream.fill();


    //Syntactic analysis
    parser::parse(tokenStream);


}

/*
enum Nonterminals {
    A=1,
    B=2,
    S=50
};

enum Terminals {
    a=3,
    b=4,
    c=5,
    d=6,
    eof=99
};


#include "parser/symbols.hpp"



using term = tag::impl::tagTerminalSymbol<int>;
using nterm = tag::impl::tagNonTerminalSymbol<int>;
using ParseElement = std::variant<term,  nterm>; 


void handleNonTerminals(std::stack<ParseElement>& symStack, ParseElement inSymbol, int inStream) {
    
    int symbol = std::get<nterm>(inSymbol).val;
    //S productions
    if(symbol == Nonterminals::S) {
        std::cout << "Start symbol parse tree\n";
        if(inStream == Terminals::a) {
            std::cout << "S(a) -> aABb\n";
            symStack.push(term(Terminals::b));
            symStack.push(nterm(Nonterminals::B));
            symStack.push(nterm(Nonterminals::A));
            symStack.push(term(Terminals::a));
        }else{
            throw std::runtime_error{"unexpected input"};
        }
    }
    

    //A productions
    if(symbol == Nonterminals::A) {
        std::cout << "parsing A symbol";
        if(inStream == Terminals::b) {
            std::cout << "A(b) -> Є\n";
        }
        else if(inStream == Terminals::c) {
            std::cout << "A(c) -> c\n";
        }
        else if(inStream == Terminals::d) {
            std::cout << "A(d) -> Є\n";
        }
        else {
            throw std::runtime_error{"unexpected"};
        }
    }

    //B productions
    if(symbol == Nonterminals::B) {
        std::cout << "parsing B symbol";
        if(inStream ==  Terminals::b){
            std::cout << "B(b) -> Є\n";
        }
        else if(inStream ==  Terminals::d){
            std::cout << "B(d) -> d\n";
            symStack.push(term(Terminals::d));
        }
    }


}


class ISymbol{};
class TerminalSymbol{};
class NonterminalSymbol{};


class IProductions{
public:
    virtual const char* getSymbolName();
    virtual void log();
    virtual int productionFor(int terminal)=0;
};


struct IProductionFactory{
    virtual void create(int token);
};


class productionsA : public IProductionFactory {
public:
    void create(int token) override {
        switch(token) {
            
        }
    }
};












void parserTest() {
    std::vector<int> inputBuffer = {Terminals::a, Terminals::d, Terminals::b, Terminals::eof};
    std::stack<ParseElement> symStack;
    size_t idx=0;
    symStack.push(term(Terminals::eof));
    symStack.push(nterm(Nonterminals::S));

    
    while (!symStack.empty())
    {
        auto currentSymbol = symStack.top();
        std::visit([](const auto& el) { std::cout << "Current symbol: " << el.val << "\n";}, currentSymbol);
        
        symStack.pop();
        
        //Current token in the input stream
        int token = inputBuffer[idx];

        //Parse Non-Terminal Symbols
        if(std::holds_alternative<nterm>(currentSymbol)) {
            
            handleNonTerminals(symStack, currentSymbol, token);

        }
        //Parse Terminal Symbols
        else if(std::holds_alternative<term>(currentSymbol)){
            auto terminalSymbol = std::get<term>(currentSymbol).val;
            if(terminalSymbol == token) {
                //Skip terminal
                idx++;
                
            }
        }
    }



}

*/

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
    
    #ifndef CLAUDIO_NOT_INTERACTIVE
    
    if(!clipp::parse(argc, argv, cli)) {
        std::cout << "Incorrect usage:\n" << clipp::make_man_page(cli, "claudio");
        return 0;
    }

    #else
        //inPath = "\\source.clp";
        //std::ifstream iss(inPath);
        std::istringstream iss("x = 10;");
    #endif
    
    
    
    //inPath = R"(C:\Users\andre\Coding\School\Compiladores\claudio\out\build\default\Debug\source.cla)";
    
    try{
        //begin compilation
        using clock = std::chrono::high_resolution_clock;
        auto compStart = clock::now();
        compile(iss);
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