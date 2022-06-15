/*****************************************************************//**
 * @file   stout.h
 * @brief  Small library for algorithms used during calculations, also a type of beer.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <omp.h>

#include "../include/ClosedPolygonalChains.h"
#include "../include/Triangle.h"
#include "../include/Ray.h"
#include "../include/Intersections.h"

/**
 * @brief Function finding and removing edges with the same points but in opposite directions.
 * 
 * @param edges Container with edges to check.
 * @return Vector of edges without duplicates.
 */
inline std::vector<Edge> removeReversed(std::vector<Edge> edges){
	std::vector<Edge> e;
	for( auto& x : edges ){
		bool only = true;
		for( auto& y : e )
			if( y == x )
				only = false;
		if( only ) e.push_back(x);
	}
	std::vector<Edge> out(e.begin(), e.end());
	return out;
}

/**
* @brief Function processing edges to unique triangles. 
* 
* Each face is split until its formed from triangles only.
*
* @param origin Vector of edges from the loaded file.
* @return Vector of all triangles forming solid.
*/
inline std::vector<Triangle> triangulateEdges(std::vector<Edge>& origin){
	
	std::vector<Triangle> triangles;
	std::vector<Edge> allEdges = origin;

	for( int i = 0; i < origin.size(); i++ ){
		for( int j = i+1; j < origin.size(); j++ ){
			if( !(origin[i] == origin[j]) ){
				Point xs = origin[i].getStart();
				Point xe = origin[i].getEnd();
				Point ys = origin[j].getStart();
				Point ye = origin[j].getEnd();
				Edge temp;

				if( xs == ys ){
					temp.set(xe, ye);
				} else if( xs == ye ){
					temp.set(xe, ys);
				} else if( xe == ys ){
					temp.set(xs, ye);
				} else if( xe == ye ){
					temp.set(xs, ys);
				} else{
					continue;
				}

				bool add = true;
				for( auto& e : triangles ){
					if( areIntersecting(temp, e.getEdgeA()) || areIntersecting(temp, e.getEdgeB()) || areIntersecting(temp, e.getEdgeC()) ){
						add = false;
						break;
					}
				}
				if( add ){
					triangles.push_back(Triangle(origin[i], origin[j], temp));
					allEdges.push_back(Edge{temp.getStart(), temp.getEnd(), temp.getRgb()});
				}
			}
		}
	}
	std::vector<Triangle> unique;
	for( int i = 0; i < triangles.size(); i++ ){
		bool add = true;
		for( int j = 0; j < unique.size(); j++ ){
			if( triangles[i] == unique[j] ){
				add = false;
				break;
			}
		}
		if( add )
			unique.push_back(triangles[i]);
	}
	for( const auto& org : origin ){
		bool orphan = true;
		for( const auto& trg : unique ){
			if( org == trg.getEdgeA() || org == trg.getEdgeB() || org == trg.getEdgeC() ){
				orphan = false;
				break;
			}
		}
		if( orphan ){
			for( int i = 0; i<allEdges.size(); i++ ){
				Edge second = allEdges[i];
				Edge* third = nullptr;
				if( allEdges[i].getStart() == org.getStart() ){
					third = new Edge{ allEdges[i].getEnd(), org.getEnd() };
				}
				else if( allEdges[i].getStart() == org.getEnd() ){
					third = new Edge{ allEdges[i].getEnd(), org.getStart() };
				} 
				else if( allEdges[i].getEnd() == org.getStart() ){
					third = new Edge{ allEdges[i].getStart(), org.getEnd() };
				} 
				else if( allEdges[i].getEnd() == org.getEnd() ){
					third = new Edge{ allEdges[i].getStart(), org.getStart() };
				}
				if( third ){
					for( int j = 0; j<allEdges.size(); j++ ){
						if( allEdges[j] == *third ){
							unique.push_back(Triangle{org, second, *third});
							i = allEdges.size();
							break;
						}
					}
				}
				delete third;
			}
		}
	}

	return unique;
};

