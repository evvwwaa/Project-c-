#pragma once
#include<string>
#include<span>

class Visual {
public:
    Visual();

    template<typename T>
    void visualize(std::span<T> data, int i1, int i2);
    void title(const std::string& title);
    void algInformation(const std::string& algType, const std::string& complexity);

private:
    std::string algType_;
    std::string complexity_;
    bool firstVisualization_;
    int visualizationHeight_;
    bool supportsANSI_;
};
