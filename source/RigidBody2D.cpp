#include "RigidBody2D.hpp"

void RigidBody2D::integrate(float dt) noexcept {
    this->velocity = this->velocity + this->acceleration * dt;
    this->position = this->position + this->velocity * dt;
}