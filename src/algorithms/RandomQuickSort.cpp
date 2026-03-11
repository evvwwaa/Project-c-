// #include "RandomQuickSort.h"
// #include "../utilities/Logger.h"
//
// template<class T>
// void RandomQuickSort<T>::sort(std::span<T> data, std::optional<std::function<void(std::span<T>, int, int)>> visualizer) {
//     auto& logger = Logger::getInstance();
//     logger.log("Start: RandomQuickSort", Logger::INFO);
//
//     if (data.size() <= 1) {
//         logger.log("End: RandomQuickSort (array size <= 1)", Logger::INFO);
//         return;
//     }
//
//     std::srand(std::time(nullptr));
//
//     std::function<void(int, int)> quickSortRecursive = [&](int low, int high) {
//         if (low >= high) return;
//
//         int randomIndex = low + rand() % (high - low + 1);
//         int pivot = data[randomIndex];
//
//         if (visualizer) {
//             (*visualizer)(data, randomIndex, -1);
//             std::this_thread::sleep_for(std::chrono::milliseconds(50));
//         }
//
//         int temp = data[randomIndex];
//         data[randomIndex] = data[low + (high - low) / 2];
//         data[low + (high - low) / 2] = temp;
//
//         int i = low;
//         int j = high;
//
//         while (i <= j) {
//             while (i <= high && data[i] < pivot) {
//                 i++;
//                 if (visualizer) {
//                     (*visualizer)(data, i, -1);
//                     std::this_thread::sleep_for(std::chrono::milliseconds(20));
//                 }
//             }
//
//             while (j >= low && data[j] > pivot) {
//                 j--;
//                 if (visualizer) {
//                     (*visualizer)(data, -1, j);
//                     std::this_thread::sleep_for(std::chrono::milliseconds(20));
//                 }
//             }
//
//             if (i <= j) {
//                 int tempSwap = data[i];
//                 data[i] = data[j];
//                 data[j] = tempSwap;
//
//                 if (visualizer) {
//                     (*visualizer)(data, i, j);
//                     std::this_thread::sleep_for(std::chrono::milliseconds(50));
//                 }
//
//                 i++;
//                 j--;
//             }
//         }
//
//         if (visualizer) {
//             (*visualizer)(data, -1, -1);
//             std::this_thread::sleep_for(std::chrono::milliseconds(30));
//         }
//
//         if (low < j) quickSortRecursive(low, j);
//         if (i < high) quickSortRecursive(i, high);
//     };
//
//     quickSortRecursive(0, data.size() - 1);
//
//     if (visualizer) {
//         (*visualizer)(data, -1, -1);
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }
//
//     logger.log("End: RandomQuickSort", Logger::INFO);
// }