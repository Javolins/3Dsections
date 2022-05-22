/*****************************************************************//**
 * @file   OriginalEdge.h
 * @brief  class responsible for storing edges from .geo file
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#pragma once
#include "Edge.h"

class OriginalEdge : public Edge {
	public:
		OriginalEdge(Point start, Point end, Rgb rgb) : Edge(start, end, rgb) {};
};

