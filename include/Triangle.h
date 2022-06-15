/*****************************************************************//**
 * @file   Triangle.h
 * @brief  Class representing a triangle built from three edges.
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "Plane.h"
#include "../include/Edge.h"
#include "../include/vectorOperations.h"

#include <algorithm>
#include <string>

/**
 * Custom type representing triangle.
 */
class Triangle : public Plane{

	public:
		Triangle(const Edge& _edgeA, const Edge& _edgeB, const Edge& _edgeC);

		Edge getEdgeA() const { return edgeA; }
		Edge getEdgeB() const { return edgeB; }
		Edge getEdgeC() const { return edgeC; }
		Point getPointA() const { return pointA; }
		Point getPointB() const { return pointB; }
		Point getPointC() const { return pointC; }
		void setEdgeA(const Edge& e = { Point(), Point() }) { edgeA = e; };
		void setEdgeB(const Edge& e = { Point(), Point() }) { edgeB = e; };
		void setEdgeC(const Edge& e = { Point(), Point() }) { edgeC = e; };

		Plane getPlane() const{ return Plane{ getA(), getB(), getC(), getD() }; }
		double getArea() const { return 0.5*abs(vectorOperations::norm(getNormalVector())); }

		/**
		 * @brief Checks if given point is inside this triangle.
		 * 
		 * @note Inside also includes edges.
		 * 
		 * @param pointP Given point.
		 * @return True if point is inside, otherwise false.
		 */
		bool containsPoint(const Point& pointP) const;

		/**
		 * @brief Overloaded operator "==" comparing two triangles.
		 * 
		 * @param e Given triangle to compare.
		 * @return True if given triangle has the same points as this triangle, otherwise false.
		 */
		bool operator==(const Triangle& e) const;

		/**
		 * @brief Function for finding a point inside this triangle.
		 * 
		 * @note Inside do not include edges.
		 * 
		 * @return Point object which is definitely inside this triangle.
		 */
		Point getPointInside() const;

		friend std::ostream& operator<<(std::ostream& s, const Triangle& t);

	private:
		Edge edgeA, edgeB, edgeC;
		Point pointA, pointB, pointC;
};

inline std::ostream& operator<<(std::ostream& s, const Triangle& t){
	return s << "Triangle:\n" << t.getEdgeA() << t.getEdgeB() << t.getEdgeC() << std::endl;
}

/**
 * @brief Function object for hashing triangles to be used in std::unordered_set.
 * 
 * @note Use with caution! It may behave wildly.
 */
class hashTriangles{
	public:
		size_t operator()(const Triangle& t) const{
			std::array<Point, 3> points{ t.getPointA(), t.getPointB(), t.getPointC() };
			std::sort(points.begin(), points.end(), comparePoints());

			size_t out =
				3 * points[0].getX() +
				5 * points[0].getY() +
				7 * points[0].getZ() +
				11 * points[1].getX() +
				13 * points[1].getY() +
				17 * points[1].getZ() +
				19 * points[2].getX() +
				23 * points[2].getY() +
				29 * points[2].getZ();

			return out;
		}
};