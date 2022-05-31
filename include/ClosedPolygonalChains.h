/*****************************************************************//**
 * @file   ClosedPolygonalChains.h
 * @brief  class representing edges of a drawn section
 *
 * @author Michał Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "../include/MeshEdge.h"
#include <vector>

class ClosedPolygonalChains {

	public:
		ClosedPolygonalChains() = default;
		ClosedPolygonalChains(std::vector<Edge> in) : edges(in) {};
		~ClosedPolygonalChains() = default;

		void addEdge(const Edge edge) { edges.push_back(edge); }
		std::vector<Edge> getEdges() const { return edges; }

	private:
		std::vector<Edge> edges;
};