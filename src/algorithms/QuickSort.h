#pragma once

#include "../core/AllAlgorithms.h"

class QuickSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>, int, int)>> visualizer) override;

    std::string algType() const override { return "QuickSort"; }
    std::string complexity() const override { return "O(n)"; }
};