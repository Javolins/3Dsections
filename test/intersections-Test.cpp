/*****************************************************************//**
 * @file   intersections-Test.h
 * @brief  Unit tests for Plane class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/intersections.h"
#include "../include/Triangle.h"
#include "../include/Ray.h"

TEST_CASE("intersections::edgeWithPlane()"){

	SUBCASE("basic tests"){
		// basic planes
		Plane yOz{ 1 };
		Plane xOy{ 0,0,1 };
		Plane xOz{ 0,1 };

		// simple edges
		Edge z_eq_my_p1{ Point{ 0,1,0 }, Point{ 0,0,1 } };
		Edge y_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,1,0 } };
		Edge z_eq_mx_p1{ Point{ 1,0,0 }, Point{ 0,0,1 } };
		Edge x_eq_y_eq_z{ Point{ 0,0,0 }, Point{ 1,1,1 } };
		// shorter edges
		Edge z_eq_my_p1_short{ Point{ 0,0.25,0.75 }, Point{ 0,0.75,0.25 } };
		Edge y_eq_mx_p1_short{ Point{ 0.25,0.75,0 }, Point{ 0.75,0.25,0 } };
		Edge z_eq_mx_p1_short{ Point{ 0.25,0,0.75 }, Point{ 0.75,0,0.25 } };
		Edge x_eq_y_eq_z_short{ Point{ 1,1,1 }, Point{ 2,2,2 } };


		// yOz intersections with simple edges
		REQUIRE((*intersections::edgeWithPlane(y_eq_mx_p1, yOz) == Point{ 0,1,0 }));
		REQUIRE((*intersections::edgeWithPlane(z_eq_mx_p1, yOz) == Point{ 0,0,1 }));
		REQUIRE((*intersections::edgeWithPlane(x_eq_y_eq_z, yOz) == Point{ 0,0,0 }));
		REQUIRE((intersections::edgeWithPlane(z_eq_my_p1, yOz) == nullptr));
		// yOz intersections with short edges
		REQUIRE((intersections::edgeWithPlane(y_eq_mx_p1_short, yOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(z_eq_mx_p1_short, yOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(x_eq_y_eq_z_short, yOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(z_eq_my_p1_short, yOz) == nullptr));

		// xOy intersections with simple edges
		REQUIRE((*intersections::edgeWithPlane(z_eq_my_p1, xOy) == Point{ 0,1,0 }));
		REQUIRE((*intersections::edgeWithPlane(z_eq_mx_p1, xOy) == Point{ 1,0,0 }));
		REQUIRE((*intersections::edgeWithPlane(x_eq_y_eq_z, xOy) == Point{ 0,0,0 }));
		REQUIRE((intersections::edgeWithPlane(y_eq_mx_p1, xOy) == nullptr));
		// xOy intersections with short edges
		REQUIRE((intersections::edgeWithPlane(z_eq_my_p1_short, xOy) == nullptr));
		REQUIRE((intersections::edgeWithPlane(z_eq_mx_p1_short, xOy) == nullptr));
		REQUIRE((intersections::edgeWithPlane(x_eq_y_eq_z_short, xOy) == nullptr));
		REQUIRE((intersections::edgeWithPlane(y_eq_mx_p1_short, xOy) == nullptr));

		// xOz intersections with simple edges
		REQUIRE((*intersections::edgeWithPlane(z_eq_my_p1, xOz) == Point{ 0,0,1 }));
		REQUIRE((*intersections::edgeWithPlane(y_eq_mx_p1, xOz) == Point{ 1,0,0 }));
		REQUIRE((*intersections::edgeWithPlane(x_eq_y_eq_z, xOz) == Point{ 0,0,0 }));
		REQUIRE((intersections::edgeWithPlane(z_eq_mx_p1, xOz) == nullptr));
		// xOz intersections with short edges
		REQUIRE((intersections::edgeWithPlane(z_eq_my_p1_short, xOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(y_eq_mx_p1_short, xOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(x_eq_y_eq_z_short, xOz) == nullptr));
		REQUIRE((intersections::edgeWithPlane(z_eq_mx_p1_short, xOz) == nullptr));
	}

	SUBCASE("Dividing by 0"){

		Plane z_eq_p0d5{ 0,0,1,-0.5 };
		Plane z_eq_p1d5{ 0,0,1,-1.5 };
		Plane z_eq_p1{ 0,0,1,-1.0 };
		Edge x_eq_y_eq_zero{ Point{ 0,0,0 }, Point{ 0,0,2 } };

		REQUIRE((*intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p0d5) == Point{ 0,0,0.5 }));
		REQUIRE((*intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p1d5) == Point{ 0,0,1.5 }));

		if( REQUIRE((intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p1) != nullptr)) ){

			REQUIRE(intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p1)->getX() == 0);
			REQUIRE(intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p1)->getY() == 0);
			REQUIRE(intersections::edgeWithPlane(x_eq_y_eq_zero, z_eq_p1)->getZ() == 1);
		}
	}

	SUBCASE("Ray testing"){

		Triangle a(Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));
		Triangle b(Edge(Point(0, 0, 0), Point(1, 1, 1)), Edge(Point(1, 1, 1), Point(-2, 3, -4)), Edge(Point(-2, 3, -4), Point(0, 0, 0)));
		Triangle c(Edge(Point(0, 0, 0), Point(1000, 0, 0)), Edge(Point(1000, 0, 0), Point(0, -1, -1)), Edge(Point(0, -1, -1), Point(4, 4, 4)));

		Triangle outA(Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));
		Triangle outB(Edge(Point(-10, -10, -10), Point(-9, -9, -9)), Edge(Point(-9, -9, -9), Point(-12, -13, -14)), Edge(Point(-12, -13, -14), Point(-10, -10, -10)));
		Triangle outC(Edge(Point(0, 0, 0), Point(1000, 0, 0)), Edge(Point(1000, 0, 0), Point(0, -1, -1)), Edge(Point(0, -1, -1), Point(4, 4, 4)));

		// same plane
		Point insideA = a.getPointInside();
		Ray rayA(insideA);
		bool a1 = intersections::edgeWithPlane(rayA, outA.getPlane()) != nullptr && outA.containsPoint((*intersections::edgeWithPlane(rayA, outA.getPlane())));
		REQUIRE(a1);

		// parallel planes
		Point insideB = b.getPointInside();
		Ray rayB(insideB);
		bool b1 = intersections::edgeWithPlane(rayB, outB.getPlane()) != nullptr && outB.containsPoint((*intersections::edgeWithPlane(rayB, outB.getPlane())));
		REQUIRE(!b1);

		// default ray starting point
		Ray rayC(Point{});
		bool c1 = intersections::edgeWithPlane(rayC, outC.getPlane()) != nullptr && outC.containsPoint((*intersections::edgeWithPlane(rayC, outC.getPlane())));
		REQUIRE(!c1);
	}

}

TEST_CASE("intersections::edgeWithEdge()"){
	std::vector<Edge> testEdges;

	// not intersecting
	Edge a1(Point(0, 0, 5), Point(-2, 0, 0));
	Edge b1(Point(0, -2, 0), Point(0, 5, 0), Color(0, 0, 0));
	// common point
	Edge a2(Point(-2, 0, 0), Point(0, 0, 4), Color(0, 0, 0));
	Edge b2(Point(-2, 0, 0), Point(0, -2, 0), Color(0, 0, 0));
	//intersecting
	Edge a3(Point(-2, 0, 0), Point(3, 0, 0), Color(0, 0, 0));
	Edge b3(Point(0, -1, 0), Point(0, 3, 0), Color(0, 0, 0));
	// not intersecting in range
	Edge a4(Point(1, 0, 0), Point(5, 0, 0), Color(0, 0, 0));
	Edge b4(Point(0, 1, 0), Point(0, 5, 0), Color(0, 0, 0));
	// parallel
	Edge a5(Point(1, 0, 0), Point(5, 0, 0), Color(0, 0, 0));
	Edge b5(Point(1, 1, 0), Point(5, 1, 0), Color(0, 0, 0));
	// duplicates
	Edge a6(Point(1, 0, 0), Point(5, 0, 0), Color(0, 0, 0));
	Edge b6(Point(1, 1, 0), Point(5, 1, 0), Color(0, 0, 0));
	// partially the same
	Edge a7(Point(1, 0, 0), Point(5, 0, 0), Color(0, 0, 0));
	Edge b7(Point(3, 0, 0), Point(9, 0, 0), Color(0, 0, 0));


	REQUIRE(intersections::edgeWithEdge(a1, b1) == false);
	REQUIRE(intersections::edgeWithEdge(a2, b2) == false);
	REQUIRE(intersections::edgeWithEdge(a3, b3) == true);
	REQUIRE(intersections::edgeWithEdge(a4, b4) == false);
	REQUIRE(intersections::edgeWithEdge(a5, b5) == false);
	REQUIRE(intersections::edgeWithEdge(a6, b6) == false);
	REQUIRE(intersections::edgeWithEdge(a7, b7) == false);
}
