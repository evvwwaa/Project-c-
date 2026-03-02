add_library(ui_lib Visual.cpp Visual.h)

target_include_directories(ui_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
