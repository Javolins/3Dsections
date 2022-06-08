/*****************************************************************//**
 * @file   Plane-Test.cpp
 * @brief  Plane testing
 *
 * @author Michał Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Plane.h"
#include "../include/Triangle.h"

TEST_CASE("Plane testing") {

	// default constructor testing
	Plane test = Plane();

	// get() testing
	for (int i = 0; i < 4; i++)
		REQUIRE(test.getParameter(i) == 0.0);

	// set() testing
	for (int i = 0; i < 4; i++) {
		test.setParameter(i, i + 0.1);
		REQUIRE(test.getParameter(i) == i + 0.1);
	}

	// set and get for A B C D
	test.setA(21.37);
	test.setB(21.37);
	test.setC(21.37);
	test.setD(21.37);
	REQUIRE(test.getA() == 21.37);
	REQUIRE(test.getB() == 21.37);
	REQUIRE(test.getC() == 21.37);
	REQUIRE(test.getD() == 21.37);
	test.set(42.0, 42.0, 42.0, 42.0);
	REQUIRE(test.getA() == 42.0);
	REQUIRE(test.getB() == 42.0);
	REQUIRE(test.getC() == 42.0);
	REQUIRE(test.getD() == 42.0);

	// getNormalVector() testing
	test.set(1.0, 2.0, 3.0, 4.0);
	std::array<double, 3> vec = test.getNormalVector();
	REQUIRE(vec[0] == 1.0);
	REQUIRE(vec[1] == 2.0);
	REQUIRE(vec[2] == 3.0);
}

TEST_CASE("Triangle testing"){

	Edge z_eq_my_p1{ Point{ 0,1,0 }, Point{ 0,0,1 } };
	Edge y_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,1,0 } };
	Edge z_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,0,1 } };

	Triangle test{ z_eq_my_p1, y_eq_mx_p1, z_eq_mx_p1 };
	MESSAGE("A: ", test.getA(), ", B: ", test.getB(), ", C: ", test.getC(), ", D: ", test.getD());
	REQUIRE(test.getA() == -1);
	REQUIRE(test.getB() == -1);
	REQUIRE(test.getC() == -1);
	REQUIRE(test.getD() == 1);
	REQUIRE(test.getArea() == sqrt(3)/2);
	REQUIRE(test.containsPoint(Point{ 0,1,0 }));
	REQUIRE(test.containsPoint(Point{ 0,0,1 }));
	REQUIRE(test.containsPoint(Point{ 1,0,0 }));

	Triangle test2{ Edge{Point{ 0,0,0 },Point{ 0,2,0 }}, Edge{Point{ 0,0,0 },Point{ 2,0,0 }}, Edge{Point{ 2,0,0 },Point{ 0,2,0 }} };
	MESSAGE("A: ", test2.getA(), ", B: ", test2.getB(), ", C: ", test2.getC(), ", D: ", test2.getD());
	REQUIRE(test2.getArea() == 2);
	REQUIRE(test2.containsPoint(Point{ 0,0,0 }));
	REQUIRE(test2.containsPoint(Point{ 0,2,0 }));
	REQUIRE(test2.containsPoint(Point{ 2,0,0 }));
	REQUIRE(test2.containsPoint(Point{ 1,1,0 }));

	REQUIRE(test2.containsPoint(Point{ 0.6,0.6,0 }));

	REQUIRE(test2.containsPoint(Point{ 2.1,0,0 }) == false);
	REQUIRE(test2.containsPoint(Point{ 0,2.1,0 }) == false);
	REQUIRE(test2.containsPoint(Point{ 1.5,1.5,0 }) == false);
	REQUIRE(test2.containsPoint(Point{ 1,1,1 }) == false);
}
