#pragma once
#include "Pizza.h"

class CaliforniaStyleCheesePizza : public Pizza {
public:
    CaliforniaStyleCheesePizza() {
        name_ = "California Style Cheese Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Light Tomato Sauce";
        toppings_ = {"Goat Cheese", "Fresh Mozzarella", "Basil"};
    }
};

class CaliforniaStyleVeggiePizza : public Pizza {
public:
    CaliforniaStyleVeggiePizza() {
        name_ = "California Style Veggie Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "Olive Oil and Garlic";
        toppings_ = {"Fresh Mozzarella", "Arugula", "Avocado", "Sun-dried Tomatoes"};
    }
};

// この店だけのメニュー
class CaliforniaStyleBBQChickenPizza : public Pizza {
public:
    CaliforniaStyleBBQChickenPizza() {
        name_ = "California Style BBQ Chicken Pizza";
        dough_ = "Thin Crust Dough";
        sauce_ = "BBQ Sauce";
        toppings_ = {"Grilled Chicken", "Red Onion", "Smoked Gouda", "Cilantro"};
    }
};