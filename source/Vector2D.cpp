#include "Vector2D.hpp"
#include <assert.h>

[[nodiscard]] Vector2D Vector2D::normalized() const {

    float current_length = length();
    assert(current_length > 0);
    return Vector2D(x, y) / current_length;
}

void Vector2D::normalize() {

    float current_length = length();
    assert(current_length > 0);
    x = x / current_length;
    y = y / current_length;
}

[[nodiscard]] Vector2D Vector2D::operator+(const Vector2D& rhs) const noexcept {

    return Vector2D(x + rhs.x, y + rhs.y);
}

[[nodiscard]] Vector2D Vector2D::operator-(const Vector2D& rhs) const noexcept {

    return Vector2D(x - rhs.x, y - rhs.y);
}

[[nodiscard]] Vector2D Vector2D::operator*(float scalar) const noexcept  {
    return Vector2D(x * scalar, y * scalar);
}


[[nodiscard]] Vector2D Vector2D::operator/(float scalar) const noexcept {

    assert(scalar != 0);
    return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) noexcept {

}

Vector2D& Vector2D::operator-=(const Vector2D& rhs) noexcept {

}

Vector2D& Vector2D::operator*=(float scalar) noexcept {

}

// @pre std::abs(scalar) > EPSILON.
Vector2D& Vector2D::operator/=(float scalar) {

    assert(scalar != 0);
    x = x / scalar;
    y = y / scalar;
   //return &Vector2D(x, y);
}

[[nodiscard]] Vector2D operator*(float scalar, const Vector2D& vec) noexcept {
    return Vector2D(vec.x * scalar, vec.y * scalar);
}