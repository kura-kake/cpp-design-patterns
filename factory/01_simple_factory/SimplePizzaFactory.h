#pragma once
#include <memory>
#include <string>
#include "Pizza.h"

class SimplePizzaFactory {
public:
    std::unique_ptr<Pizza> createPizza(const std::string& type) const;
};