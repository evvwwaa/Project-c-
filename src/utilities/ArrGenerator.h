#pragma once

#include <vector>
#include <random>

class ArrGenerator {
public:
    template<typename T>
    static std::vector<T> randomArr(size_t size, T min = T(-1000000), T max = T(1000000)) {
        std::vector<T> arr(size);

        if constexpr (std::is_integral<T>::value) {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<T> dist(min, max);

            for (size_t i = 0; i < size; i++) {
                arr[i] = dist(generator);
            }
        } else if constexpr (std::is_floating_point<T>::value) {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_real_distribution<T> dist(min, max);

            for (size_t i = 0; i < size; i++) {
                arr[i] = dist(generator);
            }
        } else {
            static_assert(std::is_arithmetic<T>::value, "Not supporting this type.");
        }
        return arr;
    }

    template<typename T>
    static std::vector<T> sortedArray(size_t size, T min = T(-1000000), T max = T(1000000)) {
        std::vector<T> arr = randomArray<T>(size, min, max);
        std::sort(arr.begin(), arr.end());
        return arr;
    }
};