/**
 * @brief Function checking if one of triangles from @ref triangulateIntersectionPoints is inside processed solid 
 * by creating ray from inside this triangle and counting intersections with outside triangles.
 * 
 * @param insideTriangle Triangle to be tested, constructed from points of intersection.
 * @param outsideTriangles Vector of all outer solid triangles
 * @return True if tested triangle is inside processed solid, false otherwise.
 */
inline bool sectionTriangleInsideSolid(const Triangle insideTriangle, const std::vector<Triangle> outsideTriangles){

	Ray ray(insideTriangle.getPointInside());
	int counter = 0;
	
	std::vector<Point> interPoints;
	for( const auto& e : outsideTriangles ){
		auto point = intersection(ray, e.getPlane());
		if( (point != nullptr) && e.containsPoint(*point) )
			if( interPoints.end() == std::find(interPoints.begin(), interPoints.end(), *point) ){
				interPoints.push_back(*point);
				counter++;
			}
	}

	if( counter % 2 == 1 )
		return true;
	else
		return false;
}

/**
 * @brief Function improving on @ref triangulateIntersectionPoints by using statistical analysis of multiple rays instead of relying on one.
 * 
 * @param insideTriangle Triangle to be tested, constructed from points of intersection.
 * @param outsideTriangles Vector of all outer solid triangles
 * @return True if tested triangle is inside processed solid "most of the times", false otherwise.
 */
inline bool sectionTriangleInsideSolidStatistically(const Triangle insideTriangle, const std::vector<Triangle> outsideTriangles){

	Ray ray(insideTriangle.getPointInside());
	int counter = 0;

	int n = 9; // 9 - all non-random combinations
	for( const auto& e : outsideTriangles ){
		int statistic = 0;
		std::vector<Point> interPoints;
		for( int i = 1; i < n; i++ ){
			ray.changeEnd(i);
			auto point = intersection(ray, e.getPlane());
			if( (point != nullptr) && e.containsPoint(*point) )
				if( interPoints.end() == std::find(interPoints.begin(), interPoints.end(), *point) ){
					interPoints.push_back(*point);
					statistic++;
				}
		}
		double certainty = 0.65;
		if( statistic > certainty*n ) counter++;
	}

	if( counter % 2 == 1 )
		return true;
	else
		return false;
}


/**
 * @brief Function determining if 2 points on intersection plane should be connected by checking if all 4 of their points are on the same plane.
 * 
 * @note Fails to recognize opposing parallel edges in a cube connecting squares diagonally.
 * 
 * @param a One of original edges.
 * @param b Another one of original edges.
 * @return True if 4 points are on the same plane, false otherwise.
 */
inline bool samePlaneEdges(const Edge& a, const Edge& b){
	std::array<double, 3> aVec = a.getDirectionalVector();
	std::array<double, 3> bVec = b.getDirectionalVector();
	std::array<double, 3> crossProduct = cross(aVec, bVec);
	if( crossProduct[0] == 0 && crossProduct[1] == 0 && crossProduct[2] == 0 ){
		bVec = std::array<double, 3> {
			a.getEnd().getX() - b.getStart().getX(),
				a.getEnd().getY() - b.getStart().getY(),
				a.getEnd().getZ() - b.getStart().getZ()
		};
		crossProduct = cross(aVec, bVec);
	}

	double D = -(crossProduct[0]*b.getEnd().getX() + crossProduct[1]*b.getEnd().getY() + crossProduct[2]*b.getEnd().getZ());
	Plane commonPlane{ crossProduct[0], crossProduct[1], crossProduct[2], D };

	if( commonPlane.containsPoint(a.getStart()) )
		if( commonPlane.containsPoint(a.getEnd()) )
			if( commonPlane.containsPoint(b.getStart()) )
				if( commonPlane.containsPoint(b.getEnd()) )
					return true;
	return false;
}

