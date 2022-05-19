#pragma once
/*****************************************************************//**
 * @file   SimpleLib.h
 * @brief  A few simple math useful tools class representation
 *
 * @author Janusz Malinowski AGH Univeristy
 *********************************************************************/

/**
* @brief Auxiliary class representing a R,G,B color.
* 
* @note RGB components represent by three integer value
*/
struct Color 
{
	int R, G, B;
	Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};


/**
 * @brief Simple class representing a math point in three-dimensional space X,Y,Z.
 * 
 * @note Point coordinates are represented by three float value and one for every dimension
 */

struct Point 
{
	float x, y, z;
	Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

 /**
  * @brief Simple class representing a math section in three-dimensional space X,Y,Z.
  * 
  * @note Section is indicated by start and end point @ref Point ans its color
  */
struct Segment 
{
	Point begin, end;
	Color color;
	Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};


/**
 * @brief .Class representing a math vector in three-dimensional space X,Y,Z
 */


class Vector4
{
public:
	/**  
	* @brief One dimensional Array of double which contains a vector coordinates X,Y,Z 
	*/
	double data[4];
	/** 
	* @brief Creates an instance of the class - Vector4.
	*/
	Vector4();
	/**
	 * @brief Print Vector4 content
	 * 
	 */
	void Print(void);
	/**
	 * @brief Set a Vector4 coordinates.
	 * 
	 * @param X coordinate
	 * @param Y coordinate
	 * @param Z coordinate
	 */
	void Set(double d1, double d2, double d3);
	/**
	 * .@brief Get method
	 * 
	 * @return X coordinate 
	 */
	double GetX();
	/**
	 * .@brief Get method
	 *
	 * @return Y coordinate
	 */
	double GetY();
	/**
	 * .@brief Get method
	 *
	 * @return Z coordinate
	 */
	double GetZ();
	/**
	 * @brief Overloaded "-" operator
	 * 
	 * @note Operator allow substraction Vector4 coordinates 
	 * from other Vector4 coordinates
	 * 
	 * @param const reference to Vector4 object
	 * @return Vector4 object
	 */
	Vector4 operator-(const Vector4&);
	/**
	 * @brief The friend delaration beetwen class Vector4 
	 * and overloaded "*" operator
	 * 
	 * @param const reference to Vector4 object,
	 * @param vector multiplier
	 * 
	 * @return Vector4 object
	 */
	friend Vector4 operator*(const Vector4&, double);
};

/**
 * @brief .Class representing a math matrix in three-dimensional space
 */
class Matrix4
{
public:
	/**
	* @brief Two-dimensional Array of double which represent math matrix
	*/
	double data[4][4];
	/**
	* @brief Creates an instance of the class - Matrix4.
	*/
	Matrix4();
	/**
	 * @brief Print Matrix4 content
	 *
	 */
	void Print(void);
	/**
	 * @brief Overloaded "*" operator as a member function
	 *
	 * @note Operator allow multiplication Matrix4 elements
	 *
	 * @param const Matrix4 object
	 * @return Matrix4 object
	 */
	Matrix4 operator*(const Matrix4);
	/**
	 * @brief The friend declaration beetwen class Matrix4 
	 * and overloaded "*" operator defined outside the class 
	 *
	 * @note Operator allow multiplication Matrix4 by Vector4
	 *
	 * @param const Matrix4 object
	 * @param const Vector4 object
	 * @return Vector4 object
	 */
	friend Vector4 operator*(const Matrix4, const Vector4);
};


Vector4::Vector4()
{
	data[0] = 0.0; data[1] = 0.0; data[2] = 0.0; data[3] = 1.0;
}

void Vector4::Print(void)
{
	printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n", data[0], data[1], data[2], data[3]);
}

void Vector4::Set(double d1, double d2, double d3)
{
	data[0] = d1; data[1] = d2; data[2] = d3;
}

double Vector4::GetX()
{
	return data[0];
}

double Vector4::GetY()
{
	return data[1];
}

double Vector4::GetZ()
{
	return data[2];
}

Vector4 Vector4::operator- (const Vector4& gVector)
{
	unsigned int i;
	Vector4 Result;
	for (i = 0; i < 4; i++) Result.data[i] = data[i] - gVector.data[i];
	return Result;
}

Vector4 operator* (const Vector4& gVector, double val)
{
	unsigned int i;
	Vector4 Result;
	for (i = 0; i < 4; i++) Result.data[i] = gVector.data[i] * val;
	return Result;
}

Matrix4::Matrix4()
{
	data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0; data[0][3] = 0.0;
	data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0; data[1][3] = 0.0;
	data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 0.0; data[2][3] = 0.0;
	data[3][0] = 0.0; data[3][1] = 0.0; data[3][2] = 0.0; data[3][3] = 1.0;
}

void Matrix4::Print(void)
{
	printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[0][0], data[0][1], data[0][2], data[0][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[1][0], data[1][1], data[1][2], data[1][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[2][0], data[2][1], data[2][2], data[2][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[3][0], data[3][1], data[3][2], data[2][3]);
}

Matrix4 Matrix4::operator* (const Matrix4 gMatrix)
{
	int i, j, k;
	Matrix4 tmp;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			tmp.data[i][j] = 0.0;
			for (k = 0; k < 4; k++)
				tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * gMatrix.data[k][j]);
		}
	return tmp;
}

Vector4 operator* (const Matrix4 gMatrix, const Vector4 gVector)
{
	unsigned int i, j;
	Vector4 tmp;

	for (i = 0; i < 4; i++)
	{
		tmp.data[i] = 0.0;
		for (j = 0; j < 4; j++) tmp.data[i] = tmp.data[i] + (gMatrix.data[i][j] * gVector.data[j]);
	}
	return tmp;
}




