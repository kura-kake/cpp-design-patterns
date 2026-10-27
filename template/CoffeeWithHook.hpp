#pragma once

#include <cctype>
#include <iostream>
#include <string>

#include "CaffeineBeverageWithHook.hpp"

class CoffeeWithHook : public CaffeineBeverageWithHook {
protected:
    void brew() override { std::cout << "フィルタを使ってコーヒーをドリップする\n"; }

    void addCondiments() override { std::cout << "砂糖とミルクを加える\n"; }

    bool customerWantsCondiments() override {
        std::string answer = getUserInput();
        return !answer.empty() && std::tolower(static_cast<unsigned char>(answer[0])) == 'y';
    }

private:
    std::string getUserInput() {
        std::string answer;
        std::cout << "コーヒーに砂糖とミルクを入れますか? (y/n) ";
        if (!std::getline(std::cin, answer)) {
            return "no";
        }
        return answer;
    }
};
