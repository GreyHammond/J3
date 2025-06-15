#pragma once
#include "common.hpp"
#include "service.hpp"

class service_collection {
public:
    template <std::derived_from<service>... services_t>
    void add();

    template <std::derived_from<service> service_t>
    std::shared_ptr<service_t> get();

private:
    using service_hash = std::uint32_t;
    std::unordered_map<service_hash, std::shared_ptr<service>> service_map;

    template <std::derived_from<service> service_t>
    void add_service();
};

template <std::derived_from<service>... services_t>
void service_collection::add() {
    (this->add_service<services_t>(), ...);
}

template <std::derived_from<service> service_t>
std::shared_ptr<service_t> service_collection::get() {
    static constexpr service_hash hash = entt::type_hash<service_t>::value();
    if (this->service_map.contains(hash))
        return std::static_pointer_cast<service_t>(this->service_map[hash]);
    
    return nullptr;
}

template <std::derived_from<service> service_t>
void service_collection::add_service() {
    static constexpr service_hash hash = entt::type_hash<service_t>::value();
    this->service_map[hash] = std::make_unique<service_t>();
}
