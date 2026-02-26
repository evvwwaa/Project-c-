#pragma once

#include "../core/AllAlgorithms.h"

class InsertionSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>)>> visualizer) override;

    std::string algType() const override { return "InsertionSort"; }
    std::string complexity() const override { return "O(n²)"; }
};