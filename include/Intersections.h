/*****************************************************************//**
 * @file   intersections.h
 * @brief  Small library for functions calculating intersections.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <array>
#include <memory>

#include "../include/Edge.h"
#include "../include/vectorOperations.h"
#include "../include/Plane.h"

//! Namespace containing operations on intersections.
namespace intersections {
	/**
	 * @brief Calculates the intersections::edgeWithPlane point of @ref Edge and @ref Plane.
	 *
	 * @param line Segment of the line used in an algorithm.
	 * @param plane Plane used in an algorithm.
	 * @return If there is exactly one point of intersections::edgeWithPlane it will be returned, in other case - nullptr.
	 */
	inline std::unique_ptr<Point> edgeWithPlane(const Edge& line, const Plane& plane){

		if( line.getDirectionalVector()[0] == 0 &&  line.getDirectionalVector()[1] == 0 && line.getDirectionalVector()[2] == 0 )
			return nullptr;

		// check if edge intersects plane
		Point onPlane{ 0,0,0 };
		if( plane.getA() != 0 )
			onPlane.setX(-plane.getD()/plane.getA());
		else if( plane.getB() != 0 )
			onPlane.setY(-plane.getD()/plane.getB());
		else if( plane.getC() != 0 )
			onPlane.setZ(-plane.getD()/plane.getC());
		else return nullptr;

		Point start = line.getStart();
		Point end = line.getEnd();

		while( start == onPlane || end == onPlane ){
			srand(time(nullptr));
			onPlane.set(onPlane.getX()+rand()%7-3, onPlane.getX()+rand()%7-3, onPlane.getX()+rand()%7-3);
			if( plane.getA() != 0 )
				onPlane.setX(-(plane.getD()+plane.getB()*onPlane.getY()+plane.getC()*onPlane.getZ()) / plane.getA());
			else if( plane.getB() != 0 )
				onPlane.setY(-(plane.getD()+plane.getA()*onPlane.getX()+plane.getC()*onPlane.getZ()) / plane.getB());
			else if( plane.getC() != 0 )
				onPlane.setZ(-(plane.getD()+plane.getA()*onPlane.getX()+plane.getB()*onPlane.getY()) / plane.getC());
			else return nullptr;
		}

		std::array<double, 3> startVec{ start.getX() - onPlane.getX(), start.getY() - onPlane.getY(), start.getZ() - onPlane.getZ() };
		std::array<double, 3> endVec{ end.getX() - onPlane.getX(), end.getY() - onPlane.getY(), end.getZ() - onPlane.getZ() };
		std::array<double, 3> planeVec{ plane.getNormalVector() };

		if( vectorOperations::sgn(vectorOperations::dot(startVec, planeVec)) == vectorOperations::sgn(vectorOperations::dot(endVec, planeVec)) )
			return nullptr;

		// calculate intersections::edgeWithPlane point
		std::array<double, 3> lineVec = line.getDirectionalVector();

		if( (plane.getA() * lineVec[0] + plane.getB() * lineVec[1] + plane.getC() * lineVec[2]) == 0 )
			return nullptr;

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
	 * @brief Function calculating all intersections between vector of @ref Edge and @ref Plane.
	 *
	 * @param edges 3D solid defined as edges.
	 * @param plane intersecting with 3D solid.
	 * @return Vector of intersections::edgeWithPlane points with const pointers to edges that created them.
	 */
	inline std::vector<std::pair<const Edge*, Point>> edgesWithPlane(const std::vector<Edge>& edges, const Plane& plane){

		std::vector<std::pair<const Edge*, Point>> intersections;
		for( auto& edge : edges ){
			std::unique_ptr<Point> ptr{ edgeWithPlane(edge, plane) };
			if( ptr != nullptr )
				intersections.push_back({ &edge, *ptr });
		}
		return intersections;
	}

	/**
	 * @brief Function checking if two given edges intersect at exactly one point.
	 *
	 * @param a First Edge.
	 * @param b Second Edge.
	 * @return True if edges are intersecting, false otherwise.
	 */
	inline bool edgeWithEdge(const Edge& a, const Edge& b){

		std::array<double, 3> aVec = a.getDirectionalVector();
		std::array<double, 3> bVec = b.getDirectionalVector();

		std::array<double, 3> crossProduct = vectorOperations::cross(aVec, bVec);
		if( crossProduct[0] == 0 && crossProduct[1] == 0 && crossProduct[2] == 0 )
			return false;

		Point A = a.getStart();
		Point B = a.getEnd();
		Point C = b.getStart();
		Point D = b.getEnd();

		double t = 0, s = 0;
		if( !(((A.getX()-B.getX()) == 0 || (D.getY()-C.getY()) == 0) && ((A.getY()-B.getY()) == 0 || (D.getX()-C.getX()) == 0)) )
			if( (A.getX() - B.getX()) ){

				s = ((A.getX()-B.getX())*(D.getY()-B.getY()) - (A.getY()-B.getY())*(D.getX()-B.getX()))
					/ ((A.getX()-B.getX())*(D.getY()-C.getY()) - (A.getY()-B.getY())*(D.getX()-C.getX()));
				t = ((D.getX()-B.getX()) - s*(D.getX()-C.getX())) / (A.getX() - B.getX());

				if( t*(A.getZ() - B.getZ()) + s*(D.getZ()-C.getZ()) != D.getZ()-B.getZ() )
					return false;
			}
		if( !(((A.getX()-B.getX()) == 0 || (D.getZ()-C.getZ()) == 0) && ((A.getZ()-B.getZ()) == 0 || (D.getX()-C.getX()) == 0)) )
			if( (A.getX() - B.getX()) ){

				s = ((A.getX()-B.getX())*(D.getZ()-B.getZ()) - (A.getZ()-B.getZ())*(D.getX()-B.getX()))
					/ ((A.getX()-B.getX())*(D.getZ()-C.getZ()) - (A.getZ()-B.getZ())*(D.getX()-C.getX()));
				t = ((D.getX()-B.getX()) - s*(D.getX()-C.getX())) / (A.getX() - B.getX());

				if( t*(A.getY() - B.getY()) + s*(D.getY()-C.getY()) != D.getY()-B.getY() )
					return false;
			}
		if( !(((A.getY()-B.getY()) == 0 || (D.getZ()-C.getZ()) == 0) && ((A.getZ()-B.getZ()) == 0 || (D.getY()-C.getY()) == 0)) )
			if( (A.getY() - B.getY()) ){

				s = ((A.getY()-B.getY())*(D.getZ()-B.getZ()) - (A.getZ()-B.getZ())*(D.getY()-B.getY()))
					/ ((A.getY()-B.getY())*(D.getZ()-C.getZ()) - (A.getZ()-B.getZ())*(D.getY()-C.getY()));
				t = ((D.getY()-B.getY()) - s*(D.getY()-C.getY())) / (A.getY() - B.getY());

				if( t*(A.getX() - B.getX()) + s*(D.getX()-C.getX()) != D.getX()-B.getX() )
					return false;
			}

		if( 0 < t && t < 1 && 0 < s && s < 1 )
			return true;
		return false;

	}
}

