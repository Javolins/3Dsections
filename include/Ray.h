/*****************************************************************//**
 * @file   Ray.h
 * @brief  
 * 
 * @author Michał Rutkowski @P4ndaM1x
 * @date   June 2022
 *********************************************************************/

#pragma once
#include <limits>
#include "Edge.h"

class Ray : public Edge{
	public:
		// zmieniając max() na min() można uzyskać znacznie stabilniejsze rezultaty na prawym panelu, ale 
		Ray(const Point& point) : Edge{ point, Point{std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max()} } {}
		// wszelkie możliwości umiejscwowienia końca promienia + nieskończenie wiele więcej opcji
		void changeEnd(const int version){
			if( version == 1 )
				set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max() });
			else if( version == 2 )
				set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::max(),std::numeric_limits<float>::min() });
			else if( version == 3 )
				set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::min(),std::numeric_limits<float>::min() });
			else if( version == 4 )
				set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::min() });
			else if( version == 5 )
				set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max() });
			else if( version == 6 )
				set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max() });
			else if( version == 7 )
				set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max() });
			else if( version == 8 )
				set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::min(),std::numeric_limits<float>::min() });
			else{
				std::srand(std::time(nullptr));
				float random = ((double)rand() / ((double)RAND_MAX))/2.0 + 0.5;
				set(getStart(), Point{ (rand()%2 ? 1:-1)*random*std::numeric_limits<float>::min(),(rand()%2 ? 1:-1)*random*std::numeric_limits<float>::min(),(rand()%2 ? 1:-1)*random*std::numeric_limits<float>::min() });
			}
		}
		// zwraca początek promienia
		Point getPoint() const{ return getStart(); }
};