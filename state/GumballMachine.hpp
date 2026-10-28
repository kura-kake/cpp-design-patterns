#pragma once

#include <memory>

#include "State.hpp"

// Context クラス。
// 状態を整数ではなく State オブジェクトで保持し、アクションは現在の状態に委譲する。
class GumballMachine {
public:
    explicit GumballMachine(int numberGumballs);

    // アクション（現在の状態に委譲するだけ）
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();  // dispense() は内部アクションなので、ここから呼ぶ

    // 状態オブジェクトから呼ばれる
    void setState(State* state) { state_ = state; }
    void releaseBall();

    // 各 State のゲッター
    State* getSoldOutState() const { return soldOutState_.get(); }
    State* getNoQuarterState() const { return noQuarterState_.get(); }
    State* getHasQuarterState() const { return hasQuarterState_.get(); }
    State* getSoldState() const { return soldState_.get(); }

    int getCount() const { return count_; }

private:
    // すべての State（マシンが所有する）
    std::unique_ptr<State> soldOutState_;
    std::unique_ptr<State> noQuarterState_;
    std::unique_ptr<State> hasQuarterState_;
    std::unique_ptr<State> soldState_;

    State* state_;  // 現在の状態（上のいずれかを指す。所有はしない）
    int count_ = 0;
};
