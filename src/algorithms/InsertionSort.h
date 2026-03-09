#pragma once
#include <../core/AllAlgorithmI.h>
#include "../utilities/Logger.h"
#include <thread>

template<class T>
class InsertionSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
    std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override {
        auto& logger = Logger::getInstance();
        logger.log("Start: InsertionSort", Logger::INFO);

        if (data.size() <= 1) {
            logger.log("End: InsertionSort", Logger::INFO);
            return;
        }

        for (size_t i = 1; i < data.size(); ++i) {
            auto current_element = data[i];
            int j = static_cast<int>(i) - 1;

            if (visualizer) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                (*visualizer)(data, i, j);
            }

            while (j >= 0 && current_element < data[j]) {
                data[j + 1] = data[j];
                if (visualizer) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    (*visualizer)(data, j, j + 1);
                    --j;
                }

                data[j + 1] = current_element;

                if (visualizer) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    (*visualizer)(data, j + 1, i);
                }
            }

            if (visualizer) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                (*visualizer)(data, -1, -1);
            }

            logger.log("End: InsertionSort", Logger::INFO);
        }
    }

    std::string algType() const override { return "InsertionSort"; }
    std::string complexity() const override { return "O(n²)"; }
};