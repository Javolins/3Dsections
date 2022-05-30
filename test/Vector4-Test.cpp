/*****************************************************************//**
 * @file   Vector4-Test.cpp
 * @brief  Vector4 testing
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Matrix4.h"
#include "../include/Vector4.h"

TEST_CASE("Vector testing") {

	// constructor testing
	Vector4 test = Vector4();

	// get() testing
	for (int i = 0; i < 4; i++) {
		if (i == 3)
			REQUIRE(test.getElement(i) == 1.0);
		else
			REQUIRE(test.getElement(i) == 0.0);
	}

	// set() testing
	for (int i = 0; i < 4; i++)
			test.setElement(i, 5);
	for (int i = 0; i < 4; i++)
			REQUIRE(test.getElement(i) == 5);

	// set and get for X Y Z
	test.setX(3.0);
	test.setY(3.0);
	test.setZ(3.0);
	REQUIRE(test.getX() == 3.0);
	REQUIRE(test.getY() == 3.0);
	REQUIRE(test.getZ() == 3.0);
	test.set(4.0, 4.0, 4.0);
	REQUIRE(test.getX() == 4.0);
	REQUIRE(test.getY() == 4.0);
	REQUIRE(test.getZ() == 4.0);

	// operator- testing
	Vector4 minus;
	test = test - minus;
	for (int i = 0; i < 4; i++)
		REQUIRE(test.getElement(i) == 4);

	// operator* testing
	double x = 2;
	test = test * 2;
	for (int i = 0; i < 4; i++)
		REQUIRE(test.getElement(i) == 8.0);
}