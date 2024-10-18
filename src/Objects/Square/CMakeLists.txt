add_library(Square STATIC square.c)
target_link_libraries(Square GameEngine GameObject Rayleigh)
target_include_directories(Square PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
