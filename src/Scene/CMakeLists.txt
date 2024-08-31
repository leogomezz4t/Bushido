add_library(Scene STATIC scene.c)
target_link_libraries(Scene GameObject)
target_include_directories(Scene PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
