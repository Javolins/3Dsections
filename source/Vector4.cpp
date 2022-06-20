/*****************************************************************//**
 * @file   Vector4.cpp
 * @brief  Implementation of methods used in the Vector4 class.
 *
 * @author PhD Janusz Malinowski, Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#include "../include/Vector4.h"
#include "../include/Matrix4.h"
#include <stdio.h>

void Vector4::printVector() {
	printf("(%2.3lf,%2.3lf,%2.3lf,%2.3lf)\n", data[0], data[1], data[2], data[3]);
}

Vector4 Vector4::operator- (const Vector4& gVector) {
	unsigned int i;
	Vector4 Result;
	for (i = 0; i < 4; i++) Result.setElement(i, getElement(i) - gVector.getElement(i));
	return Result;
}

Vector4 operator* (const Vector4& gVector, double val) {
	unsigned int i;
	Vector4 Result;
	for (i = 0; i < 4; i++) Result.setElement(i, gVector.getElement(i) * val);
	return Result;
}