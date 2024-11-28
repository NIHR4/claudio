#pragma once
#include "../symbols.hpp"
#include <vector>


class IBaseProductionFactory {
public:
    virtual std::string getName() const = 0;
    virtual std::vector<AnySymbol> create(size_t token)=0;
};