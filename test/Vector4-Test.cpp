/*****************************************************************//**
 * @file   Vector4-Test.cpp
 * @brief  Unit tests for Vector4 class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/Matrix4.h"
#include "../include/Vector4.h"

TEST_CASE("Vector4") {

	// constructor testing
	Vector4 test = Vector4();

	SUBCASE("get()"){
		for( int i = 0; i < 4; i++ ){
			if( i == 3 )
				REQUIRE(test.getElement(i) == 1.0);
			else
				REQUIRE(test.getElement(i) == 0.0);
		}
	}

	SUBCASE("set()"){
		for( int i = 0; i < 4; i++ )
			test.setElement(i, 5);
		for( int i = 0; i < 4; i++ )
			REQUIRE(test.getElement(i) == 5);
	}

	SUBCASE("Specific setters and getters"){
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
	}

	SUBCASE("operator-"){
		Vector4 minus; 
		test.set(4.0, 4.0, 4.0);
		test = test - minus;
		for( int i = 0; i < 3; i++ )
			REQUIRE(test.getElement(i) == 4);
	}
	
	SUBCASE("operator*"){
		test.set(4.0, 4.0, 4.0);
		double x = 2;
		test = test * 2;
		for( int i = 0; i < 3; i++ )
			REQUIRE(test.getElement(i) == 8.0);
	}
}