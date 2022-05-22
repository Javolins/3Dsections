#pragma once
/*****************************************************************//**
 * @file   Vector4.h
 * @brief  class representing matrix used in 3D transformations
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#include "Vector4.h"

class Matrix4 {
	public:
		Matrix4();
		void printMatrix();
		double getElement(int x, int y) const { return data[x][y]; };
		void setElement(int x, int y, double value) { data[x][y] = value; };

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
	private:
		/**
		* @brief Two-dimensional Array of double which represent math matrix
		*/
		double data[4][4];
};