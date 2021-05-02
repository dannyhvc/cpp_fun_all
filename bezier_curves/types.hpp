#pragma once
#include <cstdint>
#include <utility>
#include <vector>

// unsigned integral types
using u8 = std::uint_fast8_t;
using u16 = std::uint_fast16_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;

// integral types
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

// floating point types
using f32 = float;
using f64 = double;
using f96 = long double;

using related_points = std::vector<std::pair<f32, f32>>;

struct Point 
{
    f32 x;
    f32 y;

    Point() = default;
    explicit Point(const f32 _X, const f32 _Y)
        : x(_X), y(_Y) { }    
    ~Point() = default;
};

inline Point operator+(Point const& _lhs, Point const& _rhs) noexcept {
    return Point(_lhs.x + _rhs.x, _lhs.y + _rhs.y);
}

inline Point operator-(Point const& _lhs, Point const& _rhs) noexcept {
    return Point(_lhs.x - _rhs.x, _lhs.y - _rhs.y);
}

// Vector2D multiplication
inline Point operator*(Point const& _lhs, Point const& _rhs) noexcept {
    return Point(_lhs.x * _rhs.x, _lhs.y * _rhs.y);
}

// Vector2D Scalar imul
inline Point operator*(f32 const& _lhs, Point const& _rhs) noexcept {
    return Point(_lhs * _rhs.x, _lhs * _rhs.y);
}

inline Point operator*(Point const& _lhs, f32 const& _rhs) noexcept {
    return Point(_lhs.x * _rhs, _lhs.y * _rhs);
}
