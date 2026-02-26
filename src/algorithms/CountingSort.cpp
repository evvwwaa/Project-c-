#include "CountingSort.h"
#include "../utilities/Logger.h"

void CountingSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: CountingSort", Logger::INFO);

    //

    logger.log("End: CountingSort", Logger::INFO);
}