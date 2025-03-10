#include "WeatherDisplay.h"
#include <iostream>
#include <json/json.h>

void displayWeather(const std::string& city, const std::string& jsonData) {
    Json::Value root;
    Json::Reader reader;
    if (reader.parse(jsonData, root)) {
        std::cout << "Weather information for " << city << ":\n";
        std::string weatherDesc = root["weather"][0]["description"].asString();
        std::string temp = root["main"]["temp"].asString();
        std::string humidity = root["main"]["humidity"].asString();
        std::string windSpeed = root["wind"]["speed"].asString();
        std::cout << "Description: " << weatherDesc << "\n";
        std::cout << "Temperature: " << temp << " K\n";
        std::cout << "Humidity: " << humidity << " %\n";
        std::cout << "Wind Speed: " << windSpeed << " m/s\n";
    } else {
        std::cout << "Failed to parse weather data.\n";
    }
}