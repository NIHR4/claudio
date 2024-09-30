#pragma once
#include <vector>
#include "token.hpp"
#include "../io/source_file.hpp"



std::vector<Token> extractTokens(SourceFile& file);