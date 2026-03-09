#include "core/AllAlgorithms.h"
#include "ui/Visual.h"

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
}
//     data = {5, 8, 3, 9, 4, 1, 0};
//
//     auto selection = AlgCreation::create("SelectionSort");
//     Visual visual2;
//     visual2.title("Selection Sort Demo");
//     visual2.algInformation(selection->algType(), selection->complexity());
//     selection->sort(data, [&](std::span<int> arr, int i1, int i2){ visual2.visualize(arr, i1, i2); });
//
//     std::cout << "Sorted array (SelectionSort):\n";
//     for (auto x : data) std::cout << x << " ";
//     std::cout << std::endl;
//
//     data = {5, 8, 3, 9, 4, 1, 0};
//
//     auto insertion = AlgCreation::create("InsertionSort");
//     Visual visual3;
//     visual3.title("Insertion Sort Demo");
//     visual3.algInformation(selection->algType(), selection->complexity());
//     selection->sort(data, [&](std::span<int> arr, int i1, int i2){ visual3.visualize(arr, i1, i2); });
//
//     std::cout << "Sorted array (InsertionSort):\n";
//     for (auto x : data) std::cout << x << " ";
//     std::cout << std::endl;
//
//     data = {5, 8, 3, 9, 4, 1, 0};
//
//     auto counting = AlgCreation::create("CountingSort");
//     Visual visual4;
//     visual4.title("Counting Sort Demo");
//     visual4.algInformation(selection->algType(), selection->complexity());
//     selection->sort(data, [&](std::span<int> arr, int i1, int i2){ visual4.visualize(arr, i1, i2); });
//
//     std::cout << "Sorted array (CountingSort):\n";
//     for (auto x : data) std::cout << x << " ";
//     std::cout << std::endl;
// }