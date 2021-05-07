/*
Name: Daniel Herrera
Date: / /
Desc:
*/
#include <iostream>
#include "pch.h"
using std::cout;
using std::endl;

//==================== DEBUG ADAPTER MODE ===================//
#if _DEBUG
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#pragma warning(push)
#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
BOOST_AUTO_TEST_CASE(CASE1)
{
    cout << __TIMESTAMP__ << " <==> D.HERRERA.V 0881570\n" << std::endl;
}//end case1

BOOST_AUTO_TEST_CASE(testing_point_operators)
{
    const Point_2D a{ 10, 4 };
    const Point_2D b{ 3, 14.123f };

    // testing subtraction
    const auto c = b - a;
    // testing addition
    const auto d = b + a;
    // testing mul
    const auto e = b * a;
    // testing scalar mul
    const auto f = 3.0f * a;

    // if outputting is needed
    //cout << "a = Point(" << a.x << ',' << a.y << ')' << endl;
    //cout << "b = Point(" << b.x << ',' << b.y << ')' << endl;
    //cout << "sub = Point(" << c.x << ',' << c.y << ')' << endl;
    //cout << "add = Point(" << d.x << ',' << d.y << ')' << endl;
    //cout << "mul = Point(" << e.x << ',' << e.y << ')' << endl;
    //cout << "mul = Point(" << f.x << ',' << f.y << ')' << endl;
}

BOOST_AUTO_TEST_CASE(testing_range_create)
{
    auto range = Range(1, 10, 1)();
}
#endif // DEBUG

//================ RELEASE MODE OPTIMIZATION =================//
#ifndef _DEBUG
int main(int argv, char** argc)
{
    return EXIT_SUCCESS;
}//end beziercurves
#endif // !_DEBUG