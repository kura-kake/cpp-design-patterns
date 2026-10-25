#include <iostream>
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"

void order(PizzaStore& store, const std::string& type) {
    auto pizza = store.orderPizza(type);
    if (pizza) {
        pizza->describe();
    }
    std::cout << "----\n";
}

int main() {
    NYPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    order(nyStore, "cheese");
    order(chicagoStore, "cheese");
    order(nyStore, "clam");
    order(chicagoStore, "clam");
    order(chicagoStore, "veggie");
}