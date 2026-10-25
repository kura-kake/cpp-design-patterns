#pragma once
#include "Pizza.h"

class CheesePizza : public Pizza {
public:
    CheesePizza() : Pizza("Cheese Pizza") {}
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza() : Pizza("Pepperoni Pizza") {}
};

class ClamPizza : public Pizza {
public:
    ClamPizza() : Pizza("Clam Pizza") {}
};

class VeggiePizza : public Pizza {
public:
    VeggiePizza() : Pizza("Veggie Pizza") {}
};

class HawaiianPizza : public Pizza {
public:
    HawaiianPizza() : Pizza("Hawaiian Pizza") {}
};