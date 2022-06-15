/*****************************************************************//**
 * @file   Triangle.h
 * @brief  Class representing a triangle built from three edges.
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "Plane.h"
#include "Edge.h"
#include "VectorOperations.h"

#include <algorithm>
#include <string>

/**
 * Custom type representing triangle.
 */
class Triangle : public Plane{

	public:
		Triangle(const Edge& _edgeA, const Edge& _edgeB, const Edge& _edgeC) 
		: edgeA{ _edgeA }, edgeB{ _edgeB }, edgeC{ _edgeC }, pointA{ edgeA.getStart() }, pointB{ edgeA.getEnd() }, pointC{ edgeB.getStart() }
		{
			if( pointC == pointA ||  pointC == pointB )
				pointC = edgeB.getEnd();

			std::array<double, 3> crossProduct = cross(edgeA.getDirectionalVector(), edgeB.getDirectionalVector());
			set(crossProduct[0], 
				crossProduct[1],
				crossProduct[2],
				-(crossProduct[0]*getPointInside().getX() + crossProduct[1]*getPointInside().getY() + crossProduct[2]*getPointInside().getZ())
			);
		}

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
		double getArea() const { return 0.5*abs(norm(getNormalVector())); }

		/**
		 * @brief Checks if given point is inside this triangle.
		 * 
		 * @note Inside also includes edges.
		 * 
		 * @param pointP Given point.
		 * @return True if point is inside, otherwise false.
		 */
		bool containsPoint(const Point& pointP) const{
			std::array<double, 3> vecPA = { pointP.getX() - getPointA().getX(), pointP.getY() - getPointA().getY(), pointP.getZ() - getPointA().getZ() };
			std::array<double, 3> vecPB = { pointP.getX() - getPointB().getX(), pointP.getY() - getPointB().getY(), pointP.getZ() - getPointB().getZ() };
			std::array<double, 3> vecPC = { pointP.getX() - getPointC().getX(), pointP.getY() - getPointC().getY(), pointP.getZ() - getPointC().getZ() };
			double sum = 0.5 * ( abs(norm(cross(vecPA,vecPB))) + abs(norm(cross(vecPB, vecPC))) + abs(norm(cross(vecPC, vecPA))) );
			//double eps = 0.000000001;
			//if( sum >= getArea()-eps && sum <= getArea()+eps )
			if( sum == getArea() )
				return true;
			return false;
		}

		/**
		 * @brief Overloaded operator "==" comparing two triangles.
		 * 
		 * @param e Given triangle to compare.
		 * @return True if given triangle has the same points as this triangle, otherwise false.
		 */
		bool operator==(const Triangle& e) const {
			if( this != nullptr ){
				std::array<Point, 3> thisPoints{ getPointA(), getPointB(), getPointC() };
				std::sort(thisPoints.begin(), thisPoints.end(), comparePoints());
				std::array<Point, 3> thatPoints{ e.getPointA(), e.getPointB(), e.getPointC() };
				std::sort(thatPoints.begin(), thatPoints.end(), comparePoints());
				if( thisPoints[0] == thatPoints[0] && thisPoints[1] == thatPoints[1] && thisPoints[2] == thatPoints[2] )
					return true;
				else
					return false;
			}
		};

		/**
		 * @brief Function for finding a point inside this triangle.
		 * 
		 * @note Inside do not include edges.
		 * 
		 * @return Point object which is definitely inside this triangle.
		 */
		Point getPointInside() const{
			Point centerAB{ (pointA.getX()+pointB.getX())/2, (pointA.getY()+pointB.getY())/2, (pointA.getZ()+pointB.getZ())/2 };
			return Point{ (centerAB.getX()+pointC.getX())/2, (centerAB.getY()+pointC.getY())/2, (centerAB.getZ()+pointC.getZ())/2 };
		}
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