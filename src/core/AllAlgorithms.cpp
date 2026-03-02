#include "AllAlgorithms.h"
#include "../utilities/Logger.h"
#include <iostream>
#include "../algorithms/BubbleSort.h"
#include "../algorithms/SelectionSort.h"
#include "../algorithms/InsertionSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/QuickSort.h"
#include "../algorithms/RandomQuickSort.h"
#include "../algorithms/CountingSort.h"
#include "../algorithms/RadixSort.h"

std::unique_ptr<AllAlgorithmsI> AlgCreation::create(const std::string &algType) {
    Logger::getInstance().log("The algorithm: " + algType, Logger::DEBUG);

    if (algType == "BubbleSort") {
        return std::make_unique<BubbleSort>();
    }
    else if (algType == "SelectionSort") {
        return std::make_unique<SelectionSort>();
    }
    else if (algType == "InsertionSort") {
        return std::make_unique<InsertionSort>();
    }
    else if (algType == "MergeSort") {
        return std::make_unique<MergeSort>();
    }
    else if (algType == "QuickSort") {
        return std::make_unique<QuickSort>();
    }
    else if (algType == "RandomQuickSort") {
        return std::make_unique<RandomQuickSort>();
    }
    else if (algType == "CountingSort") {
        return std::make_unique<CountingSort>();
    }
    else if (algType == "RadixSort") {
        return std::make_unique<RadixSort>();
    }

    Logger::getInstance().log("Noname algorithm: " + algType, Logger::ERROR);
    throw std::invalid_argument("No such algorithm" + algType);
}

std::vector<std::string> AlgCreation::available() {
    return {"BubbleSort", "SelectionSort", "InsertionSort", "MergeSort", "QuickSort", "RandomQuickSort", "CountingSort", "RadixSort"};
}
