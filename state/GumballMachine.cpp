#include "GumballMachine.hpp"

#include <iostream>

#include "States.hpp"

GumballMachine::GumballMachine(int numberGumballs)
    : soldOutState_(std::make_unique<SoldOutState>(*this)),
      noQuarterState_(std::make_unique<NoQuarterState>(*this)),
      hasQuarterState_(std::make_unique<HasQuarterState>(*this)),
      soldState_(std::make_unique<SoldState>(*this)),
      state_(soldOutState_.get()),
      count_(numberGumballs) {
    // ガムボールが1個以上あれば NoQuarterState、なければ SoldOutState で始める
    if (count_ > 0) {
        state_ = noQuarterState_.get();
    }
}

void GumballMachine::insertQuarter() { state_->insertQuarter(); }

void GumballMachine::ejectQuarter() { state_->ejectQuarter(); }

void GumballMachine::turnCrank() {
    state_->turnCrank();
    state_->dispense();
}

void GumballMachine::releaseBall() {
    std::cout << "ガムボールがスロットから出てきます" << std::endl;
    if (count_ != 0) {
        count_ = count_ - 1;
    }
}
