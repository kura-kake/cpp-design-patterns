#include "ChicagoPizzaStore.h"
#include "Pizzas.h"

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(const std::string& type) const {
    std::unique_ptr<Pizza> pizza;

    if (type == "cheese") {
        pizza = std::make_unique<CheesePizza>(ingredientFactory_);
        pizza->setName("Chicago Style Cheese Pizza");
    } else if (type == "pepperoni") {
        pizza = std::make_unique<PepperoniPizza>(ingredientFactory_);
        pizza->setName("Chicago Style Pepperoni Pizza");
    } else if (type == "clam") {
        pizza = std::make_unique<ClamPizza>(ingredientFactory_);
        pizza->setName("Chicago Style Clam Pizza");
    } else if (type == "veggie") {
        pizza = std::make_unique<VeggiePizza>(ingredientFactory_);
        pizza->setName("Chicago Style Veggie Pizza");
    }
    return pizza;
}