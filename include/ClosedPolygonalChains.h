/*****************************************************************//**
 * @file   ClosedPolygonalChains.h
 * @brief  Class representing edges of a drawn section.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once
#include <vector>
#include "../include/Edge.h"

/**
 * Container for vector of @ref Edge to be drawn on @ref rightPanel.
 */
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