#include "WeatherFetcher.h"
#include <iostream>

const std::string API_KEY = "9b3fd2ff1cbe7f6f3adc73241ac50558";

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

std::string getWeatherData(const std::string& city) {
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + API_KEY;
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == CURLE_OK) {
            return response;
        }
    }
    return "";
}