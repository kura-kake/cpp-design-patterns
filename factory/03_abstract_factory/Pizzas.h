#pragma once
#include "Pizza.h"
// 具象の食材ファクトリも、具象の食材も include していない

class CheesePizza : public Pizza {
public:
    explicit CheesePizza(const PizzaIngredientFactory& f) : Pizza(f) {}
    void prepare() override {
        std::cout << "Preparing " << name_ << "\n";
        dough_  = factory_.createDough();
        sauce_  = factory_.createSauce();
        cheese_ = factory_.createCheese();
    }
};

class PepperoniPizza : public Pizza {
public:
    explicit PepperoniPizza(const PizzaIngredientFactory& f) : Pizza(f) {}
    void prepare() override {
        std::cout << "Preparing " << name_ << "\n";
        dough_     = factory_.createDough();
        sauce_     = factory_.createSauce();
        cheese_    = factory_.createCheese();
        veggies_   = factory_.createVeggies();
        pepperoni_ = factory_.createPepperoni();
    }
};

class ClamPizza : public Pizza {
public:
    explicit ClamPizza(const PizzaIngredientFactory& f) : Pizza(f) {}
    void prepare() override {
        std::cout << "Preparing " << name_ << "\n";
        dough_  = factory_.createDough();
        sauce_  = factory_.createSauce();
        cheese_ = factory_.createCheese();
        clam_   = factory_.createClam();
    }
};

class VeggiePizza : public Pizza {
public:
    explicit VeggiePizza(const PizzaIngredientFactory& f) : Pizza(f) {}
    void prepare() override {
        std::cout << "Preparing " << name_ << "\n";
        dough_   = factory_.createDough();
        sauce_   = factory_.createSauce();
        cheese_  = factory_.createCheese();
        veggies_ = factory_.createVeggies();
    }
};