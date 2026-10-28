#include <iostream>

#include "GumballMachine.hpp"

int main() {
    GumballMachine gumballMachine(5);

    std::cout << "--- 通常の購入 ---" << std::endl;
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();

    std::cout << "\n--- 25セントを入れて返却 ---" << std::endl;
    gumballMachine.insertQuarter();
    gumballMachine.ejectQuarter();
    gumballMachine.turnCrank();  // 返却済みなので出ない

    std::cout << "\n--- 2回投入／お金なしでハンドル ---" << std::endl;
    gumballMachine.insertQuarter();
    gumballMachine.insertQuarter();  // HasQuarterState で拒否される
    gumballMachine.turnCrank();
    gumballMachine.turnCrank();  // 投入していない

    std::cout << "\n--- 売り切れまで購入 ---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        gumballMachine.insertQuarter();
        gumballMachine.turnCrank();
    }

    std::cout << "\n--- 売り切れ状態の動作 ---" << std::endl;
    gumballMachine.insertQuarter();
    gumballMachine.turnCrank();
    gumballMachine.ejectQuarter();

    return 0;
}
