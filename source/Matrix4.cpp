/*****************************************************************//**
 * @file   Matrix4.cpp
 * @brief  Implementation of methods used in the Matrix4 class.
 *
 * @author PhD Janusz Malinowski, Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#include "../include/Matrix4.h"
#include <stdio.h>

Matrix4::Matrix4() {
	data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0; data[0][3] = 0.0;
	data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0; data[1][3] = 0.0;
	data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 0.0; data[2][3] = 0.0;
	data[3][0] = 0.0; data[3][1] = 0.0; data[3][2] = 0.0; data[3][3] = 1.0;
}

void Matrix4::printMatrix() {
	printf("\n|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[0][0], data[0][1], data[0][2], data[0][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[1][0], data[1][1], data[1][2], data[1][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n", data[2][0], data[2][1], data[2][2], data[2][3]);
	printf("|%2.3lf,%2.3lf,%2.3lf,%2.3lf|\n\n", data[3][0], data[3][1], data[3][2], data[2][3]);
}

void Matrix4::setAllElements(double value){
	data[0][0] = 5.0; data[0][1] = 5.0; data[0][2] = 5.0; data[0][3] = 5.0;
	data[1][0] = 5.0; data[1][1] = 5.0; data[1][2] = 5.0; data[1][3] = 5.0;
	data[2][0] = 5.0; data[2][1] = 5.0; data[2][2] = 5.0; data[2][3] = 5.0;
	data[3][0] = 5.0; data[3][1] = 5.0; data[3][2] = 5.0; data[3][3] = 5.0;
}

Matrix4 Matrix4::operator* (const Matrix4 gMatrix) {
	int i; 
	int j; 
	int k;
	Matrix4 tmp;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			tmp.setElement(i, j, 0.0);
			for (k = 0; k < 4; k++)
				tmp.setElement(i, j, tmp.getElement(i, j) + (getElement(i, k) * gMatrix.getElement(k, j)));
		}
	return tmp;
}

Vector4 operator* (const Matrix4 gMatrix, const Vector4 gVector) {
	unsigned int i, j;
	Vector4 tmp;
	for (i = 0; i < 4; i++) {
		tmp.setElement(i, 0.0);
		for (j = 0; j < 4; j++)
			tmp.setElement(i, tmp.getElement(i) + (gMatrix.getElement(i, j) * gVector.getElement(j)));
	}
	return tmp;
}