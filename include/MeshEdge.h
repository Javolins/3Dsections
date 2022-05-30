/*****************************************************************//**
 * @file   MeshEdge.h
 * @brief  class responsible for storing additional edges created for computations 
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#pragma once
#include "../include/Edge.h"

class MeshEdge : public Edge {
	public:
		MeshEdge(Point start, Point end, Color rgb) : Edge(start, end, rgb) {};
};

