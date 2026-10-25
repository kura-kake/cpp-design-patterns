#include "ChicagoPizzaIngredientFactory.h"
#include "ChicagoIngredients.h"   // シカゴの食材を知っているのはここだけ

std::unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDough() const {
    return std::make_unique<ThickCrustDough>();
}

std::unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce() const {
    return std::make_unique<PlumTomatoSauce>();
}

std::unique_ptr<Cheese> ChicagoPizzaIngredientFactory::createCheese() const {
    return std::make_unique<MozzarellaCheese>();
}

std::vector<std::unique_ptr<Veggies>> ChicagoPizzaIngredientFactory::createVeggies() const {
    std::vector<std::unique_ptr<Veggies>> veggies;
    veggies.push_back(std::make_unique<BlackOlives>());
    veggies.push_back(std::make_unique<Spinach>());
    veggies.push_back(std::make_unique<Eggplant>());
    return veggies;
}

std::unique_ptr<Pepperoni> ChicagoPizzaIngredientFactory::createPepperoni() const {
    return std::make_unique<SlicedPepperoni>();   // NY と共通の食材
}

std::unique_ptr<Clams> ChicagoPizzaIngredientFactory::createClam() const {
    return std::make_unique<FrozenClams>();
}