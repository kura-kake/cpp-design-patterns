#pragma once
#include <memory>
#include <string>
#include "Pizza.h"
#include "SimplePizzaFactory.h"

class PizzaStore {
public:
    explicit PizzaStore(const SimplePizzaFactory& factory) : factory_(factory) {}

    std::unique_ptr<Pizza> orderPizza(const std::string& type);

private:
    const SimplePizzaFactory& factory_;
};