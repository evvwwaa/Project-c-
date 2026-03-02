#include "RadixSort.h"
#include <vector>
#include "../utilities/Logger.h"

void RadixSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>, int, int)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: RadixSort", Logger::INFO);

    //
    logger.log("End: RadixSort", Logger::INFO);
}