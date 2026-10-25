#pragma once
#include "Ingredients.h"

class ThinCrustDough : public Dough {
public:
    std::string toString() const override { return "Thin Crust Dough"; }
};

class MarinaraSauce : public Sauce {
public:
    std::string toString() const override { return "Marinara Sauce"; }
};

class ReggianoCheese : public Cheese {
public:
    std::string toString() const override { return "Reggiano Cheese"; }
};

class Garlic : public Veggies {
public:
    std::string toString() const override { return "Garlic"; }
};

class Onion : public Veggies {
public:
    std::string toString() const override { return "Onion"; }
};

class Mushroom : public Veggies {
public:
    std::string toString() const override { return "Mushrooms"; }
};

class RedPepper : public Veggies {
public:
    std::string toString() const override { return "Red Pepper"; }
};

class FreshClams : public Clams {
public:
    std::string toString() const override { return "Fresh Clams from Long Island Sound"; }
};