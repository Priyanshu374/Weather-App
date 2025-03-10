#ifndef WEATHERFETCHER_H
#define WEATHERFETCHER_H

#include <string>
#include <curl/curl.h>

std::string getWeatherData(const std::string& city);
size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* buffer);

#endif // WEATHERFETCHER_H