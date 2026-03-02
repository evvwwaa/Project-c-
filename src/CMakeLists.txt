add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(algorithms)
add_subdirectory(utilities)

add_executable(project main.cpp)

target_link_libraries(project
        core_lib
        algorithms_lib
        utilities_lib
        ui_lib
)

target_include_directories(project
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/core
        ${CMAKE_CURRENT_SOURCE_DIR}/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/algorithms
        ${CMAKE_CURRENT_SOURCE_DIR}/utilities
)