#include "ecs_manager.hpp"

void ecs_manager::initialize() {
    for (auto& system : systems) {
        system->initialize();
    }
}

void ecs_manager::update() {
    for (auto& system : systems) {
        system->update(registry);
    }
}

entt::entity ecs_manager::create_entity() {
    return registry.create();
}
