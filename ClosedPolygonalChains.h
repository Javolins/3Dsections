/*****************************************************************//**
 * @file   ClosedPolygonalChains.h
 * @brief  class representing edges of a drawn section
 *
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include "MeshEdge.h"
#include <vector>

class ClosedPolygonalChains {

	public:
		ClosedPolygonalChains() = default;
		~ClosedPolygonalChains() = default;

		void addEdge(const MeshEdge edge) { edges.push_back(edge); }
		std::vector<MeshEdge> getEdges() const { return edges; }

	private:
		std::vector<MeshEdge> edges;
};