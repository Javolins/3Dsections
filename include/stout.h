/*****************************************************************//**
 * @file   stout.h
 * @brief  small lib for algorithms used during calculating sections
 *
 * @author Michał Rutkowski, Aleksander Bartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

#include <vector>
#include <array>
#include <set>
#include <map>
#include <memory>
#include <cmath>
#include <omp.h>
#include "../include/OriginalEdge.h"
#include "../include/MeshEdge.h"
#include "../include/Edge.h"
#include "../include/Plane.h"
#include "../include/ClosedPolygonalChains.h"
#include "../include/Triangle.h"
#include "../include/Ray.h"



inline std::vector<Edge> removeReversed(std::vector<Edge> edges){
	std::vector<Edge> e;
	for( auto& x : edges ){
		bool only = true;
		for( auto& y : e )
			if( y.getStart() == x.getEnd() && y.getEnd() == x.getStart() )
				only = false;
		if( only ) e.push_back(x);
	}
	std::vector<Edge> out(e.begin(), e.end());
	return out;
}

/**
 * .@brief function triangulating given solid for processing
 * 
 * @param origin vector of edges from the file
 * @return vector of all original and virtual edges
 * 
 */
inline std::vector<Edge> mesh(std::vector<OriginalEdge>& origin) {
	std::vector<Point> points;
	for (const auto& a : origin) {
		points.push_back(a.getStart());
		points.push_back(a.getEnd());
	}
	std::vector<Edge> allEdges;

	//foreach point
	for (const auto& p : points) {
		//filter appropriate edges
		std::vector<Edge> temp;
		for (auto& e : origin) {
			if (e.getStart() == p || e.getEnd() == p) {
				temp.push_back(e);
			}
		}
		//foreach pair of edges
		for (auto& x : temp) {
			for (const auto& y : temp) {
				if (!(x == y)) {
					//find 3 edge to form triangle
					//add edges
					if (x.getStart() == p && y.getStart() == p)		allEdges.push_back(MeshEdge(x.getEnd(), y.getEnd(), Color(0,0,0)));
					else if (x.getStart() == p && y.getEnd() == p)	allEdges.push_back(MeshEdge(x.getEnd(), y.getStart(), Color(0, 0, 0)));
					else if (x.getEnd() == p && y.getStart() == p)	allEdges.push_back(MeshEdge(x.getStart(), y.getEnd(), Color(0, 0, 0)));
					else if (x.getEnd() == p && y.getEnd() == p)	allEdges.push_back(MeshEdge(x.getStart(), y.getStart(), Color(0, 0, 0)));
					// else throw new Exception :P
				}
			}
		}
	}
	std::vector<Edge> out(allEdges.begin(), allEdges.end());
	removeReversed(out);
	return out;
};

/**
 * @brief Calculates the dot product of two vectors.
 * 
 * @param a First 3-dimensional vector.
 * @param b Second 3-dimensional vector.
 * @return Dot product of provided vectors.
 */
