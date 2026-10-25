#include "NYPizzaStore.h"
#include "NYStylePizzas.h"   // NY のピザを知っているのはここだけ

std::unique_ptr<Pizza> NYPizzaStore::createPizza(const std::string& type) const {
    if (type == "cheese")    return std::make_unique<NYStyleCheesePizza>();
    if (type == "pepperoni") return std::make_unique<NYStylePepperoniPizza>();
    if (type == "clam")      return std::make_unique<NYStyleClamPizza>();
    if (type == "veggie")    return std::make_unique<NYStyleVeggiePizza>();
    return nullptr;
}