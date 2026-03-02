#include "BubbleSort.h"
#include "../utilities/Logger.h"

void BubbleSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
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
                areSwapped = true;

                if (visualizer) {
                    (*visualizer)(data);
                }
            }
        }
        if (!areSwapped) {
            break;
        }
    }

    logger.log("End: BubbleSort", Logger::INFO);
}