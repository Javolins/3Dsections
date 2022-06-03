/*****************************************************************//**
 * @file   stout.h
 * @brief  small lib for algorithms used during calculating sections
 *
 * @author Michał Rutkowski, Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <array>
#include <set>
#include <map>
#include <memory>
#include <cmath>
#include <omp.h>
#include "../include/OriginalEdge.h"
#include "../include/MeshEdge.h"
#include "../include/Edge.h"
#include "../include/Plane.h"
#include "../include/ClosedPolygonalChains.h"


/**
 * .@brief function triangulating given solid for processing
 * 
 * @param origin vector of edges from the file
 * @return vector of all original and virtual edges
 * 
 * //TODO proper color of new Edge
 */
inline std::vector<Edge> mesh(std::vector<OriginalEdge>& origin) {
	std::set<Point, comparePoints> uniquePoints;
	for (const auto& a : origin) {
		uniquePoints.insert(a.getStart());
		uniquePoints.insert(a.getEnd());
	}
	std::set<Edge, compareEdges> allEdges;

	//foreach point
	for (const auto& p : uniquePoints) {
		//filter appropriate edges
		std::vector<Edge> temp;
		for (auto& e : origin) {
			if (e.getStart() == p || e.getEnd() == p) {
				temp.push_back(e);
			}
		}
		//foreach pair of edges
		for (auto& x : temp) {
			for (const auto& y : temp) {
				if (!(x == y)) {
					//find 3 edge to form triangle
					//add edges
					if (x.getStart() == p && y.getStart() == p)		allEdges.insert(MeshEdge(x.getEnd(), y.getEnd(), Color(0,0,0)));
					else if (x.getStart() == p && y.getEnd() == p)	allEdges.insert(MeshEdge(x.getEnd(), y.getStart(), Color(0, 0, 0)));
					else if (x.getEnd() == p && y.getStart() == p)	allEdges.insert(MeshEdge(x.getStart(), y.getEnd(), Color(0, 0, 0)));
					else if (x.getEnd() == p && y.getEnd() == p)	allEdges.insert(MeshEdge(x.getStart(), y.getStart(), Color(0, 0, 0)));
					// else throw new Exception :P
				}
			}
		}
	}
	std::vector<Edge> out(allEdges.begin(), allEdges.end());
	return out;
};

/**
 * @brief Calculates the dot product of two vectors.
 * 
 * @param a First 3-dimensional vector.
 * @param b Second 3-dimensional vector.
 * @return Dot product of provided vectors.
 */
inline double dot(std::array<double, 3> a, std::array<double, 3> b){
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

/**
 * @brief Calculates the norm of a vector.
 * 
 * @param vec 3-dimensional vector.
 * @return Norm of the provided vector.
 */
inline double norm(std::array<double, 3> vec){
	return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}

/**
 * @brief Simple signum function.
 * 
 * @param val Checked value.
 * @return 1 if @ref val is positive, -1 if @ref val is negative, 0 if @ref val is a zero
 */
inline int sgn(double val){
	return (val>0) - (val<0);
}

/**
 * @brief Calculates the intersection point of @ref line and @ref plane
 * 
 * @param line Segment of the line used in an algorithm.
 * @param plane Plane used in an algorithm.
 * @return If there is exactly one point of itersection it will be returned, in other case - nullptr.
 */
inline std::unique_ptr<Point> intersection(const Edge& line, const Plane& plane){

	Point start = line.getStart();
	Point end = line.getEnd();

	std::array<double, 3> startVec{ start.getX(), start.getY(), start.getZ() };
	std::array<double, 3> endVec{ end.getX(), end.getY(), end.getZ() };
	std::array<double, 3> planeVec = plane.getNormalVector();

	// check if edge intersects plane
	if( sgn(dot(startVec, planeVec)) == sgn(dot(endVec, planeVec)) ) 
		return nullptr;

	std::array<double, 3> lineVec = line.getDirectionalVector();

	double t = -(plane.getA() * start.getX() + plane.getB() * start.getY() + plane.getC() * start.getZ() + plane.getD())
		/ (plane.getA() * lineVec[0] + plane.getB() * lineVec[1] + plane.getC() * lineVec[2]);

	return std::unique_ptr<Point>{
		new Point{
			static_cast<float>(start.getX() + t * lineVec[0]),
			static_cast<float>(start.getY() + t * lineVec[1]),
			static_cast<float>(start.getZ() + t * lineVec[2])
		}
	};
}

/**
 * @brief DO TESTÓW!!!
 * 
 * @param originalEdges
 * @param plane
 * @return 
 */
 inline std::vector<std::pair<const Edge*, Point>> intersectionPoints(const std::vector<OriginalEdge>& originalEdges, const Plane& plane){
	
	 std::vector<std::pair<const Edge*, Point>> intersections;
	for( auto& edge : originalEdges ){
		std::unique_ptr<Point> ptr{ intersection(edge, plane) };
		if( ptr != nullptr )
			intersections.push_back({ &edge, *ptr });
	}
	return intersections;
}


 /**
  * @brief Functions checking which intersections with a plane would create a section
  * 
  * @param intersections - map of intersections with appropriate point of intersection and edge intersecting
  * @param origin - original edges from file
  * @return polygonal chain to be drawn as intersection border
  */
 inline ClosedPolygonalChains polygonalChain(const std::vector<std::pair<const Edge*, Point>> intersections, const std::vector<OriginalEdge> origin) {
	 std::set<Edge, compareEdges> polyLine;

	 #pragma omp parallel for collapse(3)
	 for( int i = 0; i < intersections.size() - 1; i++) {
		 for( int j = i+1; j < intersections.size(); j++ ){
			 for( int k = 0; k < origin.size(); k++ ){
				 Edge* e;
				 // 4 possible connections, both ways
				 if		( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getStart() )	e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getEnd() )		e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getStart() )	e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getEnd() )		e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));

				 else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getStart() )	e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getEnd() )		e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getStart() )	e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getEnd() )		e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				 else continue;

				 #pragma omp critical
				 polyLine.insert(*e);
			 }
		 }
	 }
	 std::vector<Edge> out(polyLine.begin(), polyLine.end());
	 ClosedPolygonalChains cpc = ClosedPolygonalChains(out);
	 return cpc;
 }

 inline std::vector<Edge> removeReversed(std::vector<Edge> edges) {
	 std::vector<Edge> unique;
	 for (auto& x : edges) {
		bool only = true;
		for (auto &y : unique)
			if (y.getStart() == x.getEnd() && y.getEnd() == x.getStart())
				only = false;
		if (only) unique.push_back(x);
	 }
	 return unique;
 }
