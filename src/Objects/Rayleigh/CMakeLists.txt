add_library(Rayleigh STATIC rayleigh.c)
target_link_libraries(Rayleigh GameEngine GameObject SpriteAnimation Square)
target_include_directories(Rayleigh PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
