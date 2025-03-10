cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 14)

# Find required libraries
find_package(CURL REQUIRED)
find_package(JsonCpp REQUIRED)

# Include directories
include_directories(include)

# Add executable
add_executable(WeatherApp src/main.cpp src/WeatherFetcher.cpp src/WeatherDisplay.cpp)

# Link libraries
target_link_libraries(WeatherApp ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES})