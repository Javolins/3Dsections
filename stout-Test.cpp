/*****************************************************************//**
 * @file   stout-Test.h
 * @brief
 *
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "doctest.h"
#include "stout.h"
#include <iostream>

TEST_CASE("intersection() testing") {

	// basic planes
	Plane yOz{ 1 };
	Plane xOy{ 0,0,1 };
	Plane xOz{ 0,1 };

	// simple lines
	Edge y_eq_z{ Point{ 0,1,0 }, Point{ 0,0,1 }, Color{0,0,0} };
	Edge x_eq_y{ Point{ 1,0,0 }, Point{ 0,1,0 }, Color{0,0,0} };
	Edge x_eq_z{ Point{ 1,0,0 }, Point{ 0,0,1 }, Color{0,0,0} };
	Edge x_eq_y_eq_z{ Point{ 0,0,0 }, Point{ 1,1,1 }, Color{0,0,0} };

	// basic tests
	REQUIRE((*intersection(x_eq_y, yOz) == Point{ 0,1,0 }));
	REQUIRE((*intersection(x_eq_z, yOz) == Point{ 0,0,1 }));
	REQUIRE((*intersection(x_eq_y_eq_z, yOz) == Point{ 0,0,0 }));
	REQUIRE((intersection(y_eq_z, yOz) == nullptr));

	REQUIRE((*intersection(y_eq_z, xOy) == Point{ 0,1,0 }));
	REQUIRE((*intersection(x_eq_z, xOy) == Point{ 1,0,0 }));
	REQUIRE((*intersection(x_eq_y_eq_z, xOy) == Point{ 0,0,0 }));
	REQUIRE((intersection(x_eq_y, xOy) == nullptr));

	REQUIRE((*intersection(y_eq_z, xOz) == Point{ 0,0,1 }));
	REQUIRE((*intersection(x_eq_y, xOz) == Point{ 1,0,0 }));
	REQUIRE((*intersection(x_eq_y_eq_z, xOz) == Point{ 0,0,0 }));
	REQUIRE((intersection(x_eq_z, xOz) == nullptr));
}