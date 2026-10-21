#include "Displays.h"
#include "WeatherData.h"

int main() {
    WeatherData weather;                       // 先に作る（後に消える）
    CurrentConditionsDisplay current(weather);
    StatisticsDisplay statistics(weather);
    ForecastDisplay forecast(weather);

    weather.setMeasurements(27.0f, 65.0f, 1013.1f);   // 気圧が標準より低い
    weather.setMeasurements(29.0f, 70.0f, 1015.0f);   // 気圧が上がる
    weather.setMeasurements(26.0f, 90.0f, 1015.0f);   // 気圧が変わらない
}