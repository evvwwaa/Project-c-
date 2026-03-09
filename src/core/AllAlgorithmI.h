#pragma once

#include <span>

template <class T>
class AllAlgorithmsI {
public:
    AllAlgorithmsI() = default;
    virtual ~AllAlgorithmsI() = default;

    virtual void sort(std::span<T> data, std::optional<std::function<void(std::span<T>, int, int)>> visualizer = std::nullopt) = 0;

    virtual std::string algType() const = 0;
    virtual std::string complexity() const = 0;
};