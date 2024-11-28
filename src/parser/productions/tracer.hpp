#pragma once
#include "base.hpp"
#include <memory>


class Tracer : public IBaseProductionFactory {
public:
    virtual std::string getName() const override;
    virtual std::vector<AnySymbol> create(size_t token) override;
    Tracer(std::unique_ptr<IBaseProductionFactory>& ptr) : _underlyingFactory(std::move(ptr)) {}
    Tracer(std::unique_ptr<IBaseProductionFactory>&& ptr) : _underlyingFactory(std::move(ptr)) {}
private: 
    std::unique_ptr<IBaseProductionFactory> _underlyingFactory;
};