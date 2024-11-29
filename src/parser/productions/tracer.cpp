#include "tracer.hpp"

#include <iostream>
#include <string>
#include <format>
#include <variant>
#include "../symbols.hpp"
#include "../../utils/overload.hpp"

std::string Tracer::getName() const 
{
    return std::format("traced({})", _underlyingFactory->getName());
}

std::vector<AnySymbol> Tracer::create(size_t token)
{
   std::cout << std::format("production for {}({}) -> ", _underlyingFactory->getName(), tokenToString(token));
   
    auto prod = _underlyingFactory->create(token);
    if(prod.empty()) {
        std::cout << "ε\n";
        return { };
    }
    for (AnySymbol& symbol : prod)
    {
        std::visit(overloaded{
            [](tag::nterm& arg) { std::cout << symbolToString(arg.val) << " "; },
            [](tag::term& arg) { std::cout << tokenToString(arg.val) << " "; },
            [](auto const& arg ) {}
        }, symbol);
    }
    std::cout << std::endl;
    return prod;
}
