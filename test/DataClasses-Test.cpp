/*****************************************************************//**
 * @file   DataClasses-Test.cpp
 * @brief  Unit tests for Point and Color classes.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../test/doctest.h"
#include "../include/DataClasses.h"

#include <array>
#include <algorithm>

TEST_CASE("comparePoints()"){

	std::array<Point, 3> table;

	//
	table = { Point{ 0,0,0 },Point{ 1,0,0 }, Point{ 2,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,0,0 },Point{ 0,1,0 }, Point{ 0,2,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,0 },Point{ 0,0,1 }, Point{ 0,0,2 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 2,0,0 },Point{ 1,0,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,2,0 },Point{ 0,1,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,2 },Point{ 0,0,1 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 1,0,0 },Point{ 2,0,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 1,0,0 });
	REQUIRE(table[2] == Point{ 2,0,0 });

	table = { Point{ 0,1,0 },Point{ 0,2,0 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,1,0 });
	REQUIRE(table[2] == Point{ 0,2,0 });

	table = { Point{ 0,0,1 },Point{ 0,0,2 }, Point{ 0,0,0 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 0,0,0 });
	REQUIRE(table[1] == Point{ 0,0,1 });
	REQUIRE(table[2] == Point{ 0,0,2 });

	//
	table = { Point{ 1,2,3 },Point{ 1,3,2 }, Point{ 1,1,1 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 1,1,1 });
	REQUIRE(table[1] == Point{ 1,2,3 });
	REQUIRE(table[2] == Point{ 1,3,2 });

	table = { Point{ 1,1,1 },Point{ 1,1,3 }, Point{ 1,1,2 } };
	std::sort(table.begin(), table.end(), comparePoints());
	REQUIRE(table[0] == Point{ 1,1,1 });
	REQUIRE(table[1] == Point{ 1,1,2 });
	REQUIRE(table[2] == Point{ 1,1,3 });
}