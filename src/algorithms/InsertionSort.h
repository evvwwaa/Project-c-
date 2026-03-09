#pragma once

#include "../core/AllAlgorithms.h"

template<class T>
class InsertionSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
             std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override;

    std::string algType() const override { return "InsertionSort"; }
    std::string complexity() const override { return "O(n²)"; }
};