#pragma once

#include "../core/AllAlgorithms.h"

class RandomQuickSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>, int, int)>> visualizer) override;

    std::string algType() const override { return "RandomQuickSort"; }
    std::string complexity() const override { return "O(n)"; }
};