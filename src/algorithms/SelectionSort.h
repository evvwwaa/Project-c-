#pragma once

#include "../core/AllAlgorithms.h"

template<class T>
class SelectionSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
             std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override;

    std::string algType() const override { return "SelectionSort"; }
    std::string complexity() const override { return "O(n²)"; }
};
