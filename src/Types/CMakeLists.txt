add_library(Types STATIC vector2.c)
target_include_directories(Types PUBLIC
                        "${CMAKE_CURRENT_SOURCE_DIR}")
