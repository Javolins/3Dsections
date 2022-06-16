/*****************************************************************//**
 * @file   Triangle.cpp
 * @brief  Implementation of methods used in the class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#include <limits>
#include "../include/Triangle.h"

Triangle::Triangle(const Edge& _edgeA, const Edge& _edgeB, const Edge& _edgeC)
	: edgeA{ _edgeA }, edgeB{ _edgeB }, edgeC{ _edgeC }, pointA{ edgeA.getStart() }, pointB{ edgeA.getEnd() }, pointC{ edgeB.getStart() }
{
	if( pointC == pointA ||  pointC == pointB )
		pointC = edgeB.getEnd();

	std::array<double, 3> crossProduct = vectorOperations::cross(edgeA.getDirectionalVector(), edgeB.getDirectionalVector());
	set(crossProduct[0],
		crossProduct[1],
		crossProduct[2],
		-(crossProduct[0]*getPointInside().getX() + crossProduct[1]*getPointInside().getY() + crossProduct[2]*getPointInside().getZ())
	);
}

bool Triangle::containsPoint(const Point& pointP) const{
	std::array<double, 3> vecPA = { pointP.getX() - getPointA().getX(), pointP.getY() - getPointA().getY(), pointP.getZ() - getPointA().getZ() };
	std::array<double, 3> vecPB = { pointP.getX() - getPointB().getX(), pointP.getY() - getPointB().getY(), pointP.getZ() - getPointB().getZ() };
	std::array<double, 3> vecPC = { pointP.getX() - getPointC().getX(), pointP.getY() - getPointC().getY(), pointP.getZ() - getPointC().getZ() };
	double sum = 0.5 * (abs(vectorOperations::norm(vectorOperations::cross(vecPA, vecPB))) + abs(vectorOperations::norm(vectorOperations::cross(vecPB, vecPC))) + abs(vectorOperations::norm(vectorOperations::cross(vecPC, vecPA))));
	//double eps = 0.000000001;
	//if( sum >= getArea()-eps && sum <= getArea()+eps )
	if( sum == getArea() )
		return true;
	return false;
}

bool Triangle::operator==(const Triangle& e) const{
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

Point Triangle::getPointInside() const{
	Point centerAB{ (pointA.getX()+pointB.getX())/2, (pointA.getY()+pointB.getY())/2, (pointA.getZ()+pointB.getZ())/2 };
	return Point{ (centerAB.getX()+pointC.getX())/2, (centerAB.getY()+pointC.getY())/2, (centerAB.getZ()+pointC.getZ())/2 };
}