/**
 * @brief Calculates edges of the section using ray casting.
 * 
 * @param in Triangles created from points of intersection.
 * @param out Triangles from outer faces of processed solid.
 * @param statistical If true uses @ref sectionTriangleInsideSolidStatistically, otherwise @ref sectionTriangleInsideSolid.
 * @return ClosedPolygonalChains object containing all edges of the section.
 */
inline ClosedPolygonalChains rayTrianglesSection(const std::vector<Triangle> in, const std::vector<Triangle> out, bool statistical){

	std::vector<Triangle> unique = in;

	for( int i = 0; i < in.size(); i++ ){

		bool a_inside = false;
		if( statistical ) {
			if( sectionTriangleInsideSolidStatistically(in[i], out) )
				a_inside = true;
		}	
		else{
			if( sectionTriangleInsideSolid(in[i], out) )
				a_inside = true;
		}

		for( int j = i+1; j < in.size(); j++ ){

			bool b_inside = false;
			if( statistical ) {
				if( sectionTriangleInsideSolidStatistically(in[i], out) )
					b_inside = true;
			}	
			else{
				if( sectionTriangleInsideSolid(in[i], out) )
					b_inside = true;
			}

			if( a_inside == b_inside ){
				if( in[i].getEdgeA() == in[j].getEdgeA() ){
					unique[i].setEdgeA();
					unique[j].setEdgeA();
				} else if( in[i].getEdgeA() == in[j].getEdgeB() ){
					unique[i].setEdgeA();
					unique[j].setEdgeB();
				} else if( in[i].getEdgeA() == in[j].getEdgeC() ){
					unique[i].setEdgeA();
					unique[j].setEdgeC();
				} else if( in[i].getEdgeB() == in[j].getEdgeA() ){
					unique[i].setEdgeB();
					unique[j].setEdgeA();
				} else if( in[i].getEdgeB() == in[j].getEdgeB() ){
					unique[i].setEdgeB();
					unique[j].setEdgeB();
				} else if( in[i].getEdgeB() == in[j].getEdgeC() ){
					unique[i].setEdgeB();
					unique[j].setEdgeC();
				} else if( in[i].getEdgeC() == in[j].getEdgeA() ){
					unique[i].setEdgeC();
					unique[j].setEdgeA();
				} else if( in[i].getEdgeC() == in[j].getEdgeB() ){
					unique[i].setEdgeC();
					unique[j].setEdgeB();
				} else if( in[i].getEdgeC() == in[j].getEdgeC() ){
					unique[i].setEdgeC();
					unique[j].setEdgeC();
				}
			} else{

				if( !a_inside ){
					unique[i].setEdgeA();
					unique[i].setEdgeB();
					unique[i].setEdgeC();
				}
				if( !b_inside ){
					unique[j].setEdgeA();
					unique[j].setEdgeB();
					unique[j].setEdgeC();
				}
			}
		}
	}

	std::vector<Edge> polyLine;
	for( auto& e: unique ){
		polyLine.push_back(e.getEdgeA());
		polyLine.push_back(e.getEdgeB());
		polyLine.push_back(e.getEdgeC());
	}
	return ClosedPolygonalChains{ polyLine };
}

/**
 * @brief Function checking if two points on the intersection are created by the same triangle, if so they should be connected.
 * 
 * @param out Solid processed to be formed only by triangles.
 * @param plane Plane intersecting with given solid.
 * @return ClosedPolygonalChains object containing all edges of the section.
 */
