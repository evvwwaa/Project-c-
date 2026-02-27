#include "RadixSort.h"
#include <vector>
#include "../utilities/Logger.h"

void RadixSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: RadixSort", Logger::INFO);

    if (data.size() <= 1) {
        logger.log("End: RadixSort", Logger::INFO);
        return;
    }

    int in_the_beginning_max_element = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] > in_the_beginning_max_element) {
            in_the_beginning_max_element = data[i];
        }
    }

    for (int which_digit = 1; in_the_beginning_max_element / which_digit > 0; which_digit *= 10) {
        std::vector<std::vector<int>>
    }

    logger.log("End: RadixSort", Logger::INFO);
}