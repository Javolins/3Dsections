/*****************************************************************//**
 * @file   Edge.h
 * @brief  Base class for describing edges of processed solid
 *
 * @author Aleksander Bartoszek, Michał Rutkowski
 *********************************************************************/

#pragma once
#include "../include/DataClasses.h"
#include <utility>
#include <array>
#include <iostream>

/**
 * @brief Class storing two points and color of the line connecting them.
 */
class Edge {
	public:
		Edge(Point start = {0,0,0}, Point end = {0,0,0}, Color rgb = {0,0,0}) : ends(std::pair<Point, Point>(start, end)), color(rgb){ }
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
		bool operator==(const Edge& e) const { 
			if (this != nullptr && ((getStart() == e.getStart() && getEnd() == e.getEnd()) || (getStart() == e.getEnd() && getEnd() == e.getStart()))) 
				return true; 
			else 
				return false; 
		};
		void set(Point a, Point b){
			ends.first = a; 
			ends.second = b;
		}
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
	private:
		std::pair<Point, Point>	ends;
		Color color;
};

/**
 * @brief struct for comparing Edges in algorithms
 */
struct compareEdges {
	bool operator()(const Edge& a, const Edge& b) const{

		if((a.getStart() == b.getStart() || a.getStart() == b.getEnd()) && (a.getEnd() == b.getStart() || a.getEnd() == b.getEnd()))
			return false;

		return true;
	}
};

inline std::ostream& operator << (std::ostream& os, const Edge& e) {
	os << e.getStart() << " ";
	os << e.getEnd() << " ";
	os << e.getRgb() << std::endl;
	return os;
}
