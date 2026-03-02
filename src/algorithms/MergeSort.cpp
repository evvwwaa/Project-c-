#include "MergeSort.h"
#include "../utilities/Logger.h"

void MergeSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>, int, int)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: MergeSort", Logger::INFO);

    //

    logger.log("End: MergeSort", Logger::INFO);
}