#pragma once
#include <vector>
#include "Interfaces.h"

class WeatherData : public Subject {
public:
    void registerObserver(Observer& o) override;
    void removeObserver(Observer& o) override;
    void notifyObservers() override;

    // センサーが新しい値を届けた、という想定
    void setMeasurements(float temperature, float humidity, float pressure);

    float getTemperature() const { return temperature_; }
    float getHumidity() const { return humidity_; }
    float getPressure() const { return pressure_; }

private:
    void measurementsChanged();

    std::vector<Observer*> observers_;   // 覚えているだけで、所有はしない
    float temperature_ = 0;
    float humidity_ = 0;
    float pressure_ = 0;
};