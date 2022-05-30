/*****************************************************************//**
 * @file   Plane-Test.cpp
 * @brief  Plane testing
 *
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "doctest.h"
#include "Plane.h"

TEST_CASE("Plane testing") {

	// default constructor testing
	Plane test = Plane();

	// get() testing
	for (int i = 0; i < 4; i++)
		REQUIRE(test.getParameter(i) == 0.0);

	// set() testing
	for (int i = 0; i < 4; i++) {
		test.setParameter(i, i + 0.1);
		REQUIRE(test.getParameter(i) == i + 0.1);
	}

	// set and get for A B C D
	test.setA(21.37);
	test.setB(21.37);
	test.setC(21.37);
	test.setD(21.37);
	REQUIRE(test.getA() == 21.37);
	REQUIRE(test.getB() == 21.37);
	REQUIRE(test.getC() == 21.37);
	REQUIRE(test.getD() == 21.37);
	test.set(42.0, 42.0, 42.0, 42.0);
	REQUIRE(test.getA() == 42.0);
	REQUIRE(test.getB() == 42.0);
	REQUIRE(test.getC() == 42.0);
	REQUIRE(test.getD() == 42.0);

	// getNormalVector() testing
	test.set(1.0, 2.0, 3.0, 4.0);
	std::array<double, 3> vec = test.getNormalVector();
	REQUIRE(vec[0] == 1.0);
	REQUIRE(vec[1] == 2.0);
	REQUIRE(vec[2] == 3.0);
}