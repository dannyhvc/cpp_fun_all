/*
Name: Daniel Herrera
Date: / /
Desc:
*/
#include <iostream>
#include "bezier.hpp"

//==================== DEBUG ADAPTER MODE ===================//
#if _DEBUG
#define BOOST_TEST_MODULE myTests
#include <boost/test/unit_test.hpp>
#pragma warning(push)
#pragma warning(disable : 26812)
#pragma warning(disable : 26495)
BOOST_AUTO_TEST_CASE(CASE1)
{
    std::cout << __TIMESTAMP__ << " <==> D.HERRERA.V 0881570\n" << std::endl;
}//end case1

BOOST_AUTO_TEST_CASE(testing_point_operators)
{
    const Point_2D x{ 3,4 };
    const Point_2D y{ 3,4 };
    operator<<(std::cout, x + y);
}
#endif // DEBUG

//================ RELEASE MODE OPTIMIZATION =================//
#ifndef _DEBUG
int main(int argv, char** argc)
{
    return EXIT_SUCCESS;
}//end beziercurves
#endif // !_DEBUG