/*****************************************************************//**
 * @file   Vector4.h
 * @brief  Class representing matrix used in 3D transformations.
 *
 * @author PhD Janusz Malinowski, Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../include/Vector4.h"

/**
 * Type representing 4-dimensional matrix.
 */
class Matrix4 {
	
	public:
		/**
		 * @brief Constructor setting up default values.
		 * 
		 * All values are set to 0 except for element[3][3] which is set to 1.
		 */
		Matrix4();
		/**
		 * @brief Method printing formatted data from Matrix4.
		 */
		void printMatrix();

		/**
		 * @brief Simple getter function for Matrix4.
		 */
		double getElement(int x, int y) const { return data[x][y]; };
		/**
		 * @brief Simple setter function for Matrix4.
		 */
		void setElement(int x, int y, double value) { data[x][y] = value; };
		/**
		 * @brief Sets all elements of this matrix to given value.
		 */
		void setAllElements(double value);

		/**
		 * @brief Overloaded "*" operator as a member function.
		 *
		 * @note Operator allows multiplication of Matrix4 elements.
		 *
		 * @param const Matrix4 object.
		 * @return Matrix4 object.
		 */
		Matrix4 operator*(const Matrix4);
		
		/**
		 * @brief The friend declaration between class Matrix4
		 * and overloaded "*" operator defined outside of the class.
		 *
		 * @note Operator allows multiplication of Matrix4 by Vector4.
		 *
		 * @param const Matrix4 object.
		 * @param const Vector4 object.
		 * @return Vector4 object.
		 */
		friend Vector4 operator*(const Matrix4, const Vector4);

	private:
		//! Two-dimensional Array of double which represent math matrix
		double data[4][4];
};