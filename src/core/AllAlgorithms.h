#pragma once

#include <span>

class AllAlgorithmsI {
public:
    AllAlgorithmsI() = default;
    virtual ~AllAlgorithmsI() = default;

    virtual void sort(std::span<int> data, std::optional<std::function<void(std::span<int>, int, int)>> visualizer = std::nullopt) = 0;

    virtual std::string algType() const = 0;
    virtual std::string complexity() const = 0;
};

class AlgCreation {
public:
    static std::unique_ptr<AllAlgorithmsI> create(const std::string& algType);

    static std::vector<std::string> available();
};