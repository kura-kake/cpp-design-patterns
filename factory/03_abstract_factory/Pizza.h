#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Ingredients.h"
#include "PizzaIngredientFactory.h"

class Pizza {
public:
    virtual ~Pizza() = default;

    // 食材の調達は、ピザの種類ごとに違うので純粋仮想関数にする
    virtual void prepare() = 0;

    virtual void bake() { std::cout << "Bake for 25 minutes at 350\n"; }
    virtual void cut()  { std::cout << "Cutting the pizza into diagonal slices\n"; }
    virtual void box()  { std::cout << "Place pizza in official PizzaStore box\n"; }

    void setName(std::string name) { name_ = std::move(name); }
    const std::string& name() const { return name_; }

    // 使われた食材を表示する
    void describe() const {
        std::cout << "[" << name_ << "]\n";
        if (dough_)     std::cout << "  Dough:     " << dough_->toString() << "\n";
        if (sauce_)     std::cout << "  Sauce:     " << sauce_->toString() << "\n";
        if (cheese_)    std::cout << "  Cheese:    " << cheese_->toString() << "\n";
        if (!veggies_.empty()) {
            std::cout << "  Veggies:   ";
            for (std::size_t i = 0; i < veggies_.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << veggies_[i]->toString();
            }
            std::cout << "\n";
        }
        if (pepperoni_) std::cout << "  Pepperoni: " << pepperoni_->toString() << "\n";
        if (clam_)      std::cout << "  Clam:      " << clam_->toString() << "\n";
    }

protected:
    explicit Pizza(const PizzaIngredientFactory& factory) : factory_(factory) {}

    // 抽象ファクトリへの参照。ファクトリ自体の所有者は PizzaStore
    const PizzaIngredientFactory& factory_;

    std::string name_;
    std::unique_ptr<Dough>     dough_;
    std::unique_ptr<Sauce>     sauce_;
    std::unique_ptr<Cheese>    cheese_;
    std::vector<std::unique_ptr<Veggies>> veggies_;
    std::unique_ptr<Pepperoni> pepperoni_;
    std::unique_ptr<Clams>     clam_;
};