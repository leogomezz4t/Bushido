add_library(Entity STATIC entity.c)
target_include_directories(Entity PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
