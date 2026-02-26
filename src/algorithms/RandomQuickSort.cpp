#include "RandomQuickSort.h"
#include "../utilities/Logger.h"

void RandomQuickSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: RandomQuickSort", Logger::INFO);

    //

    logger.log("End: RandomQuickSort", Logger::INFO);
}