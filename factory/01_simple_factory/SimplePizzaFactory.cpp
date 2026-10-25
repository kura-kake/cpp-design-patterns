#include "SimplePizzaFactory.h"
#include "ConcretePizzas.h"   // 具象クラスを include するのはここだけ

std::unique_ptr<Pizza> SimplePizzaFactory::createPizza(const std::string& type) const {
    if (type == "cheese")    return std::make_unique<CheesePizza>();
    if (type == "pepperoni") return std::make_unique<PepperoniPizza>();
    if (type == "clam")      return std::make_unique<ClamPizza>();
    if (type == "veggie")    return std::make_unique<VeggiePizza>();
    if (type == "hawaiian")    return std::make_unique<HawaiianPizza>();
    return nullptr;
}