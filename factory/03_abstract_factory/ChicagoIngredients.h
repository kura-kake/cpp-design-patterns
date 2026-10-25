#pragma once
#include "Ingredients.h"

class ThickCrustDough : public Dough {
public:
    std::string toString() const override { return "Extra Thick Crust Dough"; }
};

class PlumTomatoSauce : public Sauce {
public:
    std::string toString() const override { return "Plum Tomato Sauce"; }
};

class MozzarellaCheese : public Cheese {
public:
    std::string toString() const override { return "Shredded Mozzarella"; }
};

class BlackOlives : public Veggies {
public:
    std::string toString() const override { return "Black Olives"; }
};

class Spinach : public Veggies {
public:
    std::string toString() const override { return "Spinach"; }
};

class Eggplant : public Veggies {
public:
    std::string toString() const override { return "Eggplant"; }
};

class FrozenClams : public Clams {
public:
    std::string toString() const override { return "Frozen Clams from Chesapeake Bay"; }
};