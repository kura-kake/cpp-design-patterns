#pragma once
#include <iostream>
#include <string>
#include <utility>

// 製品の基底クラス。サブクラスがオーバーライドできる共通の実装を持つ
class Pizza {
public:
    explicit Pizza(std::string name) : name_(std::move(name)) {}
    virtual ~Pizza() = default;   // 基底クラスのデストラクタは virtual

    virtual void prepare() { std::cout << "Preparing " << name_ << "\n"; }
    virtual void bake()    { std::cout << "Baking "    << name_ << "\n"; }
    virtual void cut()     { std::cout << "Cutting "   << name_ << "\n"; }
    virtual void box()     { std::cout << "Boxing "    << name_ << "\n"; }

    const std::string& name() const { return name_; }

protected:
    std::string name_;
};