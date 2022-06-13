/*****************************************************************//**
 * @file   VectorOperations.h
 * @brief  small library of mathematical functions operating on vectors
 *
 * @author Michał Rutkowski @P4ndaM1x
 * @date   June 2022
 *********************************************************************/

#pragma once

#include <array>

 /**
  * @brief Simple signum function.
  *
  * @param val Checked value.
  * @return 1 if @ref val is positive, -1 if @ref val is negative, 0 if @ref val is a zero
  */
inline int sgn(double val){
	return (val>0) - (val<0);
}

/**
 * @brief Calculates the cross product of 2 given vectors.
 * 
 * @param a 3-dimensional vector
 * @param b 3-dimensional vector
 * @return Cross product of provided vectors
 */
inline std::array<double, 3> cross(std::array<double, 3> a, std::array<double, 3> b){
	std::array<double, 3> result;
	result[0] = a[1]*b[2] - a[2]*b[1];
	result[1] = a[2]*b[0] - a[0]*b[2];
	result[2] = a[0]*b[1] - a[1]*b[0];
	return result;
}

/**
 * @brief Calculates the norm of a vector.
 *
 * @param vec 3-dimensional vector.
 * @return Norm of the provided vector.
 */
inline double norm(std::array<double, 3> vec){
	return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
}

/**
 * @brief Calculates the dot product of two vectors.
 *
 * @param a First 3-dimensional vector.
 * @param b Second 3-dimensional vector.
 * @return Dot product of provided vectors.
 */
inline double dot(std::array<double, 3> a, std::array<double, 3> b){
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}
