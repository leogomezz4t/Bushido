add_library(GameEngine STATIC gameEngine.c)
target_include_directories(GameEngine PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")

