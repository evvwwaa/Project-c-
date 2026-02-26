#pragma once

#include "../core/AllAlgorithms.h"

class MergeSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>)>> visualizer) override;

    std::string algType() const override { return "MergeSort"; }
    std::string complexity() const override { return "O(n)"; }
};