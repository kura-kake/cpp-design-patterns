#pragma once
#include "PizzaStore.h"
#include "NYPizzaIngredientFactory.h"

class NYPizzaStore : public PizzaStore {
protected:
    std::unique_ptr<Pizza> createPizza(const std::string& type) const override;

private:
    NYPizzaIngredientFactory ingredientFactory_;   // この店の食材ファクトリ
};