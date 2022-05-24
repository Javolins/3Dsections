/*****************************************************************//**
 * @file   stout.h
 * @brief  small lib for algorithms used during calculating sections
 *
 * @author Micha³ Rutkowski, Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <array>
#include <set>
#include <utility>
#include <memory>
#include "OriginalEdge.h"
#include "Plane.h"

/**
 * Robi mi siê niedobrze od z³o¿onoœci tej funkcji, ale wmawiam sobie ¿e to tymczasowe.
 */
// zakomentowa³em, bo powodowa³a problemy przy kompilacji
/*std::vector<Edge> mesh(std::vector<OriginalEdge> origin) {
	
	std::set<Point> uniquePoints;
	for (auto a : origin) {
		uniquePoints.insert(a.getStart());
		uniquePoints.insert(a.getEnd());
	}

	std::pair<OriginalEdge, OriginalEdge> pair();
	//TODO
};*/

/**
 * @brief Calculates the intersection point of @ref line and @ref plane
 * 
 * @param line Segment of the line used in an algorithm.
 * @param plane Plane used in an algorithm.
 * @return If there is exactly one point of itersection it will be returned, in other case - nullptr.
 */
std::unique_ptr<Point> intersection(const Edge& line, const Plane& plane) {

	std::array<double, 3> lineVec = line.getDirectionalVector();
	std::array<double, 3> planeVec = plane.getNormalVector();

	// checking if there is exactly one point of itersection - possible numeric problems
	double dotProduct = lineVec[0]*planeVec[0] + lineVec[1]*planeVec[1] + lineVec[2]*planeVec[2];
	if (dotProduct == 0.0)
		return nullptr;

	Point point = line.getStart();
	double t = -(plane.getA() * point.getX() + plane.getB() * point.getY() + plane.getC() * point.getZ() + plane.getD())
		/ (plane.getA() * lineVec[0] + plane.getB() * lineVec[1] + plane.getC() * lineVec[2]);

	return std::unique_ptr<Point>(
		new Point{
			static_cast<float>(point.getX() + t * lineVec[0]),
			static_cast<float>(point.getY() + t * lineVec[1]),
			static_cast<float>(point.getZ() + t * lineVec[2])
		}
	);
}
