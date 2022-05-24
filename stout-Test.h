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

TEST_CASE("Plane testing") {

	// 2D tests
	Point start{ 0,1,0 };
	Point end{ 1,0,0 };
	Edge line{ start,end,Rgb{0,0,0} };
	Plane plane{ 1 };

	Point result = intersection(line, plane);
	REQUIRE(result.getX() == 0.0);
	REQUIRE(result.getY() == 1.0);
	REQUIRE(result.getZ() == 0.0);
}