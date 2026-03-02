#include "SelectionSort.h"
#include "../utilities/Logger.h"

void SelectionSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>, int, int)>> visualizer) {
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
                (*visualizer)(data, now_min_element, j);
            }
            if (data[j] < data[now_min_element]) {
                now_min_element = j;
            }
        }
        if (now_min_element != i) {
            std::swap(data[i], data[now_min_element]);
            if (visualizer) {
                (*visualizer)(data, i, now_min_element);
            }
        }
    }

    logger.log("End: SelectionSort", Logger::INFO);
}