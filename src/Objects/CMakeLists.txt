add_subdirectory(Rayleigh)

add_library(BushidoObjects STATIC empty.c)

target_link_libraries(BushidoObjects Rayleigh)
