#include "AllAlgorithms.h"
#include "../utilities/Logger.h"
#include <iostream>
#include "../algorithms/BubbleSort.h"

std::unique_ptr<AllAlgorithmsI> AlgCreation::create(const std::string &algType) {
    Logger::getInstance().log("The algorithm: " + algType, Logger::DEBUG);

    if (algType == "BubbleSort") {
        return std::make_unique<BubbleSort>();
    }

    Logger::getInstance().log("Noname algorithm: " + algType, Logger::ERROR);
    throw std::invalid_argument("No such algorithm" + algType);
}

std::vector<std::string> AlgCreation::available() {
    return {"BubbleSort", "SelectionSort", "InsertionSort", "MergeSort", "QuickSort", "RandomQuickSort", "CountingSort", "RadixSort"};
}
