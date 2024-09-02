add_library(GameState STATIC gameState.c)
target_link_libraries(GameState Scene)
target_link_libraries(GameState SpriteAnimation)
target_include_directories(GameState PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")

