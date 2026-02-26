#include "InsertionSort.h"
#include "../utilities/Logger.h"

void InsertionSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: InsertionSort", Logger::INFO);

    //

    logger.log("End: InsertionSort", Logger::INFO);
}