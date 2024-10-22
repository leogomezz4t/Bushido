add_library(ParallaxBackground STATIC parallaxBackground.c)
target_link_libraries(ParallaxBackground GameEngine GameObject)
target_include_directories(ParallaxBackground PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
