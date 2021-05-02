#pragma once
#include "types.hpp"
#include <vector>
#include <cmath>

inline bool operator>(Point const &_lhs, Point const &_rhs)
{
    const bool magnitude_of_lhs_bigger = std::sqrt(_lhs.x * _lhs.x + _lhs.y * _lhs.y) > std::sqrt(_rhs.x * _rhs.x + _rhs.y * _rhs.y);
    //const f32 lhs_angle = f_angle_find(_lhs);
    //const f32 rhs_angle = f_angle_find(_rhs);

    //if (magnitude_of_lhs_bigger && lhs_angle > rhs_angle);

    return true;
}

std::ostream& operator<<(std::ostream os, Point const &_rhs);

namespace bezier_detail
{
    // size of angle with respect to nearest right angle
    inline constexpr f32 f_angle_find(Point& point);

    /* makes a vector of points that are taylored to make a bezier curve */
    std::vector<Point> f_bezier_points_create(std::vector<Point>* const& start_points_list);


    inline Point f_bezier_lerp(Point const &P1, Point const &P2, f32 t) noexcept {
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
