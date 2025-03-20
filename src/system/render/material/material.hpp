#pragma once
#include "common.hpp"
#include "texture.hpp"

struct material {
    vector4 color = { 1, 1, 1, 1 };
    std::shared_ptr<texture> tex = nullptr;

    material(const vector4& color, const std::shared_ptr<texture>& texture) : color(color), tex(texture) { }
};
