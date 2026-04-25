#include "worker_pool.hpp"

void worker_pool::add_task(const task& t) {
    this->task_queue.enqueue(t);
}

void worker_pool::allocate(const int num_workers) {
    for (int i = 0; i < num_workers; i++) {
        this->workers.push_back(std::make_unique<worker>(this->task_queue));
        spdlog::debug("Created worker #{}", i);
    }
    
    spdlog::info("Allocated {} workers", num_workers);
}

void worker_pool::run() const {
    for (const auto& worker : this->workers) {
        worker->run();
    }
}

void worker_pool::destroy() {
    spdlog::debug("Requesting worker destruction");
    this->workers.clear(); // calls destructor for each
    spdlog::info("All work complete and all workers destroyed");
}