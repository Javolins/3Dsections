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

	SUBCASE("operator =="){
		// the same
		Triangle a(Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(1, 1, 0)), Edge(Point(1, 1, 0), Point(0, 0, 0)));
		Triangle a_copy(Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(1, 1, 0)), Edge(Point(1, 1, 0), Point(0, 0, 0)));
		// one common edge
		Triangle a_edge(Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(2, 2, 0)), Edge(Point(2, 2, 0), Point(0, 0, 0)));
		// one common point
		Triangle a_point(Edge(Point(0, 0, 0), Point(0, 0, 1)), Edge(Point(0, 0, 1), Point(0, 1, 1)), Edge(Point(0, 1, 1), Point(0, 0, 0)));
		// no common points
		Triangle b(Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));

		REQUIRE(a == a_copy);
		REQUIRE(!(a == a_edge));
		REQUIRE(!(a == a_point));
		REQUIRE(!(a == b));
	}

	SUBCASE("setEdge()"){
		Triangle b(Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));

		b.setEdgeA();
		b.setEdgeB();
		b.setEdgeC();

		REQUIRE(b.getEdgeA() == Edge(Point(0, 0, 0), Point(0, 0, 0)));
		REQUIRE(b.getEdgeB() == Edge(Point(0, 0, 0), Point(0, 0, 0)));
		REQUIRE(b.getEdgeC() == Edge(Point(0, 0, 0), Point(0, 0, 0)));
	}
}
