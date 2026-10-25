#pragma once
#include <memory>
#include <vector>
#include "Ingredients.h"

class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() = default;

    virtual std::unique_ptr<Dough>     createDough()     const = 0;
    virtual std::unique_ptr<Sauce>     createSauce()     const = 0;
    virtual std::unique_ptr<Cheese>    createCheese()    const = 0;
    virtual std::vector<std::unique_ptr<Veggies>> createVeggies() const = 0;
    virtual std::unique_ptr<Pepperoni> createPepperoni() const = 0;
    virtual std::unique_ptr<Clams>     createClam()      const = 0;
};