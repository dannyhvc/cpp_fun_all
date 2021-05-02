/**
* for any given set of points P there is a function F, where F ∩ P exists for degree of size |P| - 1.
* meaning that for any parametric linear equation there is 2 points that satisfy the line and thus meaning that for any parametic function
* there is a set of points that satisfy the degree as the amount of points - 1.
*/
#include <iostream>
#include "bezier.hpp"
#include <algorithm>
#include <memory>
#include <ostream>

std::vector<Point_2D> 
    bezier_detail::f_bezier_points_create(std::vector<Point_2D>* const &start_points_list)
{
	std::shared_ptr<std::vector<Point_2D>> bezier_curve_vec {new std::vector<Point_2D>()};
	//for (size_t i = 0; i < start_points_list->size(); i++)
	//{

	//}
	return *bezier_curve_vec;
}

std::ostream& operator<<(std::ostream out, Point_2D const& _rhs) {
	out << "Point(" << _rhs.x << ',' << _rhs.y << ")";
	return out;
}
