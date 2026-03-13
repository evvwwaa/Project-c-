add_executable(benchmarks benchmark.cpp)

target_link_libraries(benchmarks
        PRIVATE
        algorithms_lib
        core_lib
        utilities_lib
        ui_lib
        benchmark
)

target_include_directories(benchmarks
        PRIVATE
        ${PROJECT_SOURCE_DIR}/src/algorithms
        ${PROJECT_SOURCE_DIR}/src/core
        ${PROJECT_SOURCE_DIR}/src/utilities
        ${PROJECT_SOURCE_DIR}/src/ui
        ${PROJECT_BINARY_DIR}/_deps/benchmark-src/include
)