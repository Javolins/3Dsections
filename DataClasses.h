#pragma once
/*****************************************************************//**
 * @file   DataClasses.h
 * @brief  classes decomposing loaded file for processing
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

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
		Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		int getX() { return x; };
		int getY() { return y; };
		int getZ() { return z; };
	private:
		float x;
		float y;
		float z;
};




