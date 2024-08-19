add_library(GameObject STATIC gameObject.c)
target_include_directories(GameObject PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}"
                             "${PROJECT_SOURCE_DIR}/src/Vectors"
                             "${PROJECT_SOURCE_DIR}/src/Types")
