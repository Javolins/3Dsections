/*****************************************************************//**
 * @file   DataClasses.h
 * @brief  Classes decomposing loaded file for processing.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include <iostream>

/**
* @brief Simple class representing a R,G,B color.
* 
* @note RGB components are represented by three unsigned short values.
*/
class Color {

	public:
		Color(unsigned short r, unsigned short g, unsigned short b) : _r{ r }, _g{ g }, _b{ b } {}
		void set(unsigned short r, unsigned short g, unsigned short b) {
			_r = r; _g = g; _b = b;
		}
		unsigned short getR() const { return _r; }
		unsigned short getG() const { return _g; }
		unsigned short getB() const { return _b; }
		friend std::ostream& operator<<(std::ostream& os, const Color& p);

	private:
		unsigned short _r, _g, _b;
};

/**
 * @brief Simple class representing a math point in three-dimensional space X,Y,Z.
 * 
 * @note Point coordinates are represented by three float values, one for each dimension.
 */
class Point {

	public:
		Point(float x = 0, float y = 0, float z = 0) : _x{ x }, _y{ y }, _z{ z } {}
		bool operator==(const Point& point) const {
			if (this != nullptr && _x == point.getX() && _y == point.getY() && _z == point.getZ())
				return true;
			else
				return false;
		}
		void set(float x, float y, float z) {
			_x = x; _y = y; _z = z;
		}
		void setX(float x){ _x = x; }
		void setY(float y){ _y = y; }
		void setZ(float z){ _z = z; }
		float getX() const { return _x; }
		float getY() const { return _y; }
		float getZ() const { return _z; }
		friend std::ostream& operator<<(std::ostream& os, const Point& p);

	private:
		float _x, _y, _z;
};

/**
 * @brief Functional object for comparing Points in algorithms.
 *
 */
struct comparePoints {
	bool operator()(const Point& a, const Point& b) const {
		if (a.getX() < b.getX()) return true;
		if (b.getX() < a.getX()) return false;

		if (a.getY() < b.getY()) return true;
		if (b.getY() < a.getY()) return false;

		if (a.getZ() < b.getZ()) return true;
		if (b.getZ() < a.getZ()) return false;
		
		return false;
	}
};

inline std::ostream& operator<< (std::ostream& os, const Point& p) {
	os << "<";
	os << p.getX() << ", ";
	os << p.getY() << ", ";
	os << p.getZ() << "> ";
	return os;
}

inline std::ostream& operator<< (std::ostream& os, const Color& c) {
	os << "<";
	os << c.getR() << ", ";
	os << c.getG() << ", ";
	os << c.getB() << "> ";
	return os;
}