inline ClosedPolygonalChains quickSection(const std::vector<Triangle> out, const Plane& plane){

	std::vector<Edge> lines;
	for( const auto& e : out ){
		if( intersection(e.getEdgeA(), plane) && intersection(e.getEdgeB(), plane) )
			lines.push_back(Edge{ *intersection(e.getEdgeA(), plane), *intersection(e.getEdgeB(), plane) });
		if( intersection(e.getEdgeA(), plane) && intersection(e.getEdgeC(), plane) )
			lines.push_back(Edge{ *intersection(e.getEdgeA(), plane), *intersection(e.getEdgeC(), plane) });
		if( intersection(e.getEdgeB(), plane) && intersection(e.getEdgeC(), plane) )
			lines.push_back(Edge{ *intersection(e.getEdgeB(), plane), *intersection(e.getEdgeC(), plane) });
	}
	return ClosedPolygonalChains{ lines };
}

/**
 * @brief First prototype of @ref quickSection, contains multiple misconceptions.
 * 
 * @param out Solid processed to be formed only by triangles.
 * @param plane Plane intersecting with given solid.
 * @return ClosedPolygonalChains object containing all edges of the section.
 */
inline ClosedPolygonalChains quickSectionBeta(const std::vector<Triangle> out, const Plane& plane){

	std::vector<Edge> fromTriangles;
	for( const auto& e: out ){
		fromTriangles.push_back(e.getEdgeA());
		fromTriangles.push_back(e.getEdgeB());
		fromTriangles.push_back(e.getEdgeC());
	}
	std::vector<Edge> lines;
	for( int i = 0; i < fromTriangles.size(); i++ ){
		for( int j = i+1; j < fromTriangles.size(); j++ ){
			if( fromTriangles[i] == fromTriangles[j] )
				continue;
			bool flag = false;
			if( intersection(fromTriangles[i], plane) && intersection(fromTriangles[j], plane) ){
				for( const auto& e : lines ){
					if( areIntersecting(Edge{ *intersection(fromTriangles[i], plane), *intersection(fromTriangles[j], plane) }, e) )
						flag = true;
				}
				if( flag ) continue;

				if( fromTriangles[i].getStart() == fromTriangles[j].getStart() )
					lines.push_back(Edge{ *intersection(fromTriangles[i], plane), *intersection(fromTriangles[j], plane) });
				else if( fromTriangles[i].getStart() == fromTriangles[j].getEnd() )
					lines.push_back(Edge{ *intersection(fromTriangles[i], plane), *intersection(fromTriangles[j], plane) });
				else if( fromTriangles[i].getEnd() == fromTriangles[j].getStart() )
					lines.push_back(Edge{ *intersection(fromTriangles[i], plane), *intersection(fromTriangles[j], plane) });
				else if( fromTriangles[i].getEnd() == fromTriangles[j].getEnd() )
					lines.push_back(Edge{ *intersection(fromTriangles[i], plane), *intersection(fromTriangles[j], plane) });
			}
		}
	}
	return ClosedPolygonalChains{ lines };
}

/**
 * @brief First prototype of function checking if two points on the section should be connected.
 * 
 * It checks if there is an edge between ends of edges creating intersection points. If there is, points are being connected.
 * 
 * @param intersections Points of intersection with edges that created them.
 * @param origin Edges of the solid.
 * @return ClosedPolygonalChains object containing all edges of the section.
 */
inline ClosedPolygonalChains connectNeighboursSection(const std::vector<std::pair<const Edge*, Point>> intersections, const std::vector<Edge> origin){
	std::vector<Edge> polyLine;

	#pragma omp parallel for collapse(3)
	for( int i = 0; i < intersections.size() - 1; i++ ){
		for( int j = i+1; j < intersections.size(); j++ ){
			for( int k = 0; k < origin.size(); k++ ){
				Edge* e;
				bool firstCondition = false;
				bool secondCondition = false;
				// 4 possible connections, both ways
				if( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getStart() )	firstCondition = true;
				else if( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getEnd() )		firstCondition = true;
				else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getStart() )	firstCondition = true;
				else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getEnd() )		firstCondition = true;

				else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getStart() )	firstCondition = true;
				else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getEnd() )		firstCondition = true;
				else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getStart() )	firstCondition = true;
				else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getEnd() )		firstCondition = true;


				if( samePlaneEdges(*(intersections[i].first), *(intersections[j].first)) ) secondCondition = true;

				if( firstCondition && secondCondition ){
					e = &Edge(intersections[i].second, intersections[j].second, Color(0, 0, 0));
				} else continue;

				#pragma omp critical
				polyLine.push_back(*e);
			}
		}
	}
	std::vector<Edge> out(polyLine.begin(), polyLine.end());
	ClosedPolygonalChains cpc = ClosedPolygonalChains(out);
	return cpc;
}

