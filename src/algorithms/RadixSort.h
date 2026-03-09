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
            radixSortFloat(vec, data, visualizer);
        } else if constexpr (std::is_integral_v<T>) {
            std::vector<int64_t> intVec(vec.begin(), vec.end());
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

    void countSortInt(std::vector<int64_t>& vec, size_t size, int64_t exp) {
    std::vector<int64_t> result(size);
    std::vector<size_t> count(10, 0);

    int64_t minElement = *std::min_element(vec.begin(), vec.end());
    int64_t offset = (minElement < 0) ? -minElement : 0;

    for (size_t i = 0; i < size; i++) {
        int64_t val = vec[i] + offset;
        int digit = static_cast<int>((val / exp) % 10);
        count[digit]++;
    }

    for (size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int64_t val = vec[i] + offset;
        int digit = static_cast<int>((val / exp) % 10);
        size_t pos = count[digit] - 1;
        result[pos] = vec[i];
        count[digit]--;
    }

    for (size_t i = 0; i < size; i++) {
        vec[i] = result[i];
    }
}

    void radixSortInt(std::vector<int64_t>& vec) {
    if (vec.empty()) return;

    auto maxAbsIter = std::max_element(vec.begin(), vec.end(),
        [](int64_t a, int64_t b) { return std::abs(a) < std::abs(b); });
    int64_t maxAbsValue = std::abs(*maxAbsIter);

    for (int64_t exp = 1; maxAbsValue / exp > 0; exp *= 10) {
        countSortInt(vec, vec.size(), exp);
    }

    std::vector<int64_t> negatives, positives;
    for (int64_t val : vec) {
        if (val < 0) {
            negatives.push_back(val);
        } else {
            positives.push_back(val);
        }
    }

    std::reverse(negatives.begin(), negatives.end());

    size_t idx = 0;
    for (int64_t val : negatives) {
        vec[idx++] = val;
    }
    for (int64_t val : positives) {
        vec[idx++] = val;
    }
}

    void radixSortFloat(std::vector<T>& vec, std::span<T> data,
                                   std::optional<std::function<void(std::span<T>, int, int)>>& visualizer) {
    std::vector<int64_t> intVec(vec.size());

    for (size_t i = 0; i < vec.size(); i++) {
        std::memcpy(&intVec[i], &vec[i], sizeof(T));

        if (intVec[i] < 0) {
            intVec[i] = INT64_MIN - intVec[i];
        } else {
            intVec[i] |= static_cast<int64_t>(1) << 63;
        }
    }

    radixSortInt(intVec);

    for (size_t i = 0; i < vec.size(); i++) {
        if (intVec[i] < 0) {
            intVec[i] = INT64_MIN - intVec[i];
        } else {
            intVec[i] &= ~(static_cast<int64_t>(1) << 63);
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
    // template class RadixSort<int64_t>;
    // template class RadixSort<float>;
    // template class RadixSort<double>;

};