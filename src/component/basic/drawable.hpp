#pragma once
#include "common.hpp"

#include "system/render/material/material.hpp"
#include "system/render/mesh/mesh.hpp"

struct drawable {
    std::shared_ptr<mesh> mesh;
    std::shared_ptr<material> mat;
};
