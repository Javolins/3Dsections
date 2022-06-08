/*****************************************************************//**
 * @file   Triangle.h
 * @brief  Class representing a triangle built from three edges
 * 
 * @author Michał Rutkowski @P4ndaM1x
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "Plane.h"
#include "Edge.h"
#include <algorithm>
#include <string>

inline std::array<double, 3> cross(std::array<double, 3> a, std::array<double, 3> b){
	std::array<double, 3> result;
	result[0] = a[1]*b[2] - a[2]*b[1];
	result[1] = a[2]*b[0] - a[0]*b[2];
	result[2] = a[0]*b[1] - a[1]*b[0];
	return result;
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

class Triangle : public Plane{

	public:
		Triangle(const Edge& _edgeA, const Edge& _edgeB, const Edge& _edgeC) 
		: edgeA{ _edgeA }, edgeB{ _edgeB }, edgeC{ _edgeC } {
			std::array<double, 3> crossProduct = cross(edgeA.getDirectionalVector(), edgeB.getDirectionalVector());
			double D = -(getA()*edgeB.getEnd().getX() + getB()*edgeB.getEnd().getY() + getC()*edgeB.getEnd().getZ());
			set(crossProduct[0], crossProduct[1], crossProduct[2], D);
			pointA = edgeA.getStart();
			pointB = edgeA.getEnd();
			pointC = edgeB.getStart();
			if( pointC == pointA ||  pointC == pointB )
				pointC = edgeB.getEnd();
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
		bool containsPoint(const Point& pointP) const{
			std::array<double, 3> vecPA = { pointP.getX() - getPointA().getX(), pointP.getY() - getPointA().getY(), pointP.getZ() - getPointA().getZ() };
			std::array<double, 3> vecPB = { pointP.getX() - getPointB().getX(), pointP.getY() - getPointB().getY(), pointP.getZ() - getPointB().getZ() };
			std::array<double, 3> vecPC = { pointP.getX() - getPointC().getX(), pointP.getY() - getPointC().getY(), pointP.getZ() - getPointC().getZ() };
			double sum = 0.5 * ( abs(norm(cross(vecPA,vecPB))) + abs(norm(cross(vecPB, vecPC))) + abs(norm(cross(vecPC, vecPA))) );
			if( sum == getArea() )
				return true;
			return false;
		}
		bool operator==(const Triangle& e) const {
			//if( this != nullptr && getA() == e.getA() && getB() == e.getB() && getC() == e.getC() && getD() == e.getD() ) return true; else return false;
			if( this != nullptr ){
				std::array<Point, 3> thisPoints{ getPointA(), getPointB(), getPointC() };
				std::sort(thisPoints.begin(), thisPoints.end(), comparePoints());

				std::array<Point, 3> thatPoints{ e.getPointA(), e.getPointB(), e.getPointC() };
				std::sort(thatPoints.begin(), thatPoints.end(), comparePoints());

				if( thisPoints[0] == thatPoints[0] && thisPoints[1] == thatPoints[1] && thisPoints[2] == thatPoints[2] ){
					return true;
				}
				else{
					return false;
				}
			}
		};
		Point getPointInside() const{
			Point centerAB{ (pointA.getX()+pointB.getX())/2, (pointA.getY()+pointB.getY())/2, (pointA.getZ()+pointB.getZ())/2 };
			return Point{ (centerAB.getX()+pointC.getX())/2, (centerAB.getY()+pointC.getY())/2, (centerAB.getZ()+pointC.getZ())/2 };
		}
	private:
		Edge edgeA, edgeB, edgeC;
		Point pointA, pointB, pointC;
};

class hashTriangles{
	public:
		size_t operator()(const Triangle& t) const{
			std::array<Point, 3> points{ t.getPointA(), t.getPointB(), t.getPointC() };
			std::sort(points.begin(), points.end(), comparePoints());

			//std::string toHash =
			//	std::to_string(points[0].getX()) +
			//	std::to_string(points[0].getY()) +
			//	std::to_string(points[0].getZ()) +
			//	std::to_string(points[1].getX()) +
			//	std::to_string(points[1].getY()) +
			//	std::to_string(points[1].getZ()) +
			//	std::to_string(points[2].getX()) +
			//	std::to_string(points[2].getY()) +
			//	std::to_string(points[2].getZ());

			//		size_t ax = std::hash<float>{}(points[0].getX());
			//		size_t ay = std::hash<float>{}(points[0].getY());
			//		size_t az = std::hash<float>{}(points[0].getZ());
			//		size_t bx = std::hash<float>{}(points[1].getX());
			//		size_t by = std::hash<float>{}(points[1].getY());
			//		size_t bz = std::hash<float>{}(points[1].getZ());
			//		size_t cx = std::hash<float>{}(points[2].getX());
			//		size_t cy = std::hash<float>{}(points[2].getY());
			//		size_t cz = std::hash<float>{}(points[2].getZ());

			//size_t a = ((((((((ax ^ (ay << 1)) ^ (az << 1)) ^ (bx << 1)) ^ (by << 1)) ^ (bz << 1)) ^ (cx << 1)) ^ (cy << 1)) ^ (cz << 1));
			//size_t number = std::hash<std::string>()(toHash);

			//size_t out =
			//	3 * points[0].getX() +
			//	5 * points[0].getY() +
			//	7 * points[0].getZ() +
			//	11 * points[1].getX() +
			//	13 * points[1].getY() +
			//	17 * points[1].getZ() +
			//	19 * points[2].getX() +
			//	23 * points[2].getY() +
			//	29 * points[2].getZ();

			//return out;//number;
		}
};

