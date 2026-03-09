#pragma once

#include "../core/AllAlgorithms.h"

template<class T>
class CountingSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
             std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override;

    std::string algType() const override { return "CountingSort"; }
    std::string complexity() const override { return "O(n+k)"; }
};