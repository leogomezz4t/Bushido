cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# DEBUG
set(CMAKE_BUILD_TYPE Debug)

find_package(raylib 3.0 REQUIRED)

# Add all the subdirs 
add_subdirectory(Types)
add_subdirectory(GameObject)
add_subdirectory(Scene)
add_subdirectory(SpriteAnimation)
add_subdirectory(Entity)
add_subdirectory(GameState)

add_library(GameEngine STATIC empty.c)

target_link_libraries(GameEngine raylib m Types GameObject Scene SpriteAnimation Entity GameState)

#target_include_directories(GameEngine PUBLIC
#                        "${PROJECT_SOURCE_DIR}"
#                        )
