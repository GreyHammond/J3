#include "sidebar_controller.hpp"

void sidebar_controller::bind_data(Rml::DataModelConstructor& dmc) {
    dmc.Bind("selected_tab", &this->model.selected_tab);
    dmc.Bind("pinned", &this->model.pinned);

    dmc.BindEventCallback("bring_to_front", &sidebar_controller::bring_to_front, this);
}

void sidebar_controller::bring_to_front(Rml::DataModelHandle, Rml::Event& event, const Rml::VariantList&) {
    event.GetTargetElement()->GetOwnerDocument()->PullToFront();
}