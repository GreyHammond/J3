#pragma once
#include "common.hpp"

#include "system/render/buffer/d3d_buffer.hpp"
#include "vertex.hpp"

struct mesh {
    std::vector<vertex> vertices;
    std::vector<DWORD> indices;

    std::unique_ptr<d3d_buffer> vertex_buffer;
    std::unique_ptr<d3d_buffer> index_buffer;

    mesh(const std::vector<vertex>& vertices, const std::vector<DWORD>& indices)
        : vertices(vertices), indices(indices) {
        vertex_buffer = std::make_unique<d3d_buffer>();
        index_buffer = std::make_unique<d3d_buffer>();
    }
};
