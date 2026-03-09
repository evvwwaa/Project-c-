add_library(core_lib
        AllAlgorithms.cpp
        AllAlgorithms.h
        AllAlgorithmI.h
        AllAlgorithmI.h
        AllAlgorithmI.h
)

target_include_directories(core_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
