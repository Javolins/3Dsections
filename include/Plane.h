/*****************************************************************//**
 * @file   Plane.h
 * @brief  Class representing a plane used in 3D transformations.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include <array>
#include "DataClasses.h"

//! Type and container for 4 paramters unambiguously defining a plane.
class Plane {

	public:
		Plane(const double a = 0, const double b = 0, const double c = 0, const double d = 0) : parameters{ a, b, c, d } {}
		~Plane() = default;

		double getParameter(const short i) const { return parameters.at(i); }
		double getA() const { return parameters[0]; }
		double getB() const { return parameters[1]; }
		double getC() const { return parameters[2]; }
		double getD() const { return parameters[3]; }

		void setParameter(const short i, const double value) { parameters.at(i) = value; }
		void setA(const double input) { parameters[0] = input; }
		void setB(const double input) { parameters[1] = input; }
		void setC(const double input) { parameters[2] = input; }
		void setD(const double input) { parameters[3] = input; }
		void set(const double a, const double b, const double c, const double d) { setA(a); setB(b); setC(c); setD(d); }

		//! Returns a normal vector to the plane.
		std::array<double, 3> getNormalVector() const { return std::array<double, 3> {parameters[0], parameters[1], parameters[2]}; }

		//! Returns true if given point is on the plane.
		bool containsPoint(const Point& point) const{
			if( getA()*point.getX() + getB()*point.getY() + getC()*point.getZ() + getD() == 0 ) return true; else return false;
		}

		friend std::ostream& operator<<(std::ostream& s, const Plane& p);

	private:
		std::array<double, 4> parameters;
};

inline std::ostream& operator<<(std::ostream& s, const Plane& p){
	return s << "Plane:\n" << " " << p.getA() << " " << p.getB() << " " << p.getC() << " " << p.getD() << std::endl;
}