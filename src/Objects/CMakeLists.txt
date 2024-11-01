add_subdirectory(Rayleigh)
add_subdirectory(Square)
add_subdirectory(TrackingCamera)
add_subdirectory(TestMap)
add_subdirectory(ParallaxBackground)

add_library(BushidoObjects STATIC empty.c)

target_link_libraries(BushidoObjects Rayleigh TestMap Square ParallaxBackground TrackingCamera)
