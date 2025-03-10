#include <iostream>
#include "WeatherFetcher.h"
#include "WeatherDisplay.h"

int main() {
    std::string city;
    std::cout << "Enter city name: ";
    std::getline(std::cin, city);

    std::string weatherData = getWeatherData(city);
    if (!weatherData.empty()) {
        displayWeather(city, weatherData);
    } else {
        std::cout << "Failed to fetch weather data.\n";
    }

    return 0;
}