#pragma once
#include "PizzaStore.h"

class ChicagoPizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string& type) const override;
};