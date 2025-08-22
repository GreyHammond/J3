#pragma once
#include "common.hpp"

class controller {
public:
    virtual ~controller() = default;
    virtual void bind_data(Rml::DataModelConstructor& dmc) = 0;
};
