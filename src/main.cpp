#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <string_view>
#include "utils/string_utils.hpp"
#include "exceptions/file_not_open.hpp"
#include <clipp.h>
#include <chrono>

void scanFile(std::istream& ifs, std::string& out) {
    std::string result;
    std::string line;
    while (std::getline(ifs, line, '\n'))
    {
        std::string processed = line;
        utils::trim(processed); //remove whitespace;
        result += processed;
    }
    out = result;
}

void compile(const std::string inPath, const std::string& outPath){
        auto ifs = std::ifstream(inPath);
        if(!ifs.is_open()) {
            //Throw if file isn't open
            throw file_not_open(std::format("{} file not found", inPath));
        }
       
        std::string str;
        scanFile(ifs, str);

        std::ofstream ofs(outPath, std::ios::trunc);
        if(!ofs.is_open()) throw file_not_open(std::format("couldn't write to {}", outPath));
        ofs << str;
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
    
    try{
        using clock = std::chrono::high_resolution_clock;
        auto compStart = clock::now();
        //begin compilation
        compile(inPath, outPath);
        auto compEnd = clock::now();
        std::cout << "Build succeeded in " << std::chrono::duration_cast<std::chrono::milliseconds>(compEnd-compStart).count() << "ms\n";

        return 0;
    }catch(const file_not_open& ex){
        std::cerr << "Error: " << ex.what() << "\n";
    }

    std::cerr << "Program terminated abruptly";
    return -1;
}
