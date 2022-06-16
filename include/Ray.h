/*****************************************************************//**
 * @file   Ray.h
 * @brief  Class representing a specific edge being in fact a half-line.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#pragma once
#include "Edge.h"

/**
 * Specific edge representing a half-line.
 */
class Ray : public Edge{

	public:
		/**
		 * @brief Default constructor of really long edge starting at @ref point and ending in the very corner of the first octant of Cartesian coordinate system.
		 * 
		 * @param point Place where the ray begins.
		 */
		Ray(const Point& point) : Edge{ point, Point{std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max()} } {}

		/**
		 * @brief Changes the end of @ref Edge, accordingly to given number.
		 * 
		 * @param version Numbers from 1 to 8 represents corners of every octant of the Cartesian coordinate system, every other value will result in random ending.
		 */
		void changeEnd(const int version);

		/**
		 * @brief Simple getter of @ref Edge start point.
		 * 
		 * @return Point object.
		 */
		Point getPoint() const{ return getStart(); }
};