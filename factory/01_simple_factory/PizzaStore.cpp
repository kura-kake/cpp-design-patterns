#include "PizzaStore.h"
#include <iostream>
// ConcretePizzas.h を include していない = 具象クラスを知らない

std::unique_ptr<Pizza> PizzaStore::orderPizza(const std::string& type) {
    auto pizza = factory_.createPizza(type);
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