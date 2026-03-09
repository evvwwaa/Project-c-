#pragma once
#include <../core/AllAlgorithmI.h>
#include "../utilities/Logger.h"
#include <thread>

template <class T>
class BubbleSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
    std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override {
        auto& logger = Logger::getInstance();
        logger.log("Start: BubbleSort", Logger::INFO);

        if (data.size() <= 1) {
            logger.log("End: BubbleSort", Logger::INFO);
            return;
        }
        for (size_t i = 0; i < data.size() - 1; ++i) {
            bool areSwapped = false;
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);


                    if (visualizer) {
                        std::this_thread::sleep_for(std::chrono::milliseconds(50));
                        (*visualizer)(data, j, j+1);
                    }
                    areSwapped = true;
                }
            }
            if (!areSwapped) {
                break;
            }
        }

        logger.log("End: BubbleSort", Logger::INFO);
    }

    std::string algType() const override { return "BubbleSort"; }
    std::string complexity() const override { return "O(n²)"; }
};


