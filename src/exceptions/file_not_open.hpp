#pragma once
#include <stdexcept>

class file_not_open : public std::runtime_error{
public:
    explicit file_not_open(const std::string& msg) : std::runtime_error(msg) {}
    explicit file_not_open(const char* msg) : std::runtime_error(msg) {}
};