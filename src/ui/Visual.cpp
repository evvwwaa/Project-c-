#include "Visual.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iomanip>

Visual::Visual() {}

void Visual::visualize(std::span<int> data, int i1, int i2) {
    if (data.empty()) {
        std::cout << "[Empty]\n";
        return;
    }

    int maxValue = std::max(*std::max_element(data.begin(), data.end()), 1);
    int maxHeight = 10;

    std::vector<int> heights;
    for (auto x : data) {
        heights.push_back(x * maxHeight / maxValue);
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
