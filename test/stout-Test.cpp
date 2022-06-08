/*****************************************************************//**
 * @file   stout-Test.h
 * @brief
 *
 * @author Michał Rutkowski @P4ndaM1x Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/stout.h"
#include "../include/Edge.h"
#include "../include/DataClasses.h"
#include <iostream>
#include "../include/ClosedPolygonalChains.h"

TEST_CASE("intersection() testing") {

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
		REQUIRE((*intersection(y_eq_mx_p1, yOz) == Point{ 0,1,0 }));
		REQUIRE((*intersection(z_eq_mx_p1, yOz) == Point{ 0,0,1 }));
		REQUIRE((*intersection(x_eq_y_eq_z, yOz) == Point{ 0,0,0 }));
		REQUIRE((intersection(z_eq_my_p1, yOz) == nullptr));
		// yOz intersections with short edges
		REQUIRE((intersection(y_eq_mx_p1_short, yOz) == nullptr));
		REQUIRE((intersection(z_eq_mx_p1_short, yOz) == nullptr));
		REQUIRE((intersection(x_eq_y_eq_z_short, yOz) == nullptr));
		REQUIRE((intersection(z_eq_my_p1_short, yOz) == nullptr));

		// xOy intersections with simple edges
		REQUIRE((*intersection(z_eq_my_p1, xOy) == Point{ 0,1,0 }));
		REQUIRE((*intersection(z_eq_mx_p1, xOy) == Point{ 1,0,0 }));
		REQUIRE((*intersection(x_eq_y_eq_z, xOy) == Point{ 0,0,0 }));
		REQUIRE((intersection(y_eq_mx_p1, xOy) == nullptr));
		// xOy intersections with short edges
		REQUIRE((intersection(z_eq_my_p1_short, xOy) == nullptr));
		REQUIRE((intersection(z_eq_mx_p1_short, xOy) == nullptr));
		REQUIRE((intersection(x_eq_y_eq_z_short, xOy) == nullptr));
		REQUIRE((intersection(y_eq_mx_p1_short, xOy) == nullptr));

		// xOz intersections with simple edges
		REQUIRE((*intersection(z_eq_my_p1, xOz) == Point{ 0,0,1 }));
		REQUIRE((*intersection(y_eq_mx_p1, xOz) == Point{ 1,0,0 }));
		REQUIRE((*intersection(x_eq_y_eq_z, xOz) == Point{ 0,0,0 }));
		REQUIRE((intersection(z_eq_mx_p1, xOz) == nullptr));
		// xOz intersections with short edges
		REQUIRE((intersection(z_eq_my_p1_short, xOz) == nullptr));
		REQUIRE((intersection(y_eq_mx_p1_short, xOz) == nullptr));
		REQUIRE((intersection(x_eq_y_eq_z_short, xOz) == nullptr));
		REQUIRE((intersection(z_eq_mx_p1_short, xOz) == nullptr));
	}

	SUBCASE("strange bug, D = -1"){

		Plane z_eq_p0d5{ 0,0,1,-0.5 };
		Plane z_eq_p1d5{ 0,0,1,-1.5 };
		Plane z_eq_p1{ 0,0,1,-1.0 };
		Edge x_eq_y_eq_zero{ Point{ 0,0,0 }, Point{ 0,0,2 } };

		REQUIRE((*intersection(x_eq_y_eq_zero, z_eq_p0d5) == Point{ 0,0,0.5 }));
		REQUIRE((*intersection(x_eq_y_eq_zero, z_eq_p1d5) == Point{ 0,0,1.5 }));

		if( REQUIRE((intersection(x_eq_y_eq_zero, z_eq_p1) != nullptr)) ){

			REQUIRE(intersection(x_eq_y_eq_zero, z_eq_p1)->getX() == 0);
			REQUIRE(intersection(x_eq_y_eq_zero, z_eq_p1)->getY() == 0);
			REQUIRE(intersection(x_eq_y_eq_zero, z_eq_p1)->getZ() == 1);
		}
		//REQUIRE((*intersection(x_eq_y_eq_zero, z_eq_p1) == Point{ 0,0,1.0 }));
	}

}

TEST_CASE("intersectionPoints() testing") {
	//TODO
}

TEST_CASE("Mesh() testing") {
	std::vector<OriginalEdge> testEdges;

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	std::vector<Edge> meshedEdges = mesh(testEdges);
	//for (auto& e : meshedEdges) std::cout << e << std::endl;

	//TODO add requires
}

TEST_CASE("meshTriangles() testing"){
	std::vector<OriginalEdge> testEdges;

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	std::vector<Triangle> meshedEdges = meshTriangles(testEdges);
	std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;
	for( auto& e : meshedEdges ){
		std::cout << "a : " <<  e.getEdgeA() << " ";
		std::cout << "b : " <<  e.getEdgeB() << " ";
		std::cout << "c : " <<  e.getEdgeC() << std::endl;
	}
	std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;

	//TODO add requires
}

TEST_CASE("polygonalChain() testing") {
	std::vector<std::pair<const Edge*, Point>> testMap;

	testMap.push_back(std::pair<Edge*, Point>(&OriginalEdge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)), Point(1, 1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&OriginalEdge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)), Point(1, -1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&OriginalEdge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)), Point(-1, 1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&OriginalEdge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)), Point(-1, -1, 0)));

	std::vector<OriginalEdge> testEdges;

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	ClosedPolygonalChains testCpc = polygonalChain(testMap, testEdges);

	//for (auto a : testCpc.getEdges()) std::cout << a << std::endl;

	//TODO add requires
}

TEST_CASE("removeReversed() testing") {
	std::vector<Edge> testEdges;

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, -1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(3, 3, 3), Point(-3, -3, -3), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-3, -3, -3), Point(3, 3, 3), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(4, 4, 4), Point(-4, -4, -4), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(5, 5, 5), Point(-5, -5, -5), Color(0, 0, 0)));

	std::vector<Edge> outTest = removeReversed(testEdges);

	//for (auto e : outTest) std::cout << e << std::endl;

	//TODO add requires
}

TEST_CASE("areIntersecting() testing"){
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


	REQUIRE(areIntersecting(a1, b1) == false);
	REQUIRE(areIntersecting(a2, b2) == false);
	REQUIRE(areIntersecting(a3, b3) == true);
	REQUIRE(areIntersecting(a4, b4) == false);
	REQUIRE(areIntersecting(a5, b5) == false);
	REQUIRE(areIntersecting(a6, b6) == false);
	REQUIRE(areIntersecting(a7, b7) == false); //??
}

TEST_CASE("sortowanie"){

	//Triangle t(
	//	Edge(Point(-2, 0, 0), Point(0, 0, 4)),
	//	Edge(Point(-2, 0, 0), Point(0, -2, 0)),
	//	Edge(Point(0, -2, 0), Point(0, 0, 4 ))
	//	);

	//std::array<Point, 3> points{ t.getPointA(), t.getPointB(), t.getPointC() };

	//std::sort(points.begin(), points.end(), comparePoints());

	//std::string toHash =
	//	std::to_string(points[0].getX()) +
	//	std::to_string(points[0].getY()) +
	//	std::to_string(points[0].getZ()) +
	//	std::to_string(points[1].getX()) +
	//	std::to_string(points[1].getY()) +
	//	std::to_string(points[1].getZ()) +
	//	std::to_string(points[2].getX()) +
	//	std::to_string(points[2].getY()) +
	//	std::to_string(points[2].getZ());

	//for( auto e : points ){
	//	std::cout << e << std::endl;
	//}

	//size_t number = std::hash<std::string>()(toHash);

	//std::cout << toHash << std::endl;
	//std::cout << number << std::endl;
}
