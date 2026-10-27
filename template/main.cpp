#include <iostream>

#include "CoffeeWithHook.hpp"
#include "TeaWithHook.hpp"

int main() {
    TeaWithHook teaHook;
    CoffeeWithHook coffeeHook;

    std::cout << "\n紅茶を淹れる\n";
    teaHook.prepareRecipe();

    std::cout << "\nコーヒーを淹れる\n";
    coffeeHook.prepareRecipe();

    return 0;
}
