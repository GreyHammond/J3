#pragma once
#include "common.hpp"
#include "entity_system.hpp"

class ecs_manager {
public:
    void initialize();
    void update();

    [[nodiscard]] entt::entity create_entity();

    template <typename component_t, typename... args>
    component_t& add_component(entt::entity entity, args&&... a) {
        return registry.emplace<component_t>(entity, std::forward<args>(a)...);
    }

    template <typename system_t, typename... args>
    void add_system(args&&... a) {
        systems.push_back(entity_system{system_t(std::forward<args>(a)...)});
    }

private:
    std::vector<entity_system> systems;
    entt::registry registry;
};
