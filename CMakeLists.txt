cmake_minimum_required (VERSION 3.8)

project (ASD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

include_directories(include)

set(
    LIB_SOURCES
    src/Sorting.cpp
)

add_library(
    ASD
    ${LIB_SOURCES}
)

add_executable(DEMO main.cpp)
target_link_libraries(DEMO PRIVATE ASD)
