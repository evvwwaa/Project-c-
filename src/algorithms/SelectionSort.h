#pragma once
#include <../core/AllAlgorithmI.h>
#include "../utilities/Logger.h"
#include <thread>

template<class T>
class SelectionSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
    std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override {
        auto& logger = Logger::getInstance();
        logger.log("Start: SelectionSort", Logger::INFO);

        if (data.size() <= 1) {
            logger.log("End: SelectionSort", Logger::INFO);
            return;
        }

        for (size_t i = 0; i < data.size() - 1; ++i) {
            size_t now_min_element = i;

            for (size_t j = i + 1; j < data.size(); ++j) {
                if (visualizer) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    (*visualizer)(data, now_min_element, j);
                }
                if (data[j] < data[now_min_element]) {
                    now_min_element = j;
                }
            }
            if (now_min_element != i) {
                std::swap(data[i], data[now_min_element]);
                if (visualizer) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    (*visualizer)(data, i, now_min_element);
                }
            }
        }

        logger.log("End: SelectionSort", Logger::INFO);
    }

    std::string algType() const override { return "SelectionSort"; }
    std::string complexity() const override { return "O(n²)"; }
};
