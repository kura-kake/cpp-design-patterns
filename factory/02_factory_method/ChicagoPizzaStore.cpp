#include "ChicagoPizzaStore.h"
#include "ChicagoStylePizzas.h"   // シカゴのピザを知っているのはここだけ

std::unique_ptr<Pizza> ChicagoPizzaStore::createPizza(const std::string& type) const {
    if (type == "cheese")    return std::make_unique<ChicagoStyleCheesePizza>();
    if (type == "pepperoni") return std::make_unique<ChicagoStylePepperoniPizza>();
    if (type == "clam")      return std::make_unique<ChicagoStyleClamPizza>();
    if (type == "veggie")    return std::make_unique<ChicagoStyleVeggiePizza>();
    return nullptr;
}