#pragma once

#include "../core/AllAlgorithmI.h"

template<class T>
class QuickSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data, std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override {
        auto& logger = Logger::getInstance();
        logger.log("Start: QuickSort", Logger::INFO);

        if (data.size() <= 1) {
            logger.log("End: QuickSort", Logger::INFO);
            return;
        }

        std::vector<T> vec(data.begin(), data.end());
        quickSort(vec, 0, static_cast<int>(vec.size()) - 1, visualizer);

        for (size_t i = 0; i < vec.size(); ++i) {
            data[i] = vec[i];
        }
        if (visualizer) {
            visualizer.value()(data, 0, static_cast<int>(data.size() - 1));
        }

        logger.log("End: QuickSort", Logger::INFO);
    }

    std::string algType() const override { return "QuickSort"; }
    std::string complexity() const override { return "O(n log n)"; }

    int partition(std::vector<T>& vec, int low, int high,
                  std::optional<std::function<void(std::span<T>, int, int)>> visualizer)
    {
        T pivot = vec[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (visualizer) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                visualizer.value()(std::span<T>(vec), high, j);
            }
            if (vec[j] < pivot) {
                ++i;
                std::swap(vec[i], vec[j]);
                if (visualizer) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    visualizer.value()(std::span<T>(vec), i, j);
                }
            }
        }
        std::swap(vec[i + 1], vec[high]);
        if (visualizer) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            visualizer.value()(std::span<T>(vec), i + 1, high);
        }
        return i + 1;
    }

    void quickSort(std::vector<T>& vec, int low, int high,
                  std::optional<std::function<void(std::span<T>, int, int)>> visualizer)
    {
        if (low < high) {
            int pi = partition(vec, low, high, visualizer);
            quickSort(vec, low, pi - 1, visualizer);
            quickSort(vec, pi + 1, high, visualizer);
        }
    }
};