#include "../ui/Visual.h"
#include "AllAlgorithms.h"

#include<iostream>

int main() {
    std::vector<int> data = {5, 8, 3, 9, 4, 1, 0};

    auto bubble = AlgCreation::create<int>("BubbleSort");
    Visual visual;
    visual.title("Bubble Sort Demo");
    visual.algInformation(bubble->algType(), bubble->complexity());
    bubble->sort(data, [&](std::span<int> arr, int i1, int i2){ visual.visualize(arr, i1, i2); });

    std::cout << "Sorted array (BubbleSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << "\n\n";

    data = {5, 8, 3, 9, 4, 1, 0};

    auto selection = AlgCreation::create<int>("SelectionSort");
    Visual visual2;
    visual2.title("Selection Sort Demo");
    visual2.algInformation(selection->algType(), selection->complexity());
    selection->sort(data, [&](std::span<int> arr, int i1, int i2){ visual2.visualize(arr, i1, i2); });

    std::cout << "Sorted array (SelectionSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;

    data = {5, 8, 3, 9, 4, 1, 0};

    auto insertion = AlgCreation::create<int>("InsertionSort");
    Visual visual3;
    visual3.title("Insertion Sort Demo");
    visual3.algInformation(insertion->algType(), insertion->complexity());
    insertion->sort(data, [&](std::span<int> arr, int i1, int i2){ visual3.visualize(arr, i1, i2); });

    std::cout << "Sorted array (InsertionSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;

    data = {5, 8, 3, 9, 4, 1, 0};

    auto counting = AlgCreation::create<int>("CountingSort");
    Visual visual4;
    visual4.title("Counting Sort Demo");
    visual4.algInformation(counting->algType(), counting->complexity());
    counting->sort(data, [&](std::span<int> arr, int i1, int i2){ visual4.visualize(arr, i1, i2); });

    std::cout << "Sorted array (CountingSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;

    data = {5, 8, 3, 9, 4, 1, 0};

    auto merge = AlgCreation::create<int>("MergeSort");
    Visual visual5;
    visual5.title("Merge Sort Demo");
    visual5.algInformation(merge->algType(), merge->complexity());
    merge->sort(data, [&](std::span<int> arr, int i1, int i2){ visual5.visualize(arr, i1, i2); });

    std::cout << "Sorted array (MergeSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;

    data = {5, 8, 3, 9, 4, 1, 0};

    auto quick = AlgCreation::create<int>("QuickSort");
    Visual visual6;
    visual6.title("Quick Sort Demo");
    visual6.algInformation(quick->algType(), quick->complexity());
    quick->sort(data, [&](std::span<int> arr, int i1, int i2){ visual6.visualize(arr, i1, i2); });

    std::cout << "Sorted array (QuickSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;

    data = {5, 8, 3, 9, 4, 1, 0};

    auto radix = AlgCreation::create<int>("RadixSort");
    Visual visual7;
    visual7.title("Radix Sort Demo");
    visual7.algInformation(radix->algType(), radix->complexity());
    radix->sort(data, [&](std::span<int> arr, int i1, int i2){ visual7.visualize(arr, i1, i2); });

    std::cout << "Sorted array (RAdixSort):\n";
    for (auto x : data) std::cout << x << " ";
    std::cout << std::endl;
}