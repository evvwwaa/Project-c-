#include "InsertionSort.h"
#include "../utilities/Logger.h"

void InsertionSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: InsertionSort", Logger::INFO);

    if (data.size() <= 1) {
        logger.log("End: InsertionSort", Logger::INFO);
        return;
    }

    for (size_t i = 1; i < data.size(); ++i) {
        auto current_element = data[i];
        int j = static_cast<int>(i) - 1;

        while (j >= 0 && current_element < data[j]) {
            data[j + 1] = data[j];
            --j;
        }

        data[j + 1] = current_element;

        if (visualizer) {
            (*visualizer)(data);
        }
    }

    if (visualizer) {
        (*visualizer)(data);
    }

    logger.log("End: InsertionSort", Logger::INFO);
}