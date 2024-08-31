add_library(GameEngine STATIC gameEngine.c)
target_link_libraries(GameEngine Scene)
target_link_libraries(GameEngine SpriteAnimation)
target_include_directories(GameEngine PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")

