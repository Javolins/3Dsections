/*****************************************************************//**
 * @file   Vector4.h
 * @brief  Class representing vector used in 3D transformations.
 *
 * @author PhD Janusz Malinowski, Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

/**
 * Type representing 4-dimensional vector.
 */
class Vector4 {
	
	public:
		/**
		 * @brief Constructor setting up default values.
		 * 
		 * All values are set to 0 except for element[3] which is set to 1.
		 */
		Vector4() { data[0] = 0.0; data[1] = 0.0; data[2] = 0.0; data[3] = 1.0; };
		//! Method printing formatted data from Vector4.
		void printVector();

		double getElement(int x) const { return data[x]; };
		double getX() const { return data[0]; };
		double getY() const { return data[1]; };
		double getZ() const { return data[2]; };
		void set(double x, double y, double z) { setX(x); setY(y); setZ(z); };
		void setElement(int x, double value) { data[x] = value; };
		void setX(double input) { data[0] = input; };
		void setY(double input) { data[1] = input; };
		void setZ(double input) { data[2] = input; };

		/**
		 * @brief Overloaded "-" operator.
		 *
		 * @note Operator allows substraction of Vector4 coordinates
		 * from other Vector4 coordinates.
		 *
		 * @param Const reference to the Vector4 object.
		 * @return Vector4 object.
		 */
		Vector4 operator-(const Vector4&);
		
		/**
		 * @brief The friend declaration between Vector4 class
		 * and overloaded "*" operator.
		 *
		 * @param Const reference to the Vector4 object.
		 * @param Vector multiplier.
		 *
		 * @return Vector4 object.
		 */
		friend Vector4 operator*(const Vector4&, double);
	
	private:
		//! One dimensional array of doubles containing a vector of coordinates: X,Y,Z.
		double data[4];
};
