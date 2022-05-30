/*****************************************************************//**
 * @file   Matrix4-Test.cpp
 * @brief  Matrix4-Testing
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Matrix4.h"
#include "../include/Vector4.h"

TEST_CASE("Matrix testing") {

	// constructor testing
	Matrix4 testMatrix = Matrix4();

	// getElement() testing
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (i == 3 && j == 3)
				REQUIRE(testMatrix.getElement(i, j) == 1.0);
			else
				REQUIRE(testMatrix.getElement(i, j) == 0.0);
		}

	// setElement() testing
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			testMatrix.setElement(i, j, 5);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			REQUIRE(testMatrix.getElement(i, j) == 5);

	// operator* testing
	Matrix4 m;
	testMatrix = testMatrix * m;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if(j == 3)
				REQUIRE(testMatrix.getElement(i, j) == 5);
			else
				REQUIRE(testMatrix.getElement(i, j) == 0);

	Vector4 v;
	v = testMatrix * v;
	for (int i = 0; i < 4; i++)
		REQUIRE(v.getElement(i) == 5);
}
