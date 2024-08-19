cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Bushido VERSION 0.1)

# Add all the subdirs 
add_subdirectory(src/Types)
add_subdirectory(src/GameObject)

find_package(raylib 3.0 REQUIRED)

add_executable(Bushido src/app.c)

target_link_libraries(Bushido raylib m Vectors GameObject)

target_include_directories(Bushido PUBLIC
                        "${PROJECT_SOURCE_DIR}/include")
