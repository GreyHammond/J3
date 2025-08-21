#include "timer.hpp"

timer::timer() {
    this->start_time = std::chrono::high_resolution_clock::now();
    this->last_time = this->start_time;
    this->fps_time = this->start_time;
}

void timer::update() {
    auto now = std::chrono::high_resolution_clock::now();
    this->delta_time = std::chrono::duration<double>(now - this->last_time).count();
    this->time = std::chrono::duration<double>(now - this->start_time).count();
    this->last_time = now;
    this->frames++;

    // calc fps
    if (std::chrono::duration<double>(now - fps_time).count() >= 1.0) {
        this->fps = this->frames;
        this->frames = 0;
        this->fps_time = now;
    }
}
