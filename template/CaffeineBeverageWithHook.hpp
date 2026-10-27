#pragma once

#include <iostream>

class CaffeineBeverageWithHook {
public:
    virtual ~CaffeineBeverageWithHook() = default;

    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

protected:
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    void boilWater() { std::cout << "お湯を沸かす\n"; }
    void pourInCup() { std::cout << "カップに注ぐ\n"; }

    virtual bool customerWantsCondiments() { return true; }
};
