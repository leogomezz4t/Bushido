add_library(SpriteAnimation STATIC spriteAnimation.c spriteRenderer.c sprite.c)
target_link_libraries(SpriteAnimation Types GameObject)
target_include_directories(SpriteAnimation PUBLIC
                            "${CMAKE_CURRENT_SOURCE_DIR}")
