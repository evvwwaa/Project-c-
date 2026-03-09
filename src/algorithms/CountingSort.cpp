#include "CountingSort.h"
#include <vector>
#include "../utilities/Logger.h"
#include <thread>

template<class T>
void CountingSort<T>::sort(std::span<T> data, std::optional<std::function<void(std::span<T>, int, int)>> visualizer) {
    Logger& logger = Logger::getInstance();
    logger.log("Start: CountingSort", Logger::INFO);

    if (data.size() <= 1) {
        logger.log("End: CountingSort",
            Logger::INFO);
        return;
    }

    int min_element = data[0];
    int max_element = data[0];
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] < min_element) {
            min_element = data[i];
        }
        if (data[i] > max_element) {
            max_element = data[i];
        }
    }

    std::vector<int> count_elements(max_element - min_element + 1, 0);

    for (size_t i = 0; i < data.size(); i++) {
        count_elements[data[i] - min_element]++;
    }

    size_t first_index = 0;
    for (int i = 0; i < count_elements.size(); i++) {
        while (count_elements[i] > 0) {
            data[first_index] = i + min_element;
            if (visualizer) {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                (*visualizer)(data, first_index, -1);
            }
            first_index++;
            count_elements[i]--;
        }
    }

    logger.log("End: CountingSort", Logger::INFO);
}