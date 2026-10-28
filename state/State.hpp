#pragma once

// すべての状態クラスが実装するインターフェース。
// メソッドはガムボールマシンで起こり得るアクションに直接対応している。
class State {
public:
    virtual ~State() = default;

    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};
