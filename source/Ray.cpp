/*****************************************************************//**
 * @file   Ray.cpp
 * @brief  Implementation of methods used in the Ray class.
 *
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   June 2022
 *********************************************************************/

#include <limits>
#include "../include/Ray.h"

void Ray::changeEnd(const int version){
	switch( version ){
		case 1:
			set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max() });
			break;
		case 2:
			set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::max(),std::numeric_limits<float>::min() });
			break;
		case 3:
			set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::min(),std::numeric_limits<float>::min() });
			break;
		case 4:
			set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::min() });
			break;
		case 5:
			set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::min(),std::numeric_limits<float>::max() });
			break;
		case 6:
			set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max() });
			break;
		case 7:
			set(getStart(), Point{ std::numeric_limits<float>::max(),std::numeric_limits<float>::max(),std::numeric_limits<float>::max() });
			break;
		case 8:
			set(getStart(), Point{ std::numeric_limits<float>::min(),std::numeric_limits<float>::min(),std::numeric_limits<float>::min() });
			break;
		default:
			std::srand(std::time(nullptr));
			float random = ((double)rand() / ((double)RAND_MAX))/2.0 + 0.5;
			set(getStart(), Point{ (rand()%2 ? 1 : -1)*random*std::numeric_limits<float>::min(),(rand()%2 ? 1 : -1)*random*std::numeric_limits<float>::min(),(rand()%2 ? 1 : -1)*random*std::numeric_limits<float>::min() });
			break;
	}
}