#pragma once

#include "State.hpp"

// GumballMachine と各 State は相互に参照し合うので前方宣言にとどめ、
// メソッドの実装は States.cpp に置く。
class GumballMachine;

// 25セントが入っていない状態
class NoQuarterState : public State {
public:
    explicit NoQuarterState(GumballMachine& machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& machine_;
};

// 25セントが入っている状態
class HasQuarterState : public State {
public:
    explicit HasQuarterState(GumballMachine& machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& machine_;
};

// ガムボールを販売している状態（ハンドルが回された後）
class SoldState : public State {
public:
    explicit SoldState(GumballMachine& machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& machine_;
};

// ガムボールが売り切れた状態
class SoldOutState : public State {
public:
    explicit SoldOutState(GumballMachine& machine) : machine_(machine) {}

    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& machine_;
};
