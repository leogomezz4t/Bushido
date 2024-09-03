add_subdirectory(Test)

add_library(BushidoScenes STATIC empty.c)

target_link_libraries(BushidoScenes TestScene)
