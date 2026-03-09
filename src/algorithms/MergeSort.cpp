// #include "MergeSort.h"
// #include "../utilities/Logger.h"
//
// template <class T>
// void MergeSort<T>::sort(std::span<T> data, std::optional<std::function<void(std::span<T>, int, int)>> visualizer) {
//     auto& logger = Logger::getInstance();
//     logger.log("Start: MergeSort", Logger::INFO);
//
//     std::vector<T> vector(data.begin(), data.end());
//     mergeSort(vector, 0, vector.size() - 1);
//
//     for (size_t i = 0; i < vector.size(); ++i) {
//         data[i] = vector[i];
//     }
//
//     if (visualizer.has_value()) {
//         visualizer.value()(data, 0, data.size() - 1);
//     }
//
//     logger.log("End: MergeSort", Logger::INFO);
// }
//
// template <typename T>
// void MergeSort<T>::merge(std::vector<T>& vec, size_t left, size_t mid, size_t right) {
//     std::vector<T> temp;
//     temp.reserve(right - left + 1);
//
//     size_t i = left;
//     size_t j = mid + 1;
//
//     while (i <= mid && j <= right) {
//         if (vec[i] <= vec[j]) {
//             temp.push_back(vec[i++]);
//         }
//         else {
//             temp.push_back(vec[j++]);
//         }
//     }
//
//     while (i <= mid) temp.push_back(vec[i++]);
//     while (j <= right) temp.push_back(vec[j++]);
//
//     for (size_t k = 0; k < temp.size(); ++k) {
//         vec[left + k] = temp[k];
//     }
// }
//
// template <typename T>
// void MergeSort<T>::mergeSort(std::vector<T>& vec, size_t left, size_t right) {
//     if (left >= right) return;
//
//     size_t mid = left + (right - left) / 2;
//     mergeSort(vec, left, mid);
//     mergeSort(vec, mid + 1, right);
//     merge(vec, left, mid, right);
// }
//
// template class MergeSort<int>;
// template class MergeSort<double>;
// template class MergeSort<float>;