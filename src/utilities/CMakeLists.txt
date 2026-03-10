add_library(utilities_lib
        Logger.cpp
        Logger.h
        ArrGenerator.h
)

target_include_directories(utilities_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
