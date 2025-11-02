cmake_minimum_required(VERSION 3.16)
project(Multithreading VERSION 1.0 LANGUAGES CXX)

find_path(JSON_INCLUDE_DIR nlohmann/json.hpp
  PATHS /opt/homebrew/include /usr/local/include
)

target_include_directories(main PRIVATE ${JSON_INCLUDE_DIR})

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add your source files
add_executable(main src/main.cpp)
