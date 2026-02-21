add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(algorithms)

add_executable(project main.cpp
        main.cpp)

target_include_directories(project
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        ${CMAKE_CURRENT_SOURCE_DIR}/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms
)