cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# DEBUG
set(CMAKE_BUILD_TYPE Debug)

project(Bushido VERSION 0.1)

find_package(raylib 3.0 REQUIRED)

# Add all the subdirs 
add_subdirectory(src/GameEngine)
add_subdirectory(src/Objects)
add_subdirectory(src/Scenes)

add_executable(Bushido src/app.c)

target_link_libraries(Bushido raylib m GameEngine BushidoObjects BushidoScenes)

target_include_directories(Bushido PRIVATE
                        "${PROJECT_SOURCE_DIR}/include"
                        )
