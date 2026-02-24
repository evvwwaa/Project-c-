add_library(algorithms_lib
        BubbleSort.cpp
        BubbleSort.h
)

target_include_directories(algorithms_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)