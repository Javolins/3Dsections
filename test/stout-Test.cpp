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


	SUBCASE("strange bug, D = -1"){

		Plane z_eq_p0d5{ 0,0,1,-0.5 };
		Plane z_eq_p1d5{ 0,0,1,-1.5 };
		Plane z_eq_p1{ 0,0,1,-1.0 };
		Edge x_eq_y_eq_zero{ Point{ 0,0,0 }, Point{ 0,0,2 } };

		REQUIRE((*intersection(x_eq_y_eq_zero, z_eq_p0d5) == Point{ 0,0,0.5 }));
		REQUIRE((*intersection(x_eq_y_eq_zero, z_eq_p1d5) == Point{ 0,0,1.5 }));

		if( REQUIRE((intersection(z_eq_mx_p1_short, xOz) != nullptr)) ){

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
	//for (auto& e : meshedEdges) {
	//	std::cout << e << std::endl;
	//}

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

	testEdges.push_back(OriginalEdge(Point(3, 3, 3), Point(-3, -3, -3), Color(0, 0, 0)));
	testEdges.push_back(OriginalEdge(Point(-3, -3, -3), Point(3, 3, 3), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(4, 4, 4), Point(-4, -4, -4), Color(0, 0, 0)));

	testEdges.push_back(OriginalEdge(Point(5, 5, 5), Point(-5, -5, -5), Color(0, 0, 0)));

	std::vector<Edge> outTest = removeReversed(testEdges);

	//for (auto e : outTest) std::cout << e << std::endl;

	//TODO add requires
}
