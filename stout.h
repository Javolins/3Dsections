/*****************************************************************//**
 * @file   stout.h
 * @brief  small lib for algorithms used during calculating sections
 *
 * @author Micha� Rutkowski, Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <set>
#include <utility>
#include "OriginalEdge.h"

/**
 * Robi mi si� niedobrze od z�o�ono�ci tej funkcji, ale wmawiam sobie �e to tymczasowe.
 */
std::vector<Edge> mesh(std::vector<OriginalEdge> origin) {
	
	std::set<Point> uniquePoints;
	for (auto a : origin) {
		uniquePoints.insert(a.getStart());
		uniquePoints.insert(a.getEnd());
	}

	std::pair<OriginalEdge, OriginalEdge> pair();
	//TODO
};
