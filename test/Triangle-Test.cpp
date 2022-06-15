/*****************************************************************//**
 * @file   Triangle-Test.cpp
 * @brief  Unit tests for Triangle class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Triangle.h"

TEST_CASE("Triangle"){

	Edge z_eq_my_p1{ Point{ 0,1,0 }, Point{ 0,0,1 } };
	Edge y_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,1,0 } };
	Edge z_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,0,1 } };

	SUBCASE("Made from Edges"){
		Triangle test{ z_eq_my_p1, y_eq_mx_p1, z_eq_mx_p1 };
		//MESSAGE("A: ", test.getA(), ", B: ", test.getB(), ", C: ", test.getC(), ", D: ", test.getD());
		REQUIRE(test.getA() == -1);
		REQUIRE(test.getB() == -1);
		REQUIRE(test.getC() == -1);
		REQUIRE(test.getD() == 1);
		REQUIRE(test.getArea() == sqrt(3)/2);
		REQUIRE(test.containsPoint(Point{ 0,1,0 }));
		REQUIRE(test.containsPoint(Point{ 0,0,1 }));
		REQUIRE(test.containsPoint(Point{ 1,0,0 }));
	}
	
	SUBCASE("Made from points"){
		Triangle test{ Edge{Point{ 0,0,0 },Point{ 0,2,0 }}, Edge{Point{ 0,0,0 },Point{ 2,0,0 }}, Edge{Point{ 2,0,0 },Point{ 0,2,0 }} };
		//MESSAGE("A: ", test.getA(), ", B: ", test.getB(), ", C: ", test.getC(), ", D: ", test.getD());
		REQUIRE(test.getArea() == 2);
		REQUIRE(test.containsPoint(Point{ 0,0,0 }));
		REQUIRE(test.containsPoint(Point{ 0,2,0 }));
		REQUIRE(test.containsPoint(Point{ 2,0,0 }));
		REQUIRE(test.containsPoint(Point{ 1,1,0 }));

		REQUIRE(test.containsPoint(Point{ 0.6,0.6,0 }));

		REQUIRE(test.containsPoint(Point{ 2.1,0,0 }) == false);
		REQUIRE(test.containsPoint(Point{ 0,2.1,0 }) == false);
		REQUIRE(test.containsPoint(Point{ 1.5,1.5,0 }) == false);
		REQUIRE(test.containsPoint(Point{ 1,1,1 }) == false);
	}
}
