#pragma once
#include "common.hpp"

#include "framework/ui/controller/controller.hpp"
#include "j3/model/sidebar_model.hpp"

class sidebar_controller : public controller {
public:
    void bind_data(Rml::DataModelConstructor& dmc) override;

private:
    sidebar_model model;
};
