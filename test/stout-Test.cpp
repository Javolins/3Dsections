/*****************************************************************//**
 * @file   stout-Test.h
 * @brief
 *
 * @author Micha³ Rutkowski @P4ndaM1x Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "doctest.h"
#include "stout.h"
#include "Edge.h"
#include "DataClasses.h"
#include <iostream>
#include "ClosedPolygonalChains.h"

TEST_CASE("intersection() testing") {

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
	//for (auto& e : meshedEdges) {
	//	std::cout << e << std::endl;
	//}

	//TODO add requires
}

TEST_CASE("polygonalChain() testing") {
	std::map<const Edge*, Point> testMap;

	testMap.insert(std::pair<Edge*, Point>(&OriginalEdge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)), Point(1, 1, 0)));
	testMap.insert(std::pair<Edge*, Point>(&OriginalEdge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)), Point(1, -1, 0)));
	testMap.insert(std::pair<Edge*, Point>(&OriginalEdge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)), Point(-1, 1, 0)));
	testMap.insert(std::pair<Edge*, Point>(&OriginalEdge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)), Point(-1, -1, 0)));

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

	for (auto a : testCpc.getEdges()) std::cout << a << std::endl;

	//TODO add requires
}

TEST_CASE("removeReversed() testing") {
	std::vector<Edge> testEdges;

	testEdges.push_back(OriginalEdge(Point(1, 1, 1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-1, -1, -1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(3, 3, 3), Point(-3, -3, -3), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-3, -3, -3), Point(3, 3, 3), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(4, 4, 4), Point(-4, -4, -4), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(5, 5, 5), Point(-5, -5, -5), Color(0, 0, 0)));

	std::vector<Edge> outTest = removeReversed(testEdges);

	//for (auto e : outTest) std::cout << e << std::endl;

	//TODO add requires
}
