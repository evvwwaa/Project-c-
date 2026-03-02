#include "QuickSort.h"
#include "../utilities/Logger.h"

void QuickSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>, int, int)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: QuickSort", Logger::INFO);

    //

    logger.log("End: QuickSort", Logger::INFO);
}