add_library(Scene STATIC componentUpdates.c scene.c)
target_link_libraries(Scene GameObject SpriteAnimation Collider GameCamera)
target_include_directories(Scene PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
