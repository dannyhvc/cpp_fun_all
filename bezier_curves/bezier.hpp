#pragma once
#include "types.hpp"
#include <vector>
#include <cmath>

/*
* point related definitions and inline operator code
*/

using related_points = std::vector<std::pair<f32, f32>>;

struct Point_2D
{
    f32 x;
    f32 y;

    Point_2D() = default;
    explicit Point_2D(const f32 _X, const f32 _Y)
        : x(_X), y(_Y) { }
    ~Point_2D() = default;
};

inline Point_2D operator+(Point_2D const& _lhs, Point_2D const& _rhs) noexcept {
    return Point_2D(_lhs.x + _rhs.x, _lhs.y + _rhs.y);
}

inline Point_2D operator-(Point_2D const& _lhs, Point_2D const& _rhs) noexcept {
    return Point_2D(_lhs.x - _rhs.x, _lhs.y - _rhs.y);
}

// Vector2D multiplication
inline Point_2D operator*(Point_2D const& _lhs, Point_2D const& _rhs) noexcept {
    return Point_2D(_lhs.x * _rhs.x, _lhs.y * _rhs.y);
}

// Vector2D Scalar imul
inline Point_2D operator*(f32 const& _lhs, Point_2D const& _rhs) noexcept {
    return Point_2D(_lhs * _rhs.x, _lhs * _rhs.y);
}

inline Point_2D operator*(Point_2D const& _lhs, f32 const& _rhs) noexcept {
    return Point_2D(_lhs.x * _rhs, _lhs.y * _rhs);
}

inline bool operator>(Point_2D const &_lhs, Point_2D const &_rhs)
{
    const bool magnitude_of_lhs_bigger = std::sqrt(_lhs.x * _lhs.x + _lhs.y * _lhs.y) > std::sqrt(_rhs.x * _rhs.x + _rhs.y * _rhs.y);
    //const f32 lhs_angle = f_angle_find(_lhs);
    //const f32 rhs_angle = f_angle_find(_rhs);

    //if (magnitude_of_lhs_bigger && lhs_angle > rhs_angle);

    return true;
}

std::ostream& operator<<(std::ostream os, Point_2D const &_rhs);



/*
*
*/
namespace bezier_detail
{
    // size of angle with respect to nearest right angle
    inline constexpr f32 f_angle_find(Point_2D& point);

    /* makes a vector of points that are taylored to make a bezier curve */
    std::vector<Point_2D> f_bezier_points_create(std::vector<Point_2D>* const& start_points_list);


    inline Point_2D f_bezier_lerp(Point_2D const &P1, Point_2D const &P2, f32 t) noexcept {
        return P1 + t * (P2 - P1);
    }

    // inverse sqrt function
    _NODISCARD constexpr float 
        Q_rsqrt(f32 number) noexcept 
    {
        const float y = std::bit_cast<f32>(
            0x5f3759df - (std::bit_cast<u32>(number) >> 1)
        );
        return y * (1.5f - (number * 0.5f * y * y));
    }
};
