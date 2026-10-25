#pragma once
#include <memory>
#include <string>
#include "Pizza.h"

class PizzaStore {
public:
    virtual ~PizzaStore() = default;
    std::unique_ptr<Pizza> orderPizza(const std::string& type);

protected:
    virtual std::unique_ptr<Pizza> createPizza(const std::string& type) const = 0;
};