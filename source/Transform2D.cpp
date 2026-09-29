#include "Transform2D.hpp"

[[nodiscard]] Transform2D Transform2D::translation(float tx, float ty) noexcept {

    Transform2D translation = Transform2D();
    translation.m[2][0] = tx;
    translation.m[2][1] = ty;
    return translation;
}

[[nodiscard]] Transform2D Transform2D::rotation(float angle_rad) noexcept {
    Transform2D rotation = Transform2D();
    rotation.m[0][0] = cos(angle_rad);
    rotation.m[0][1] = sin(angle_rad);
    rotation.m[1][0] = sin(angle_rad) * -1;
    rotation.m[1][1] = cos(angle_rad);
    return rotation;
}

[[nodiscard]] Transform2D Transform2D::scale(float sx, float sy) noexcept {

    Transform2D scale = Transform2D();
    scale.m[0][0] = sx;
    scale.m[1][1] = sy;
    return scale;
}

[[nodiscard]] Transform2D Transform2D::operator*(const Transform2D& rhs) const noexcept {
    Transform2D result = Transform2D();
    
    for (int i = 0; i < 3; ++i) {
        result.m[i][0] = this->m[i][0] * rhs.m[0][0] + this->m[i][1] * rhs.m[1][0] + this->m[i][2] * rhs.m[2][0];
        result.m[i][1] = this->m[i][0] * rhs.m[0][1] + this->m[i][1] * rhs.m[1][1] + this->m[i][2] * rhs.m[2][1];
        result.m[i][2] = this->m[i][0] * rhs.m[0][2] + this->m[i][1] * rhs.m[1][2] + this->m[i][2] * rhs.m[2][2];
    }

    return result;
}

Transform2D& Transform2D::operator*=(const Transform2D& rhs) noexcept {

    *this = *this * rhs;
    return *this;
}

[[nodiscard]] Vector2D Transform2D::transform_point(const Vector2D& point) const noexcept {
    Vector2D result = Vector2D();

    result.x = point.x * this->m[0][0] + point.y * this->m[1][0] + this->m[2][0];
    result.y = point.x * this->m[0][1] + point.y * this->m[1][1] + this->m[2][1];

    return result;
}

[[nodiscard]] Vector2D Transform2D::transform_vector(const Vector2D& direction) const noexcept {
    Vector2D result = Vector2D();

    result.x = direction.x * this->m[0][0] + direction.y * this->m[1][0];
    result.y = direction.x * this->m[0][1] + direction.y * this->m[1][1];

    return result;
}