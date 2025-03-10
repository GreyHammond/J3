#pragma once
#include "common.hpp"

class jiayi {
public:
    jiayi(HINSTANCE instance, const std::wstring& command_line);

    static jiayi& get();
};

extern char jiayi_buffer[sizeof(jiayi)];
