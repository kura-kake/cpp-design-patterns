#pragma once
#include "PizzaIngredientFactory.h"

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    std::unique_ptr<Dough>     createDough()     const override;
    std::unique_ptr<Sauce>     createSauce()     const override;
    std::unique_ptr<Cheese>    createCheese()    const override;
    std::vector<std::unique_ptr<Veggies>> createVeggies() const override;
    std::unique_ptr<Pepperoni> createPepperoni() const override;
    std::unique_ptr<Clams>     createClam()      const override;
};