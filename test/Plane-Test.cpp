/*****************************************************************//**
 * @file   Plane-Test.cpp
 * @brief  Unit tests for Plane class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Plane.h"

TEST_CASE("Plane") {

	// default constructor testing
	Plane test = Plane();

	SUBCASE("get()"){
		for( int i = 0; i < 4; i++ )
			REQUIRE(test.getParameter(i) == 0.0);
	}

	SUBCASE("set()"){
		for( int i = 0; i < 4; i++ ){
			test.setParameter(i, i + 0.1);
			REQUIRE(test.getParameter(i) == i + 0.1);
		}
	}

	SUBCASE("Specific setters and getters"){

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
	}

	SUBCASE("getNormalVector()"){
		test.set(1.0, 2.0, 3.0, 4.0);
		std::array<double, 3> vec = test.getNormalVector();
		REQUIRE(vec[0] == 1.0);
		REQUIRE(vec[1] == 2.0);
		REQUIRE(vec[2] == 3.0);
	}
}