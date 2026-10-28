#include "States.hpp"

#include <iostream>

#include "GumballMachine.hpp"

// ---------------------------------------------------------------
// NoQuarterState
// ---------------------------------------------------------------
void NoQuarterState::insertQuarter() {
    std::cout << "25セントを投入しました" << std::endl;
    machine_.setState(machine_.getHasQuarterState());
}

void NoQuarterState::ejectQuarter() {
    std::cout << "25セントを投入していません" << std::endl;
}

void NoQuarterState::turnCrank() {
    std::cout << "ハンドルを回しましたが、25セントを投入していません" << std::endl;
}

void NoQuarterState::dispense() {
    std::cout << "まずお金を払う必要があります" << std::endl;
}

// ---------------------------------------------------------------
// HasQuarterState
// ---------------------------------------------------------------
void HasQuarterState::insertQuarter() {
    std::cout << "もう一度25セントを投入することはできません" << std::endl;
}

void HasQuarterState::ejectQuarter() {
    std::cout << "25セントを返却しました" << std::endl;
    machine_.setState(machine_.getNoQuarterState());
}

void HasQuarterState::turnCrank() {
    std::cout << "ハンドルを回しました" << std::endl;
    machine_.setState(machine_.getSoldState());
}

void HasQuarterState::dispense() {
    std::cout << "ガムボールが出せません" << std::endl;
}

// ---------------------------------------------------------------
// SoldState
// ---------------------------------------------------------------
void SoldState::insertQuarter() {
    std::cout << "お待ちください。ガムボールを出す準備をしています" << std::endl;
}

void SoldState::ejectQuarter() {
    std::cout << "申し訳ありません。すでにハンドルを回しています" << std::endl;
}

void SoldState::turnCrank() {
    std::cout << "2回回してもガムボールをもう1つ手に入れることはできません！" << std::endl;
}

void SoldState::dispense() {
    // 客は支払い済みなので、まずマシンにガムボールを出すよう依頼する
    machine_.releaseBall();
    // そしてガムボール数を問い合わせ、NoQuarterState か SoldOutState に遷移する
    if (machine_.getCount() > 0) {
        machine_.setState(machine_.getNoQuarterState());
    } else {
        std::cout << "おっと、ガムボールがなくなりました！" << std::endl;
        machine_.setState(machine_.getSoldOutState());
    }
}

// ---------------------------------------------------------------
// SoldOutState
// ---------------------------------------------------------------
void SoldOutState::insertQuarter() {
    std::cout << "ガムボールがありません。25セントを投入できません" << std::endl;
}

void SoldOutState::ejectQuarter() {
    std::cout << "25セントを投入していないので、返却できません" << std::endl;
}

void SoldOutState::turnCrank() {
    std::cout << "ハンドルを回しましたが、ガムボールがありません" << std::endl;
}

void SoldOutState::dispense() {
    std::cout << "ガムボールが出せません" << std::endl;
}
