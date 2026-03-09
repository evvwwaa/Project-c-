#pragma once

#include "../utilities/Logger.h"
#include "../algorithms/BubbleSort.h"
#include "../algorithms/SelectionSort.h"
#include "../algorithms/InsertionSort.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/QuickSort.h"
#include "../algorithms/RandomQuickSort.h"
#include "../algorithms/CountingSort.h"
#include "../algorithms/RadixSort.h"

class AlgCreation {
public:
    template<class T>
    static std::unique_ptr<AllAlgorithmsI<T>> create(const std::string& algType);

    static std::vector<std::string> available();
};

template <class T>
std::unique_ptr<AllAlgorithmsI<T>> AlgCreation::create(const std::string &algType) {
    Logger::getInstance().log("The algorithm: " + algType, Logger::DEBUG);

    if (algType == "BubbleSort") {
        return std::make_unique<BubbleSort<T>>();
    }
    else if (algType == "SelectionSort") {
        return std::make_unique<SelectionSort<T>>();
    }
    else if (algType == "InsertionSort") {
        return std::make_unique<InsertionSort<T>>();
    }
    else if (algType == "MergeSort") {
        return std::make_unique<MergeSort<T>>();
    }
    else if (algType == "QuickSort") {
        return std::make_unique<QuickSort<T>>();
    }
    // else if (algType == "RandomQuickSort") {
    //     return std::make_unique<RandomQuickSort>();
    // }
    else if (algType == "CountingSort") {
        return std::make_unique<CountingSort<T>>();
    }
    // else if (algType == "RadixSort") {
    //     return std::make_unique<RadixSort>();
    // }

    Logger::getInstance().log("Noname algorithm: " + algType, Logger::ERROR);
    throw std::invalid_argument("No such algorithm" + algType);
}

inline std::vector<std::string> AlgCreation::available() {
    return {"BubbleSort", "SelectionSort", "InsertionSort", "MergeSort", "QuickSort", "RandomQuickSort", "CountingSort", "RadixSort"};
}