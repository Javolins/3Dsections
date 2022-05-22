#pragma once
/*****************************************************************//**
 * @file   Edge.h
 * @brief  Base class for describing edges of processed solid
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#include "DataClasses.h"
#include <utility>
#include <array>

class Edge {
	public:
		Edge(Point start, Point end, Rgb rgb): ends(std::pair<Point, Point>(start, end)), color(rgb) {
			directionalVector[0] = end.getX() - start.getX();
			directionalVector[1] = end.getY() - start.getY();
			directionalVector[2] = end.getZ() - start.getZ();
		};
		Point getStart() { return ends.first; };
		Point getEnd() { return ends.second; };
		Rgb getRgb() { return color; };
		std::array<double, 3> getDirVec() { return directionalVector; };
	private:
		std::pair<Point, Point>	ends;
		std::array<double, 3> directionalVector;
		Rgb color;
};

