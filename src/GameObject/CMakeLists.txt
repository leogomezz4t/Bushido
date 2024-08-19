add_library(GameObject STATIC gameObject.c)
target_link_libraries(GameObject Types)
target_include_directories(GameObject PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}"
                            )
