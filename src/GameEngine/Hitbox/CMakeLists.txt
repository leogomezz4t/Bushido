add_library(Hitbox STATIC hitbox.c)
target_link_libraries(Hitbox GameObject)
target_include_directories(Hitbox PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}")
