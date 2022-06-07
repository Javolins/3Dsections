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

		Plane getPlane() const{ return Plane{ getA(), getB(), getC(), getD() }; }
		double getArea() const { return 0.5*norm(getNormalVector()); }
		bool containsPoint(const Point& pointP) const{
			std::array<double, 3> vecPA = { pointP.getX() - getPointA().getX(), pointP.getY() - getPointA().getY(), pointP.getZ() - getPointA().getZ() };
			std::array<double, 3> vecPB = { pointP.getX() - getPointB().getX(), pointP.getY() - getPointB().getY(), pointP.getZ() - getPointB().getZ() };
			std::array<double, 3> vecPC = { pointP.getX() - getPointC().getX(), pointP.getY() - getPointC().getY(), pointP.getZ() - getPointC().getZ() };
			double sum = 0.5 * ( norm(cross(vecPA,vecPB)) + norm(cross(vecPB, vecPC)) + norm(cross(vecPC, vecPA)) );
			if( sum == getArea() )
				return true;
			return false;
		}

		Point getPointInside() const{
			Point centerAB{ (pointA.getX()+pointB.getX())/2, (pointA.getY()+pointB.getY())/2, (pointA.getZ()+pointB.getZ())/2 };
			return Point{ (centerAB.getX()+pointC.getX())/2, (centerAB.getY()+pointC.getY())/2, (centerAB.getZ()+pointC.getZ())/2 };
		}
	private:
		Edge edgeA, edgeB, edgeC;
		Point pointA, pointB, pointC;
};

class compareTriangles{
	public:
		bool operator()(const Triangle& a, const Triangle& b) const{
			//if( b.getA() < a.getA() ) return false;
			//if( a.getA() < b.getA() ) return true;

			//if( b.getB() < a.getB() ) return false;
			//if( a.getB() < b.getB() ) return true;

			//if( b.getC() < a.getC() ) return false;
			//if( a.getC() < b.getC() ) return true;

			//if( b.getD() < a.getD() ) return false;
			//if( a.getD() < b.getD() ) return true;

			if( a.getPointA() == b.getPointA() &&
			   a.getPointB() == b.getPointB() &&
			   a.getPointC() == b.getPointC() ) return false;

			return true;
		}
};

