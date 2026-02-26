#pragma once

#include "../core/AllAlgorithms.h"

class RadixSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>)>> visualizer) override;

    std::string algType() const override { return "RadixSort"; }
    std::string complexity() const override { return "O(n*k)"; }
};