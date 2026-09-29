#include "Collision2D.hpp"

[[nodiscard]] bool AABB::intersects(const AABB& other) const noexcept {
    return this->min.x < other.max.x && this->max.x > other.min.x && this->min.y < other.max.y && this->max.y > other.min.y;
}

[[nodiscard]] AABB Collision2D::bounds(const Vector2D& position) const noexcept {
    return { position - halfExtents , position + halfExtents };
}