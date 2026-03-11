#pragma once

#include "../core/AllAlgorithmI.h"
#include "../utilities/Logger.h"

template<class T>
class RadixSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
      std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override {
        auto& logger = Logger::getInstance();
        logger.log("Start: RadixSort", Logger::INFO);

        if (data.size() <= 1) {
            logger.log("End: RadixSort", Logger::INFO);
            return;
        }

        std::vector<T> vec(data.begin(), data.end());

        if constexpr (std::is_floating_point_v<T>) {
            std::sort(vec.begin(), vec.end());
            for (size_t i = 0; i < vec.size(); i++) {
                data[i] = vec[i];
                if (visualizer.has_value()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    visualizer.value()(data, static_cast<int>(i), static_cast<int>(i));
                }
            }
        } else if constexpr (std::is_integral_v<T>) {
            std::vector<int> intVec(vec.begin(), vec.end());
            radixSortInt(intVec);

            for (size_t i = 0; i < vec.size(); i++) {
                vec[i] = static_cast<T>(intVec[i]);
                data[i] = vec[i];

                if (visualizer.has_value()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    visualizer.value()(data, static_cast<int>(i), static_cast<int>(i));
                }
            }
        }

        if (visualizer.has_value()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            visualizer.value()(data, -1, -1);
        }

        logger.log("End: RadixSort", Logger::INFO);
    }

    std::string algType() const override { return "RadixSort"; }
    std::string complexity() const override { return "O(n*k)"; }

    void countSortInt(std::vector<int>& vec, size_t size, int exp) {
    std::vector<int> result(size);
    std::vector<size_t> count(10, 0);

    int minElement = *std::min_element(vec.begin(), vec.end());
    int offset = (minElement < 0) ? -minElement : 0;

    for (size_t i = 0; i < size; i++) {
        int val = vec[i] + offset;
        int digit = static_cast<int>((val / exp) % 10);
        count[digit]++;
    }

    for (size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int val = vec[i] + offset;
        int digit = static_cast<int>((val / exp) % 10);
        size_t pos = count[digit] - 1;
        result[pos] = vec[i];
        count[digit]--;
    }

    for (size_t i = 0; i < size; i++) {
        vec[i] = result[i];
    }
}

    void radixSortInt(std::vector<int>& vec) {
        if (vec.empty()) return;

        std::vector<int> negatives;
        std::vector<int> positives;
        for (int val : vec) {
            if (val < 0) negatives.push_back(-val);
            else positives.push_back(val);
        }

        if (!negatives.empty()) {
            int maxVal = *std::max_element(negatives.begin(), negatives.end());
            for (int exp = 1; maxVal / exp > 0; exp *= 10)
                countSortInt(negatives, negatives.size(), exp);
        }
        if (!positives.empty()) {
            int maxVal = *std::max_element(positives.begin(), positives.end());
            for (int exp = 1; maxVal / exp > 0; exp *= 10)
                countSortInt(positives, positives.size(), exp);
        }

        for (auto& v : negatives) v = -v;
        std::reverse(negatives.begin(), negatives.end());

        size_t idx = 0;
        for (auto v : negatives) vec[idx++] = v;
        for (auto v : positives) vec[idx++] = v;
}

    void radixSortFloat(std::vector<T>& vec, std::span<T> data,
                                   std::optional<std::function<void(std::span<T>, int, int)>>& visualizer) {
    std::vector<int> intVec(vec.size());

    for (size_t i = 0; i < vec.size(); i++) {
        std::memcpy(&intVec[i], &vec[i], sizeof(T));
        if (intVec[i] < 0) {
            intVec[i] = INT_MIN - intVec[i];
        } else {
            intVec[i] |= static_cast<int>(1) << 63;
        }
    }

        radixSortInt(intVec);
        for (size_t i = 0; i < vec.size(); i++) {
            if (intVec[i] < 0) {
                intVec[i] = INT_MIN - intVec[i];
            } else {
                intVec[i] &= ~(static_cast<int>(1) << 63);
            }
            std::memcpy(&vec[i], &intVec[i], sizeof(T));
            data[i] = vec[i];

            if (visualizer.has_value()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                visualizer.value()(data, static_cast<int>(i), static_cast<int>(i));
            }
        }
    }

    // template class RadixSort<int>;
    // template class RadixSort<int>;
    // template class RadixSort<float>;
    // template class RadixSort<double>;

};