inline double dot(std::array<double, 3> a, std::array<double, 3> b){
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

//inline std::array<double, 3> cross(std::array<double, 3> a, std::array<double, 3> b){
//	std::array<double, 3> result;
//	result[0] = a[1]*b[2] - a[2]*b[1];
//	result[1] = a[2]*b[0] - a[0]*b[2];
//	result[2] = a[0]*b[1] - a[1]*b[0];
//	return result;
//}
//
///**
// * @brief Calculates the norm of a vector.
// * 
// * @param vec 3-dimensional vector.
// * @return Norm of the provided vector.
// */
//inline double norm(std::array<double, 3> vec){
//	return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
//}

/**
 * @brief Simple signum function.
 * 
 * @param val Checked value.
 * @return 1 if @ref val is positive, -1 if @ref val is negative, 0 if @ref val is a zero
 */
inline int sgn(double val){
	return (val>0) - (val<0);
}

/**
 * @brief Calculates the intersection point of @ref line and @ref plane
 * 
 * @param line Segment of the line used in an algorithm.
 * @param plane Plane used in an algorithm.
 * @return If there is exactly one point of itersection it will be returned, in other case - nullptr.
 */
inline std::unique_ptr<Point> intersection(const Edge& line, const Plane& plane){

	// check if edge intersects plane
	Point onPlane{ 0,0,0 };
	if( plane.getA() != 0 )
		onPlane.setX( -plane.getD()/plane.getA() );
	else if( plane.getB() != 0 )
		onPlane.setY( -plane.getD()/plane.getB() );
	else if( plane.getC() != 0 )
		onPlane.setZ( -plane.getD()/plane.getC() );
	else return nullptr;

	Point start = line.getStart();
	Point end = line.getEnd();

	while( start == onPlane || end == onPlane ){
		srand(time(nullptr));
		onPlane.set( onPlane.getX()+rand()%7-3, onPlane.getX()+rand()%7-3, onPlane.getX()+rand()%7-3);
		if( plane.getA() != 0 )
			onPlane.setX( -(plane.getD()+plane.getB()*onPlane.getY()+plane.getC()*onPlane.getZ()) / plane.getA() );
		else if( plane.getB() != 0 )
			onPlane.setY( -(plane.getD()+plane.getA()*onPlane.getX()+plane.getC()*onPlane.getZ()) / plane.getB() );
		else if( plane.getC() != 0 )
			onPlane.setZ( -(plane.getD()+plane.getA()*onPlane.getX()+plane.getB()*onPlane.getY()) / plane.getC() );
		else return nullptr;
	}

	std::array<double, 3> startVec{ start.getX() - onPlane.getX(), start.getY() - onPlane.getY(), start.getZ() - onPlane.getZ() };
	std::array<double, 3> endVec{ end.getX() - onPlane.getX(), end.getY() - onPlane.getY(), end.getZ() - onPlane.getZ() };
	std::array<double, 3> planeVec{ plane.getNormalVector() };

	if( sgn(dot(startVec, planeVec)) == sgn(dot(endVec, planeVec)) ) 
		return nullptr;

	// calculate intersection point
	std::array<double, 3> lineVec = line.getDirectionalVector();

	double t = -(plane.getA() * start.getX() + plane.getB() * start.getY() + plane.getC() * start.getZ() + plane.getD())
		/ (plane.getA() * lineVec[0] + plane.getB() * lineVec[1] + plane.getC() * lineVec[2]);

	return std::unique_ptr<Point>{
		new Point{
			static_cast<float>(start.getX() + t * lineVec[0]),
			static_cast<float>(start.getY() + t * lineVec[1]),
			static_cast<float>(start.getZ() + t * lineVec[2])
		}
	};
}

/**
 * @brief DO TESTÓW!!!
 * 
 * @param originalEdges
 * @param plane
 * @return 
 */
 inline std::vector<std::pair<const Edge*, Point>> intersectionPoints(const std::vector<OriginalEdge>& originalEdges, const Plane& plane){
	
	 std::vector<std::pair<const Edge*, Point>> intersections;
	for( auto& edge : originalEdges ){
		std::unique_ptr<Point> ptr{ intersection(edge, plane) };
		if( ptr != nullptr )
			intersections.push_back({ &edge, *ptr });
	}
	return intersections;
}

 inline bool connect(const Edge& a, const Edge& b);
 /**
  * @brief Functions checking which intersections with a plane would create a section
  * 
  * @param intersections - map of intersections with appropriate point of intersection and edge intersecting
  * @param origin - original edges from file
  * @return polygonal chain to be drawn as intersection border
  */
 inline ClosedPolygonalChains polygonalChain(const std::vector<std::pair<const Edge*, Point>> intersections, const std::vector<OriginalEdge> origin) {
	 std::vector<Edge> polyLine;

	 #pragma omp parallel for collapse(3)
	 for( int i = 0; i < intersections.size() - 1; i++) {
		 for( int j = i+1; j < intersections.size(); j++ ){
			 for( int k = 0; k < origin.size(); k++ ){
				 Edge* e;
				 bool firstCondition = false;
				 bool secondCondition = false;
				 // 4 possible connections, both ways
				 if		( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getStart() )	firstCondition = true;
				 else if( origin[k].getStart() == intersections[i].first->getStart()	&& origin[k].getEnd() == intersections[j].first->getEnd() )		firstCondition = true;
				 else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getStart() )	firstCondition = true;
				 else if( origin[k].getStart() == intersections[i].first->getEnd()		&& origin[k].getEnd() == intersections[j].first->getEnd() )		firstCondition = true;

				 else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getStart() )	firstCondition = true;
				 else if( origin[k].getStart() == intersections[j].first->getStart()	&& origin[k].getEnd() == intersections[i].first->getEnd() )		firstCondition = true;
				 else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getStart() )	firstCondition = true;
				 else if( origin[k].getStart() == intersections[j].first->getEnd()		&& origin[k].getEnd() == intersections[i].first->getEnd() )		firstCondition = true;


				 if( connect(*(intersections[i].first), *(intersections[j].first)) ) secondCondition = true;

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

 inline bool connect(const Edge& a, const Edge& b){
	std::array<double, 3> aVec = a.getDirectionalVector();
	std::array<double, 3> bVec = b.getDirectionalVector();
	
	std::array<double, 3> crossProduct = cross(aVec,bVec);
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

 inline bool areIntersecting(const Edge& a, const Edge& b){

	 std::array<double, 3> aVec = a.getDirectionalVector();
	 std::array<double, 3> bVec = b.getDirectionalVector();

	 std::array<double, 3> crossProduct = cross(aVec, bVec);
	 if( crossProduct[0] == 0 && crossProduct[1] == 0 && crossProduct[2] == 0 )
		 return false;

	 Point A = a.getStart();
	 Point B = a.getEnd();
	 Point C = b.getStart();
	 Point D = b.getEnd();

	 double t = 0, s = 0;
	 if( !(((A.getX()-B.getX()) == 0 || (D.getY()-C.getY()) == 0) && ((A.getY()-B.getY()) == 0 || (D.getX()-C.getX()) == 0)) )
		 if( (A.getX() - B.getX()) ){

			 s = ((A.getX()-B.getX())*(D.getY()-B.getY()) - (A.getY()-B.getY())*(D.getX()-B.getX()))
				 / ((A.getX()-B.getX())*(D.getY()-C.getY()) - (A.getY()-B.getY())*(D.getX()-C.getX()));
			 t = ((D.getX()-B.getX()) - s*(D.getX()-C.getX())) / (A.getX() - B.getX());

			 if( t*(A.getZ() - B.getZ()) + s*(D.getZ()-C.getZ()) != D.getZ()-B.getZ() )
				 return false;
		 }
	 if( !(((A.getX()-B.getX()) == 0 || (D.getZ()-C.getZ()) == 0) && ((A.getZ()-B.getZ()) == 0 || (D.getX()-C.getX()) == 0)) )
		 if( (A.getX() - B.getX()) ){

			 s = ((A.getX()-B.getX())*(D.getZ()-B.getZ()) - (A.getZ()-B.getZ())*(D.getX()-B.getX()))
				 / ((A.getX()-B.getX())*(D.getZ()-C.getZ()) - (A.getZ()-B.getZ())*(D.getX()-C.getX()));
			 t = ((D.getX()-B.getX()) - s*(D.getX()-C.getX())) / (A.getX() - B.getX());

			 if( t*(A.getY() - B.getY()) + s*(D.getY()-C.getY()) != D.getY()-B.getY() )
				 return false;
		 }
	 if( !(((A.getY()-B.getY()) == 0 || (D.getZ()-C.getZ()) == 0) && ((A.getZ()-B.getZ()) == 0 || (D.getY()-C.getY()) == 0)) )
		 if( (A.getY() - B.getY()) ){

			 s = ((A.getY()-B.getY())*(D.getZ()-B.getZ()) - (A.getZ()-B.getZ())*(D.getY()-B.getY()))
				 / ((A.getY()-B.getY())*(D.getZ()-C.getZ()) - (A.getZ()-B.getZ())*(D.getY()-C.getY()));
			 t = ((D.getY()-B.getY()) - s*(D.getY()-C.getY())) / (A.getY() - B.getY());

			 if( t*(A.getX() - B.getX()) + s*(D.getX()-C.getX()) != D.getX()-B.getX() )
				 return false;
		 }

	 if( 0 < t && t < 1 && 0 < s && s < 1 )
		 return true;
	 return false;

 }

 /**
 * .@brief function triangulating given solid for processing
 *
 * @param origin vector of edges from the file
 * @return vector of all triangles forming solid
 *
 */
 inline std::vector<Triangle> meshTriangles(std::vector<OriginalEdge>& origin){
	 std::vector<Point> points;
	 for( const auto& a : origin ){
		 points.push_back(a.getStart());
		 points.push_back(a.getEnd());
	 }

	 std::vector<Triangle> allTriangles;

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
					 if( x.getStart() == p && y.getStart() == p ){
						 allTriangles.push_back(Triangle(x,y,MeshEdge(x.getEnd(), y.getEnd(), Color(0, 0, 0))));
					 } else if( x.getStart() == p && y.getEnd() == p ){
						 allTriangles.push_back(Triangle(x,y,MeshEdge(x.getEnd(), y.getStart(), Color(0, 0, 0))));
					 } else if( x.getEnd() == p && y.getStart() == p ){
						 allTriangles.push_back(Triangle(x,y,MeshEdge(x.getStart(), y.getEnd(), Color(0, 0, 0))));
					 } else if( x.getEnd() == p && y.getEnd() == p ){
						 allTriangles.push_back(Triangle(x,y,MeshEdge(x.getStart(), y.getStart(), Color(0, 0, 0))));
					 }
					 // else throw new Exception :P
				 }
			 }
		 }
	 }
	 return allTriangles;
 };

 inline std::vector<Triangle> connectedIntersectionPoints(std::vector<std::pair<const Edge*, Point>> isections){
	 std::vector<Triangle> out;
	 std::vector<Edge> connections;
		 //Point a1 = isections[0].second;
		 //int mem = 1;
		 //double min = 100000000000;
		 //for( int i = 1; i < isections.size(); i++ ){
			// double dist = norm(std::array<double, 3>{
			//	 a1.getX() - isections[i].second.getX(),
			//		 a1.getY() - isections[i].second.getY(),
			//		 a1.getZ() - isections[i].second.getZ()}
			// );
			// if( dist < min ){
			//	 min = dist;
			//	 mem = i;
			// }
		 //}
		 //Edge e(a1, isections[mem].second);
		 //connections.push_back(e);

		 for( int i = 0; i < isections.size(); i++ ){
			 for( int j = 0; j < isections.size(); j++ ){
				 if( i != j ){
					 Edge edge(isections[i].second, isections[j].second);
					 bool add = true;
					 for( auto& e : connections ){
						 if( areIntersecting(e, edge) ){
							 add = false;
							 continue;
						 }
					 }
					 if( add ) connections.push_back(edge);
				 }
			 }
		 }

		 #pragma omp parallel for collapse(3)
		 for( int i = 0; i < connections.size(); i++ ){
			 Edge a = connections[i];
			 for( int j = 0; j < connections.size(); j++ ){
				 if( connections[j].getStart() == a.getEnd() || connections[j].getEnd() == a.getEnd() ){
					 Edge b = connections[j];
					 for( int k = 0; k < connections.size(); k++ ){
						 if( connections[k].getStart() == b.getEnd() || connections[k].getEnd() == b.getEnd() ){
							 Edge c = connections[k];
							 #pragma omp critical
							 out.push_back(Triangle(a, b, c));
						 } else continue;
					 }
				 } else continue;
			 }
		 }

		 return out;
 }

 inline bool triangleInsideSection(Triangle insideTriangle, std::vector<Triangle>& outsideTriangles){
	 Point insidePoint = insideTriangle.getPointInside();
	 Ray ray(insidePoint);
	 
	 int counter = 0;
	 for( auto& e : outsideTriangles )
		 if( intersection(ray, e.getPlane()) != nullptr && e.containsPoint((*intersection(ray, e.getPlane()))))
			 counter++;

	 if( counter % 2 == 1 ) return true;
	 else return false;
 }

 inline ClosedPolygonalChains removeTriangles(std::vector<Triangle> in, std::vector<Triangle> out){

	 std::vector<Triangle> in_inside;
	 for( auto& e: in ){
		 if( !triangleInsideSection(e, out) ) in_inside.push_back(e);
	 }

	 std::vector<Edge> polyLine;

	 for( auto& e: in_inside ){
		 polyLine.push_back(e.getEdgeA());
		 polyLine.push_back(e.getEdgeB());
		 polyLine.push_back(e.getEdgeC());
	 }

	 ClosedPolygonalChains cpc(polyLine);
	 return cpc;
 }
