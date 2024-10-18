add_library(TestScene STATIC testScene.c)
target_link_libraries(TestScene GameEngine BushidoObjects)
target_include_directories(TestScene PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
