/*****************************************************************//**
 * @file   Ray.h
 * @brief  
 * 
 * @author Michał Rutkowski @P4ndaM1x
 * @date   June 2022
 *********************************************************************/

#pragma once
#include <limits>
#include "Edge.h"

class Ray : public Edge{
	public:
		Ray(const Point& point) : Edge{ point, Point{std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max()} } {}
		Point getPoint() const{ return getStart(); }
};