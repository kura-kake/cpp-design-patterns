#pragma once
#include <string>

// 食材のインターフェース(資料の <<interface>> Dough, Sauce, ... に相当)
class Dough {
public:
    virtual ~Dough() = default;
    virtual std::string toString() const = 0;
};

class Sauce {
public:
    virtual ~Sauce() = default;
    virtual std::string toString() const = 0;
};

class Cheese {
public:
    virtual ~Cheese() = default;
    virtual std::string toString() const = 0;
};

class Veggies {
public:
    virtual ~Veggies() = default;
    virtual std::string toString() const = 0;
};

class Pepperoni {
public:
    virtual ~Pepperoni() = default;
    virtual std::string toString() const = 0;
};

class Clams {
public:
    virtual ~Clams() = default;
    virtual std::string toString() const = 0;
};

// 地域を問わず共通の食材(複数のファクトリが同じ具象クラスを使ってもよい)
class SlicedPepperoni : public Pepperoni {
public:
    std::string toString() const override { return "Sliced Pepperoni"; }
};