#pragma once

#include <iostream>
#include <string>
#include <utility>

class Light {
public:
    explicit Light(std::string location) : location_(std::move(location)) {}

    void on() { std::cout << location_ << " 照明が点いています\n"; }
    void off() { std::cout << location_ << " 照明が消えています\n"; }

private:
    std::string location_;
};

class CeilingFan {
public:
    explicit CeilingFan(std::string location) : location_(std::move(location)) {}

    void high() { std::cout << location_ << " シーリングファンの強さは「強」です\n"; }
    void medium() { std::cout << location_ << " シーリングファンの強さは「中」です\n"; }
    void low() { std::cout << location_ << " シーリングファンの強さは「弱」です\n"; }
    void off() { std::cout << location_ << " シーリングファンは止まっています\n"; }

private:
    std::string location_;
};

class GarageDoor {
public:
    explicit GarageDoor(std::string location) : location_(std::move(location)) {}

    void up() { std::cout << location_ << " ドアが開いています\n"; }
    void down() { std::cout << location_ << " ドアが閉まっています\n"; }

private:
    std::string location_;
};

class Stereo {
public:
    explicit Stereo(std::string location) : location_(std::move(location)) {}

    void on() { std::cout << location_ << " オーディオの電源が入っています\n"; }
    void off() { std::cout << location_ << " オーディオの電源が切れています\n"; }
    void setCD() { std::cout << location_ << " オーディオがCD入力に設定されています\n"; }
    void setDvd() { std::cout << location_ << " オーディオがDVD入力に設定されています\n"; }
    void setRadio() { std::cout << location_ << " オーディオがラジオに設定されています\n"; }
    void setVolume(int volume) {
        std::cout << location_ << " オーディオのボリュームが" << volume << "に設定されています\n";
    }

private:
    std::string location_;
};
