#include "PizzaStore.h"
#include <iostream>
// 具象ピザも、具象ストアも知らない

std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string& type) {
    auto pizza = createPizza(type);   // どのピザが来るかは、ここでは分からない
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