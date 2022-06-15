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
#include "../include/Ray.h"
#include "../include/DataClasses.h"
#include "../include/ClosedPolygonalChains.h"
#include <iostream>
#include <algorithm>

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

	SUBCASE("Ray testing"){

		Triangle a (Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));
		Triangle b (Edge(Point(0, 0, 0), Point(1, 1, 1)), Edge(Point(1, 1, 1), Point(-2, 3, -4)), Edge(Point(-2, 3, -4), Point(0, 0, 0)));
		Triangle c (Edge(Point(0, 0, 0), Point(1000, 0, 0)), Edge(Point(1000, 0, 0), Point(0, -1, -1)), Edge(Point(0, -1, -1), Point(4, 4, 4)));

		Triangle outA (Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));
		Triangle outB (Edge(Point(-10, -10, -10), Point(-9, -9, -9)), Edge(Point(-9,-9,-9), Point(-12,-13,-14)), Edge(Point(-12,-13,-14), Point(-10,-10,-10)));
		Triangle outC(Edge(Point(0, 0, 0), Point(1000, 0, 0)), Edge(Point(1000, 0, 0), Point(0, -1, -1)), Edge(Point(0, -1, -1), Point(4, 4, 4)));

		// ta sama płaszczyzna
		Point insideA = a.getPointInside();
		Ray rayA(insideA);
		bool a1 = intersection(rayA, outA.getPlane()) != nullptr && outA.containsPoint((*intersection(rayA, outA.getPlane())));
		//REQUIRE(!a1);
	
		// 
		Point insideB = b.getPointInside();
		Ray rayB(insideB);
		bool b1 = intersection(rayA, outB.getPlane()) != nullptr && outB.containsPoint((*intersection(rayA, outB.getPlane())));
		//REQUIRE(!b1);

		//
		Ray rayC(Point());
		bool c1 = intersection(rayA, outC.getPlane()) != nullptr && outC.containsPoint((*intersection(rayA, outC.getPlane())));
		//REQUIRE(!c1);
	}

}

TEST_CASE("intersectionPoints() testing") {
	//TODO
}

TEST_CASE("Mesh() testing") {
	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	std::vector<Edge> meshedEdges = triangulate(testEdges);
	//for (auto& e : meshedEdges) std::cout << e << std::endl;

	//TODO add requires
}

TEST_CASE("meshTriangles() testing"){
	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	std::vector<Triangle> meshedEdges = triangulateEdges(testEdges);
	/*std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;
	for( auto& e : meshedEdges ){
		std::cout << "a : " <<  e.getEdgeA() << " ";
		std::cout << "b : " <<  e.getEdgeB() << " ";
		std::cout << "c : " <<  e.getEdgeC() << std::endl;
	}
	std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;*/

	//TODO add requires
}

TEST_CASE("polygonalChain() testing") {
	std::vector<std::pair<const Edge*, Point>> testMap;

	testMap.push_back(std::pair<Edge*, Point>(&Edge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)), Point(1, 1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&Edge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)), Point(1, -1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&Edge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)), Point(-1, 1, 0)));
	testMap.push_back(std::pair<Edge*, Point>(&Edge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)), Point(-1, -1, 0)));

	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	ClosedPolygonalChains testCpc = connectNeighboursSection(testMap, testEdges);

	//for (auto a : testCpc.getEdges()) std::cout << a << std::endl;

	//TODO add requires
}

TEST_CASE("removeReversed() testing") {
	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(3, 3, 3), Point(-3, -3, -3), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-3, -3, -3), Point(3, 3, 3), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(4, 4, 4), Point(-4, -4, -4), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(5, 5, 5), Point(-5, -5, -5), Color(0, 0, 0)));

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

TEST_CASE("triangle == operator testing"){
	// the same
	Triangle a (Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(1, 1, 0)), Edge(Point(1, 1, 0), Point(0, 0, 0)));
	Triangle a_copy (Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(1, 1, 0)), Edge(Point(1, 1, 0), Point(0, 0, 0)));
	// one common edge
	Triangle a_edge (Edge(Point(0, 0, 0), Point(1, 0, 0)), Edge(Point(1, 0, 0), Point(2, 2, 0)), Edge(Point(2, 2, 0), Point(0, 0, 0)));
	// one common point
	Triangle a_point (Edge(Point(0, 0, 0), Point(0, 0, 1)), Edge(Point(0, 0, 1), Point(0, 1, 1)), Edge(Point(0, 1, 1), Point(0, 0, 0)));
	// no common points
	Triangle b (Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));

	REQUIRE(a == a_copy);
	REQUIRE(!(a == a_edge));
	REQUIRE(!(a == a_point));
	REQUIRE(!(a == b));
}

