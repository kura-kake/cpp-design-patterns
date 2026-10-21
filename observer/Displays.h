#pragma once
#include <limits>
#include "Interfaces.h"

// 「Observer であり DisplayElement でもある」ので、2つの窓口を継承する
class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
    explicit CurrentConditionsDisplay(Subject& subject);
    ~CurrentConditionsDisplay() override;

    void update(float temperature, float humidity, float pressure) override;
    void display() const override;

private:
    Subject& subject_;   // 具体的な WeatherData ではなく、窓口の Subject を持つ
    float temperature_ = 0;
    float humidity_ = 0;
};

class StatisticsDisplay : public Observer, public DisplayElement {
public:
    explicit StatisticsDisplay(Subject& subject);
    ~StatisticsDisplay() override;

    void update(float temperature, float humidity, float pressure) override;
    void display() const override;

private:
    Subject& subject_;
    float sum_ = 0;
    int count_ = 0;
    float min_ = std::numeric_limits<float>::max();
    float max_ = std::numeric_limits<float>::lowest();
};

class ForecastDisplay : public Observer, public DisplayElement {
public:
    explicit ForecastDisplay(Subject& subject);
    ~ForecastDisplay() override;

    void update(float temperature, float humidity, float pressure) override;
    void display() const override;

private:
    Subject& subject_;
    float currentPressure_ = 1013.25f;   // 標準的な気圧を初期値にする
    float lastPressure_ = 1013.25f;
};