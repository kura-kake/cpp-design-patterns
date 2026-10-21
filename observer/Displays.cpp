#include "Displays.h"
#include <iomanip>
#include <iostream>

// ---- CurrentConditionsDisplay ----
CurrentConditionsDisplay::CurrentConditionsDisplay(Subject& subject) : subject_(subject) {
    subject_.registerObserver(*this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay() {
    subject_.removeObserver(*this);
}

void CurrentConditionsDisplay::update(float temperature, float humidity, float /*pressure*/) {
    temperature_ = temperature;
    humidity_ = humidity;
    display();
}

void CurrentConditionsDisplay::display() const {
    std::cout << std::fixed << std::setprecision(1)
              << "Current conditions: " << temperature_ << "C, "
              << humidity_ << "% humidity\n";
}

// ---- StatisticsDisplay ----
StatisticsDisplay::StatisticsDisplay(Subject& subject) : subject_(subject) {
    subject_.registerObserver(*this);
}

StatisticsDisplay::~StatisticsDisplay() {
    subject_.removeObserver(*this);
}

void StatisticsDisplay::update(float temperature, float /*humidity*/, float /*pressure*/) {
    sum_ += temperature;
    ++count_;
    if (temperature < min_) min_ = temperature;
    if (temperature > max_) max_ = temperature;
    display();
}

void StatisticsDisplay::display() const {
    if (count_ == 0) {
        std::cout << "Avg/Max/Min temperature = no data\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(1)
              << "Avg/Max/Min temperature = " << sum_ / count_ << "/"
              << max_ << "/" << min_ << "\n";
}

// ---- ForecastDisplay ----
ForecastDisplay::ForecastDisplay(Subject& subject) : subject_(subject) {
    subject_.registerObserver(*this);
}

ForecastDisplay::~ForecastDisplay() {
    subject_.removeObserver(*this);
}

void ForecastDisplay::update(float /*temperature*/, float /*humidity*/, float pressure) {
    lastPressure_ = currentPressure_;
    currentPressure_ = pressure;
    display();
}

void ForecastDisplay::display() const {
    std::cout << "Forecast: ";
    if (currentPressure_ > lastPressure_) {
        std::cout << "improving weather on the way\n";
    } else if (currentPressure_ == lastPressure_) {
        std::cout << "more of the same\n";
    } else {
        std::cout << "cooler, rainy weather likely\n";
    }
}