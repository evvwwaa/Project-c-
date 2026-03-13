#include <iostream>
#include <vector>
#include <string>
#include <BubbleSort.h>
#include <CountingSort.h>
#include <MergeSort.h>
#include <SelectionSort.h>
#include <InsertionSort.h>
#include <QuickSort.h>
#include <RandomQuickSort.h>
#include <RadixSort.h>

#include "ArrGenerator.h"
#include "../ui/Visual.h"

std::vector<std::string> SortNames = {"BubbleSort", "MergeSort", "InsertionSort", "SelectionSort",
    "CountingSort", "QuickSort", "RandomQuickSort", "RadixSort"
};

template<typename T>
std::unique_ptr<AllAlgorithmsI<T>> createSorter(const std::string& name) {
    if (name == "BubbleSort") {
        return std::make_unique<BubbleSort<T>>();
    }
    if (name == "MergeSort") {
        return std::make_unique<MergeSort<T>>();
    }
    if (name == "InsertionSort") {
        return std::make_unique<InsertionSort<T>>();
    }
    if (name == "SelectionSort") {
        return std::make_unique<SelectionSort<T>>();
    }
    if (name == "CountingSort") {
        return std::make_unique<CountingSort<T>>();
    }
    if (name == "QuickSort") {
        return std::make_unique<QuickSort<T>>();
    }
    if (name == "RandomQuickSort") {
        return std::make_unique<RandomQuickSort<T>>();
    }
    if (name == "RadixSort") {
        return std::make_unique<RadixSort<T>>();
    }
    throw std::invalid_argument("Unknown sort name!");
}

void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message << ": ";
    for (auto x : arr) std::cout << x << " ";
    std::cout << std::endl;
}

void SortRun(std::vector<int>& arr, int Type) {
    std::string SortName = SortNames[Type - 1];

    auto sorter = createSorter<int>(SortName);

    Visual visual;
    visual.title(SortName + " Visualization");
    visual.algInformation(sorter->algType(), sorter->complexity());

    printArray(arr, "First array");
    std::cout << "Sort begin...\n";

    sorter->sort(std::span<int>(arr),
      [&](std::span<int> arr, int i1, int i2){
         visual.visualize(arr, i1, i2);
      }
    );

    std::cout << "\nSorting " << SortName << " completed\n";
    printArray(arr, "Sorted array");
}
int ChooseTypeOfInput() {
    int TypeOfInput;
    do {
        std::cout << "Choose type of input:\n ";
        std::cout << "1. Enter numbers by yourself\n";
        std::cout << "2. Generate random numbers\n";
        std::cout << "3. Run Benchmarks\n";
        std::cout << "Your choice:\n ";
        std::cin >> TypeOfInput;
        if (TypeOfInput < 1 or TypeOfInput > 3) {
            std::cout << "Please enter valid choices.\n";
        }
    } while (TypeOfInput < 1 or TypeOfInput > 3);
    if (TypeOfInput == 1) {
        std::cout << "You selected manual input.\n";
    }
    else if (TypeOfInput == 2) {
        std::cout << "You selected random input.\n";
    }
    else if (TypeOfInput == 3) {
        std::cout << "You selected benchmarks.\n";
    }
    return TypeOfInput;
}

int ArraySize() {
    int size;
    do {
        std::cout << "Input array size:\n ";
        std::cin >> size;
        if (size < 1 or size > 1000) {
            std::cout << "Please enter valid array size.\n";
        }
        else {
            break;
        }
    } while (size < 1 or size > 1000);
    return size;
}

std::vector<int> InputNumbersByYourself(int size) {
    std::vector<int> arr(size);
    std::cout << "Input " << size << " numbers separated by spaces: \n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    return arr;
}

std::vector<int> GenerateNumbersByRandom(int size) {
    return ArrGenerator::randomArr<int>(size, 1, 100);
}

int chooseSortType() {
    int SortType;
    do {
        std::cout << "Choose type of input:\n ";
        std::cout << "1. BubbleSort\n";
        std::cout << "2. MergeSort\n";
        std::cout << "3. InsertionSort\n";
        std::cout << "4. SelectionSort\n";
        std::cout << "5. CountingSort\n";
        std::cout << "6. QuickSort\n";
        std::cout << "7. Random QuickSort\n";
        std::cout << "8. RadixSort\n";
        std::cout << "9. Run Benchmarks\n";
        std::cin >> SortType;
        if (SortType < 1 or SortType > 9) {
            std::cout << "Please enter valid choices.\n";
        } else {
            break;
        }
    } while (SortType < 1 or SortType > 9);
    return SortType;
}

void runBenchmarks() {
    std::cout << "\n=== Running Benchmarks ===\n";
    std::cout << "Wait, benchmarks are running...\n\n";

    int res = system("./benchmarks/benchmarks");

    if (res == 0) {
        std::cout << "\n=== Benchmarks completed successfully ===\n";
    } else {
        std::cout << "\n=== Error running benchmarks ===\n";
        std::cout << "cd cmake-build-debug && make benchmarks\n";
    }
}

int main() {
    int mode = ChooseTypeOfInput();
    int size = ArraySize();
    std::vector<int> arr;

    if (mode == 3) {
        runBenchmarks();
        return 0;
    }

    if (mode == 1) {
        arr = InputNumbersByYourself(size);
    }
    else {
        arr = GenerateNumbersByRandom(size);
    }
    int sortType = chooseSortType();
    SortRun(arr, sortType);

    if (sortType == 9) {
        runBenchmarks();
    } else {
        SortRun(arr, sortType);
    }
}