#pragma once

#include <cctype>
#include <iostream>
#include <string>

#include "CaffeineBeverageWithHook.hpp"

class TeaWithHook : public CaffeineBeverageWithHook {
protected:
    void brew() override { std::cout << "紅茶を浸す\n"; }

    void addCondiments() override { std::cout << "レモンを追加する\n"; }

    bool customerWantsCondiments() override {
        std::string answer = getUserInput();
        return !answer.empty() && std::tolower(static_cast<unsigned char>(answer[0])) == 'y';
    }

private:
    std::string getUserInput() {
        std::string answer;
        std::cout << "紅茶にレモンを入れますか? (y/n) ";
        if (!std::getline(std::cin, answer)) {
            return "no";
        }
        return answer;
    }
};
