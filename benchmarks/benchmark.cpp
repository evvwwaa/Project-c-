#include <benchmark/benchmark.h>
#include "../algorithms/BubbleSort.h"
#include "../algorithms/QuickSort.h"
#include "../algorithms/InsertionSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/SelectionSort.h"
#include "../algorithms/RadixSort.h"
#include "../algorithms/RandomQuickSort.h"
#include "../algorithms/CountingSort.h"
#include "../utilities/ArrGenerator.h"

static void BM_BubbleSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        BubbleSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_BubbleSort)->Range(8, 8<<12);

static void BM_QuickSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        QuickSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_QuickSort)->Range(8, 8<<12);

static void BM_CountingSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        CountingSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_CountingSort)->Range(8, 8<<12);

static void BM_InsertionSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        InsertionSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_InsertionSort)->Range(8, 8<<12);

static void BM_MergeSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        MergeSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_MergeSort)->Range(8, 8<<12);

static void BM_RadixSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        RadixSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_RadixSort)->Range(8, 8<<12);

static void BM_SelectionSort(benchmark::State& state) {
    for (auto _ : state) {
        auto arr = ArrGenerator::randomArr<int>(state.range(0));
        SelectionSort<int> sorter;
        sorter.sort(arr, std::nullopt);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(BM_SelectionSort)->Range(8, 8<<12);

// static void BM_RandomQuickSort(benchmark::State& state) {
//     for (auto _ : state) {
//         auto arr = ArrayGenerator::randomArr(state.range(0));
//         RandomQuickSort<int> sorter;
//         sorter.sort(arr, std::nullopt);
//         benchmark::DoNotOptimize(arr);
//     }
// }
// BENCHMARK(BM_RandomQuickSort)->Range(8, 8<<12);


BENCHMARK_MAIN();