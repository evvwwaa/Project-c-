#include "Visual.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>

Visual::Visual() : firstVisualization_(true), visualizationHeight_(0) {
    const char* term = std::getenv("TERM");
    supportsANSI_ = (term != nullptr && std::string(term) != "dumb");
}

template<typename T>
void Visual::visualize(std::span<T> data, int i1, int i2) {
    if (data.empty()) {
        std::cout << "[Empty]\n";
        return;
    }

    double minValue = static_cast<double>(*std::min_element(data.begin(), data.end()));
    double maxValue = static_cast<double>(*std::max_element(data.begin(), data.end()));

    double range = (std::abs(maxValue - minValue) < 1e-9) ? 1.0 : (maxValue - minValue);

    int maxHeight = 10;

    std::vector<int> heights;
    for (auto x : data) {
        double nor = (static_cast<double>(x) - minValue) / range;
        heights.push_back(static_cast<int>(nor * maxHeight + 0.5));
    }

    if (supportsANSI_) {
        if (firstVisualization_) {
            firstVisualization_ = false;
            visualizationHeight_ = 24;
        } else {
            std::cout << "\033[" << visualizationHeight_ << "A";
        }

        for (int i = 0; i < visualizationHeight_; ++i) {
            std::cout << "\033[K";
            if (i < visualizationHeight_ - 1) {
                std::cout << "\n";
            }
        }

        std::cout << "\033[" << visualizationHeight_ << "A";
    } else {
        if (!firstVisualization_) {
            std::cout << "\n--- Step ---\n";
        }
        firstVisualization_ = false;
    }

    for (int r = maxHeight; r >= 1; --r) {
        for (size_t c = 0; c < data.size(); ++c) {
            if (c == i1 || c == i2)
                std::cout << "\033[1;31m"; //red

            if (heights[c] >= r)
                std::cout << " █ ";
            else
                std::cout << "   ";
            if (c == i1 || c == i2)
                std::cout << "\033[0m"; //white
        }
        std::cout << '\n';
    }

    for (size_t c = 0; c < data.size(); ++c) {
        if (c == i1 || c == i2)
            std::cout << "\033[1;31m";
        std::cout << std::setw(3) << data[c];
        if (c == i1 || c == i2)
            std::cout << "\033[0m";
    }

    std::cout << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void Visual::title(const std::string &title) {
    std::cout << title << std::endl;
}

void Visual::algInformation(const std::string &algType, const std::string &complexity) {
    algType_ = algType;
    complexity_ = complexity;
    std::cout << "Algorithm: " << algType_ << ".\n" << "Complexity: " << complexity_ << "\n";
}

template void Visual::visualize<int>(std::span<int>, int, int);
template void Visual::visualize<double>(std::span<double>, int, int);
template void Visual::visualize<float>(std::span<float>, int, int);