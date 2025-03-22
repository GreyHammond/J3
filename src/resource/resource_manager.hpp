#pragma once
#include "common.hpp"
#include "resource_pool.hpp"

// probably my favorite class
class resource_manager {
public:
    template <typename T, typename... args>
    std::shared_ptr<T> add(const std::string& name, args&&... a) {
        auto pool = get_pool<T>();
        return pool->add(name, std::forward<args>(a)...);
    }

    template <typename T>
    std::shared_ptr<T> get(const std::string& name) {
        auto pool = get_pool<T>();
        return pool->get(name);
    }

private:
    // cast to unknown type to avoid specifying the template type
    std::unordered_map<uint32_t, void*> pools;

    template <typename T>
    resource_pool<T>* get_pool() {
        static constexpr uint32_t hash = entt::type_hash<T>::value();
        if (auto it = pools.find(hash); it != pools.end()) {
            return static_cast<resource_pool<T>*>(it->second);
        }

        pools.emplace(hash, new resource_pool<T>());
        return static_cast<resource_pool<T>*>(pools[hash]);
    }
};
