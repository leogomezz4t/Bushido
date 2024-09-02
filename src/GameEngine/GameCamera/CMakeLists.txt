add_library(GameCamera camera.c)
target_link_libraries(GameCamera PRIVATE Types)
target_include_directories(GameCamera PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
