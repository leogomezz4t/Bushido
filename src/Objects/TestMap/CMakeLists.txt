add_library(TestMap STATIC testMap.c)
target_link_libraries(TestMap GameEngine GameObject)
target_include_directories(TestMap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
