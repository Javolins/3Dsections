/*****************************************************************//**
 * @file   stout-Test.h
 * @brief  Unit tests for Plane class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/stout.h"
#include <iostream>
#include <algorithm>


TEST_CASE("stout::triangulate()") {
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

	std::vector<Edge> meshedEdges = stout::triangulate(testEdges);
	//for (auto& e : meshedEdges) std::cout << e << std::endl;
}

TEST_CASE("stout::triangulateEdges()"){
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

	std::vector<Triangle> meshedEdges = stout::triangulateEdges(testEdges);
	/*std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;
	for( auto& e : meshedEdges ){
		std::cout << "a : " <<  e.getEdgeA() << " ";
		std::cout << "b : " <<  e.getEdgeB() << " ";
		std::cout << "c : " <<  e.getEdgeC() << std::endl;
	}
	std::cout << "meshedEdges.size(): " << meshedEdges.size() << std::endl;*/
}

TEST_CASE("stout::connectNeighboursSection()") {
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

	ClosedPolygonalChains testCpc = stout::connectNeighboursSection(testMap, testEdges);

	//for (auto a : testCpc.getEdges()) std::cout << a << std::endl;
}

TEST_CASE("stout::removeReversed()") {
	std::vector<Edge> testEdges;

	testEdges.push_back(Edge(Point(1, 1, 1), Point(-1, -1, -1), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-1, -1, -1), Point(1, 1, 1), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(2, 2, 2), Point(-2, -2, -2), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(3, 3, 3), Point(-3, -3, -3), Color(0, 0, 0)));
	testEdges.push_back(Edge(Point(-3, -3, -3), Point(3, 3, 3), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(4, 4, 4), Point(-4, -4, -4), Color(0, 0, 0)));

	testEdges.push_back(Edge(Point(5, 5, 5), Point(-5, -5, -5), Color(0, 0, 0)));

	std::vector<Edge> outTest = stout::removeReversed(testEdges);

	//for (auto e : outTest) std::cout << e << std::endl;
}
