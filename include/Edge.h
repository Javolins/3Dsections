/*****************************************************************//**
 * @file   Edge.h
 * @brief  Base class for describing edges of processed solid
 *
 * @author Aleksander Bartoszek, Micha³ Rutkowski
 *********************************************************************/

#pragma once
#include "../include/DataClasses.h"
#include <utility>
#include <array>
#include <iostream>

class Edge {
	public:
		Edge(Point start, Point end, Color rgb = {0,0,0}) : ends(std::pair<Point, Point>(start, end)), color(rgb){}
		Point getStart() const { return ends.first; }
		Point getEnd() const { return ends.second; }
		Color getRgb() const { return color; }
		std::array<double, 3> getDirectionalVector() const { 
			return std::array<double, 3>{
				static_cast<double>(getEnd().getX() - getStart().getX()),
				static_cast<double>(getEnd().getY() - getStart().getY()),
				static_cast<double>(getEnd().getZ() - getStart().getZ())
			};
		}
		bool operator==(const Edge& e) { if (this != nullptr && getStart() == e.getStart() && getEnd() == e.getEnd()) return true; else return false; };
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
	private:
		std::pair<Point, Point>	ends;
		Color color;
};

struct compareEdges {
	bool operator()(const Edge& a, const Edge& b) const{
		if (b.getStart().getX() < a.getStart().getX()) return false;
		if (a.getStart().getX() < b.getStart().getX()) return true;

		if (b.getStart().getY() < a.getStart().getY()) return false;
		if (a.getStart().getY() < b.getStart().getY()) return true;

		if (b.getStart().getZ() < a.getStart().getZ()) return false;
		if (a.getStart().getZ() < b.getStart().getZ()) return true;

		if (b.getEnd().getX() < a.getEnd().getX()) return false;
		if (a.getEnd().getX() < b.getEnd().getX()) return true;

		if (b.getEnd().getY() < a.getEnd().getY()) return false;
		if (a.getEnd().getY() < b.getEnd().getY()) return true;

		if (b.getEnd().getZ() < a.getEnd().getZ()) return false;
		if (a.getEnd().getZ() < b.getEnd().getZ()) return true;
		return false;
	}
};

inline std::ostream& operator << (std::ostream& os, const Edge& e) {
	os << e.getStart() << " ";
	os << e.getEnd() << " ";
	os << e.getRgb() << std::endl;
	return os;
}
