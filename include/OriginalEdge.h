/*****************************************************************//**
 * @file   Edge.h
 * @brief  class responsible for storing edges from .geo file
 *
 * @author Aleksander Bartoszek
 *********************************************************************/

#pragma once
#include "../include/Edge.h"

class OriginalEdge : public Edge {
	public:
	OriginalEdge(Point start = { 0,0,0 }, Point end = { 0,0,0 }, Color rgb = {0,0,0}) : Edge(start, end, rgb){
	};
};

