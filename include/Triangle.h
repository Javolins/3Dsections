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
#include "stout.h"

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
	private:
		Edge edgeA, edgeB, edgeC;
		Point pointA, pointB, pointC;
};

