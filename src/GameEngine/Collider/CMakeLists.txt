add_library(Collider STATIC collider.c)
target_link_libraries(Collider Hitbox GameObject)
target_include_directories(Collider PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
