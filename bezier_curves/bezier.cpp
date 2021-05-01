#include <iostream>
#include "bezier.hpp"

void operator "" _print(const char* str)
{
    std::cout << str << '\n';
}

std::vector<Point> bezier_detail::f_bezier_create(std::vector<Point> const& points_list, u32 const stride)
{
    return std::vector<Point>();
}