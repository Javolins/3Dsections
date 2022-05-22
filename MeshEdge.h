#pragma once
/*****************************************************************//**
 * @file   MeshEdge.h
 * @brief  class responsible for storing additional edges created for computations 
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#include "Edge.h"

class MeshEdge : public Edge {
	public:
		MeshEdge(Point start, Point end, Rgb rgb) : Edge(start, end, rgb) {};
};

