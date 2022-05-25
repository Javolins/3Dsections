/*****************************************************************//**
 * @file   DataClasses.h
 * @brief  classes decomposing loaded file for processing
 *
 * @author Aleksander Bartoszek, Micha³ Rutkowski
 *********************************************************************/

#pragma once

/**
* @brief Simple class representing a R,G,B color.
* 
* @note RGB components represented by three unsigned short values
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

	private:
		unsigned short _r, _g, _b;
};

/**
 * @brief Simple class representing a math point in three-dimensional space X,Y,Z.
 * 
 * @note Point coordinates are represented by three float values, one for each dimension
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
		float getX() const { return _x; }
		float getY() const { return _y; }
		float getZ() const { return _z; }

	private:
		float _x, _y, _z;
};