TEST_CASE("testing comparepoints()"){

	std::array<Point, 3> table;

	//
	table = { Point{ 0,0,0 },Point{ 1,0,0 }, Point{ 2,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,0,0 },Point{ 0,1,0 }, Point{ 0,2,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,0 },Point{ 0,0,1 }, Point{ 0,0,2 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 2,0,0 },Point{ 1,0,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,2,0 },Point{ 0,1,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,2 },Point{ 0,0,1 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 1,0,0 },Point{ 2,0,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,1,0 },Point{ 0,2,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,1 },Point{ 0,0,2 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 1,2,3 },Point{ 1,3,2 }, Point{ 1,1,1 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 1,1,1 });
	REQUIRE(table[1] == Point{ 1,2,3 });
	REQUIRE(table[2] == Point{ 1,3,2 });

	table = { Point{ 1,1,1 },Point{ 1,1,3 }, Point{ 1,1,2 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 1,1,1 });
	REQUIRE(table[1] == Point{ 1,1,2 });
	REQUIRE(table[2] == Point{ 1,1,3 });
}

TEST_CASE("triangle setEdge testing") {
	Triangle b(Edge(Point(4, 4, 4), Point(5, 4, 4)), Edge(Point(5, 4, 4), Point(5, 5, 4)), Edge(Point(5, 5, 4), Point(4, 4, 4)));

	b.setEdgeA();
	b.setEdgeB();
	b.setEdgeC();

	REQUIRE(b.getEdgeA() == Edge(Point(0,0,0), Point(0,0,0)));
	REQUIRE(b.getEdgeB() == Edge(Point(0,0,0), Point(0,0,0)));
	REQUIRE(b.getEdgeC() == Edge(Point(0,0,0), Point(0,0,0)));
}

// testing intire pipeline for a cube
TEST_CASE("triangleInsideSection() testing"){

	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, -1, -1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, 1), Point(1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, 1), Point(-1, -1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, 1), Point(-1, 1, 1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, 1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(1, 1, -1), Point(1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(1, -1, -1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(-1, 1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, 1, -1), Point(1, 1, -1), Color(0, 0, 0)));

	std::vector<Triangle> solidTriangles = triangulateEdges(testEdges);
	REQUIRE(solidTriangles.size() == 12);

	Plane yOz{ 1 };
	Plane xOy{ 0,0,1 };
	Plane xOz{ 0,1 };

	std::vector<std::pair<const Edge*, Point>> sectionPoints = intersectionPoints(testEdges, Plane { 0,0,1,-0.044 });
	REQUIRE(sectionPoints.size() == 4);

	std::vector<Triangle> sectionTriangles = triangulateIntersectionPoints(sectionPoints);
	REQUIRE(sectionTriangles.size() == 2);

	int i = 0;
	for( const auto& in : sectionTriangles ){
		Ray ray(in.getPointInside());
		//bool inside = intersection(ray, e.getPlane()) != nullptr && e.containsPoint((*intersection(ray, e.getPlane())));
		std::cout << "Ray start: " << ray.getPoint() << std::endl << std::endl;
		int counter = 0;
		std::vector<Point> intersentions;
		for( auto& out : solidTriangles ){
			//std::cout << "-" << out;
			//std::cout << "-" << out.getPlane() << std::endl;
			if( (intersection(ray, out.getPlane()) != nullptr) && out.containsPoint((*intersection(ray, out.getPlane()))) ){
				if( intersentions.end() == std::find(intersentions.begin(), intersentions.end(), (*intersection(ray, out.getPlane()))) ){

					std::cout << "Found new intersection point: " << (*intersection(ray, out.getPlane())) << " with:" << std::endl;
					std::cout << out << out.getPlane() << std::endl;
					intersentions.push_back((*intersection(ray, out.getPlane())));
					counter++;
				}
			}
		}
			

		bool inside = sectionTriangleInsideSolid(in, solidTriangles);
		MESSAGE("i: ", i++, " count: ", counter);
		//REQUIRE(inside);
	}

}
