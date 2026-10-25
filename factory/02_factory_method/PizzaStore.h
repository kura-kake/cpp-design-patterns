#pragma once
#include <memory>
#include <string>
#include "Pizza.h"

//抽象 Creator
class PizzaStore {
public:
    virtual ~PizzaStore() = default;

    // 注文の手順は共通。サブクラスは変更できない
    std::unique_ptr<Pizza> orderPizza(const std::string& type);

protected:
    // ファクトリメソッド: 何を作るかはサブクラスが決める
    virtual std::unique_ptr<Pizza> createPizza(const std::string& type) const = 0;
};