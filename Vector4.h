#pragma once
/*****************************************************************//**
 * @file   Vector4.h
 * @brief  class representing vector used in 3D transformations
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

class Vector4 {
	public:
		Vector4() { data[0] = 0.0; data[1] = 0.0; data[2] = 0.0; data[3] = 1.0; };
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
	private:
		/**
	* @brief One dimensional Array of double which contains a vector coordinates X,Y,Z
	*/
		double data[4];
};