/**
 * @brief Function creating vector of triangles from points of intersection to check if points should be connected on the section.
 *
 * @param isections Points to connect with edges creating them.
 * @return Vector of necessary triangles between given points.
 */
inline std::vector<Triangle> triangulateIntersectionPoints(std::vector<std::pair<const Edge*, Point>> isections){
	std::vector<Triangle> unique;

	for( int i = 0; i < isections.size(); i++ ){
		Point a = isections[i].second;
		for( int j = i+1; j < isections.size(); j++ ){
			Point b = isections[j].second;
			for( int k = j+1; k < isections.size(); k++ ){
				Point c = isections[k].second;

				Edge ab(a, b);
				Edge bc(b, c);
				Edge ca(c, a);
				Triangle temp(ab, bc, ca);
				bool add = true;
				for( auto& e : unique ){
					if( areIntersecting(ab, e.getEdgeA()) || areIntersecting(ab, e.getEdgeB()) || areIntersecting(ab, e.getEdgeC()) ){
						add = false;
						break;
					} else if( areIntersecting(bc, e.getEdgeA()) || areIntersecting(bc, e.getEdgeB()) || areIntersecting(bc, e.getEdgeC()) ){
						add = false;
						break;
					} else if( areIntersecting(ca, e.getEdgeA()) || areIntersecting(ca, e.getEdgeB()) || areIntersecting(ca, e.getEdgeC()) ){
						add = false;
						break;
					} else if( temp == e ){
						add = false;
						break;
					}
				}

				if( add ){
					unique.push_back(Triangle(ab, bc, ca));
				}
			}
		}
	}

	return unique;
}

/**
 * @brief Function creating additional edges to make triangles from given edges. 
 * 
 * Currently unused, modified version exist in function making triangles.
 *
 * @param origin Vector of edges from the file.
 * @return Vector of all original and additional edges.
 */
inline std::vector<Edge> triangulate(std::vector<Edge>& origin){
	std::vector<Point> points;
	for( const auto& a : origin ){
		points.push_back(a.getStart());
		points.push_back(a.getEnd());
	}
	std::vector<Edge> allEdges;

	//foreach point
	for( const auto& p : points ){
		//filter appropriate edges
		std::vector<Edge> temp;
		for( auto& e : origin ){
			if( e.getStart() == p || e.getEnd() == p ){
				temp.push_back(e);
			}
		}
		//foreach pair of edges
		for( auto& x : temp ){
			for( const auto& y : temp ){
				if( !(x == y) ){
					//find 3 edge to form triangle
					//add edges
					if( x.getStart() == p && y.getStart() == p )	allEdges.push_back(Edge(x.getEnd(), y.getEnd(), Color(0, 0, 0)));
					else if( x.getStart() == p && y.getEnd() == p )	allEdges.push_back(Edge(x.getEnd(), y.getStart(), Color(0, 0, 0)));
					else if( x.getEnd() == p && y.getStart() == p )	allEdges.push_back(Edge(x.getStart(), y.getEnd(), Color(0, 0, 0)));
					else if( x.getEnd() == p && y.getEnd() == p )	allEdges.push_back(Edge(x.getStart(), y.getStart(), Color(0, 0, 0)));
					// else throw new Exception :P
				}
			}
		}
	}
	std::vector<Edge> out(allEdges.begin(), allEdges.end());
	removeReversed(out);
	return out;
};