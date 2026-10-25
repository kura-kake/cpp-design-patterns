#pragma once
#include "Pizza.h"

class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza() {
        name_ = "NY Style Cheese Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Marinara Sauce";
        toppings_ = {"Grated Reggiano Cheese"};
    }
};

class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza() {
        name_ = "NY Style Pepperoni Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Marinara Sauce";
        toppings_ = {"Grated Reggiano Cheese", "Sliced Pepperoni"};
    }
};

class NYStyleClamPizza : public Pizza {
public:
    NYStyleClamPizza() {
        name_ = "NY Style Clam Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Marinara Sauce";
        toppings_ = {"Grated Reggiano Cheese", "Fresh Clams from Long Island Sound"};
    }
};

class NYStyleVeggiePizza : public Pizza {
public:
    NYStyleVeggiePizza() {
        name_ = "NY Style Veggie Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Marinara Sauce";
        toppings_ = {"Grated Reggiano Cheese", "Garlic", "Onion", "Mushrooms"};
    }
};