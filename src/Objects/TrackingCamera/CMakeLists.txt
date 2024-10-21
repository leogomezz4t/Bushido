add_library(TrackingCamera STATIC trackingCamera.c)
target_link_libraries(TrackingCamera GameEngine GameObject)
target_include_directories(TrackingCamera PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
