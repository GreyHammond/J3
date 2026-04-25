#pragma once
#include "common.hpp"

class task {
public:
    std::string name{ "Unknown" };
    std::function<void(task&)> work{ nullptr };
    volatile float progress{ 0 };
};
