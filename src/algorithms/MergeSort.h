#pragma once

#include "../core/AllAlgorithms.h"

template<class T>
class MergeSort : public AllAlgorithmsI<T> {
public:
    void sort(std::span<T> data,
             std::optional<std::function<void(std::span<T>, int, int)>> visualizer) override;

    void merge(std::vector<T> &vec, size_t left, size_t mid, size_t right);

    void mergeSort(std::vector<T> &vec, size_t left, size_t right);

    std::string algType() const override { return "MergeSort"; }
    std::string complexity() const override { return "O(n)"; }
};