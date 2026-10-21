#include "WeatherData.h"
#include <algorithm>

void WeatherData::registerObserver(Observer& o) {
    // 同じ相手を二重に登録しない
    if (std::find(observers_.begin(), observers_.end(), &o) == observers_.end()) {
        observers_.push_back(&o);
    }
}

void WeatherData::removeObserver(Observer& o) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), &o),
                     observers_.end());
}

void WeatherData::notifyObservers() {
    // 一覧のコピーを回す。update の最中に自分で登録解除しても、回している最中の一覧が壊れない
    const auto snapshot = observers_;
    for (Observer* o : snapshot) {
        o->update(temperature_, humidity_, pressure_);
    }
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    pressure_ = pressure;
    measurementsChanged();
}

void WeatherData::measurementsChanged() {
    notifyObservers();
}