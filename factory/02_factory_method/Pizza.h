#pragma once
#include <iostream>
#include <string>
#include <vector>
//01_simple_factoryの時より拡張。生地・ソース・トッピングを持たせて、店ごとの違いを出力で見えるようにする。

// 製品の抽象基底クラス
class Pizza {
public:
    virtual ~Pizza() = default;

    virtual void prepare() {
        std::cout << "Preparing " << name_ << "\n";
        std::cout << "  Tossing dough: " << dough_ << "\n";
        std::cout << "  Adding sauce: "  << sauce_ << "\n";
        for (const auto& t : toppings_) {
            std::cout << "  Adding topping: " << t << "\n";
        }
    }
    virtual void bake() { std::cout << "Bake for 25 minutes at 350\n"; }
    virtual void cut()  { std::cout << "Cutting the pizza into diagonal slices\n"; }
    virtual void box()  { std::cout << "Place pizza in official PizzaStore box\n"; }

    const std::string& name() const { return name_; }

protected:
    Pizza() = default;   // 直接 Pizza は作れない。サブクラスが中身を決める

    std::string name_;
    std::string dough_;
    std::string sauce_;
    std::vector<std::string> toppings_;
};