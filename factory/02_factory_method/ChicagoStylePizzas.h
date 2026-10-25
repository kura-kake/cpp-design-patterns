#pragma once
#include "Pizza.h"
//シカゴ風チーズピザだけ cut() をオーバーライドして、四角く切ります。

class ChicagoStyleCheesePizza : public Pizza {
public:
    ChicagoStyleCheesePizza() {
        name_ = "Chicago Style Deep Dish Cheese Pizza";
        dough_ = "Extra Thick Crust Dough";
        sauce_ = "Plum Tomato Sauce";
        toppings_ = {"Shredded Mozzarella Cheese"};
    }
    void cut() override {
        std::cout << "Cutting the pizza into square slices\n";
    }
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
    ChicagoStylePepperoniPizza() {
        name_ = "Chicago Style Pepperoni Pizza";
        dough_ = "Extra Thick Crust Dough";
        sauce_ = "Plum Tomato Sauce";
        toppings_ = {"Shredded Mozzarella Cheese", "Black Olives", "Spinach",
                     "Eggplant", "Sliced Pepperoni"};
    }
};

class ChicagoStyleClamPizza : public Pizza {
public:
    ChicagoStyleClamPizza() {
        name_ = "Chicago Style Clam Pizza";
        dough_ = "Extra Thick Crust Dough";
        sauce_ = "Plum Tomato Sauce";
        toppings_ = {"Shredded Mozzarella Cheese", "Frozen Clams from Chesapeake Bay"};
    }
};

class ChicagoStyleVeggiePizza : public Pizza {
public:
    ChicagoStyleVeggiePizza() {
        name_ = "Chicago Style Veggie Pizza";
        dough_ = "Extra Thick Crust Dough";
        sauce_ = "Plum Tomato Sauce";
        toppings_ = {"Shredded Mozzarella Cheese", "Black Olives", "Spinach", "Eggplant"};
    }
};