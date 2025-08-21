#pragma once
#include "common.hpp"
#include "j3/window/main_window.hpp"

class jiayi {
public:
    jiayi(HINSTANCE instance, const std::wstring& command_line);

    static jiayi& get();
};

extern char jiayi_buffer[sizeof(jiayi)];
