#pragma once
#include "types.hpp"
#include <vector>

namespace bezier_detail
{
    /* makes a vector of points that are taylored to make a bezier curve */
    std::vector<Point>
        f_bezier_create(std::vector<Point> const& points_list, u32 const stride);
};