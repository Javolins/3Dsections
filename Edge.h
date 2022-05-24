/*****************************************************************//**
 * @file   Edge.h
 * @brief  Base class for describing edges of processed solid
 *
 * @author Aleksander Bartoszek, Micha³ Rutkowski
 *********************************************************************/

#pragma once
#include "DataClasses.h"
#include <utility>
#include <array>

class Edge {
	public:
		Edge(Point start, Point end, Rgb rgb): ends(std::pair<Point, Point>(start, end)), color(rgb) {}
		Point getStart() const { return ends.first; }
		Point getEnd() const { return ends.second; }
		Rgb getRgb() const { return color; }
		std::array<double, 3> getDirectionalVector() const { 
			return std::array<double, 3>{
				static_cast<double>(getEnd().getX() - getStart().getX()),
				static_cast<double>(getEnd().getY() - getStart().getY()),
				static_cast<double>(getEnd().getZ() - getStart().getZ())
			};
		}
	private:
		std::pair<Point, Point>	ends;
		Rgb color;
};