#pragma once

#include "../core/AllAlgorithms.h"

class CountingSort : public AllAlgorithmsI {
public:
    void sort(std::span<int> data,
             std::optional<std::function<void(std::span<int>)>> visualizer) override;

    std::string algType() const override { return "CountingSort"; }
    std::string complexity() const override { return "O(n+k)"; }
};