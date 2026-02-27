#include "CountingSort.h"
#include "../utilities/Logger.h"

void CountingSort::sort(std::span<int> data, std::optional<std::function<void(std::span<int>)>> visualizer) {
    auto& logger = Logger::getInstance();
    logger.log("Start: CountingSort", Logger::INFO);

    if (data.size() <= 1) {
        logger.log("End: CountingSort", Logger::INFO);
        return;
    }

    int max_element = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] > max_element) {
            max_element = data[i];
        }
    }

    std::vector<int> vector(max_element + 1, 0);

    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] += 1;
    }

    int index_element = 0;
    for (int i = 0; i <= max_element; ++i) {
        while (vector[i] > 0) {
            data[index_element] = i;
            ++index_element;
            --vector[i];

            if (visualizer) {
                (*visualizer)(data);
            }
        }
    }

    logger.log("End: CountingSort", Logger::INFO);
}