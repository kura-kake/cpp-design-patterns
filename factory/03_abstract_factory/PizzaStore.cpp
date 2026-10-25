#include "PizzaStore.h"
#include <iostream>

std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string& type) {
    auto pizza = createPizza(type);
    if (!pizza) {
        std::cerr << "Unknown pizza type: " << type << "\n";
        return nullptr;
    }
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
    return pizza;
}