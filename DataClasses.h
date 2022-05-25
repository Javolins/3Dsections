/*****************************************************************//**
 * @file   DataClasses.h
 * @brief  classes decomposing loaded file for processing
 *
 * @author Aleksander Bartoszek, Micha³ Rutkowski
 *********************************************************************/

#pragma once

/**
* @brief Auxiliary class representing a R,G,B color.
* 
* @note RGB components represented by three integer value
*/
class Rgb {
	public:
		Rgb(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {};
		int getR() { return r; };
		int getG() { return g; };
		int getB() { return b; };
	private:
		int r;
		int g; 
		int b;
};

/**
 * @brief Simple class representing a math point in three-dimensional space X,Y,Z.
 * 
 * @note Point coordinates are represented by three float values, one for each dimension
 */
class Point {
	public:
		Point(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
		bool operator==(const Point& point) const{
			if (this != nullptr && x == point.getX() && y == point.getY() && z == point.getZ())
				return true;
			else
				return false;
		}
		void operator()(float x, float y, float z) {
			this->x = x; this->y = y; this->z = z;
		}
		float getX() const { return x; };
		float getY() const { return y; };
		float getZ() const { return z; };
	private:
		float x;
		float y;
		float z;
};




