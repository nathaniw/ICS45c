#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

#include <string>
#include <vector>

#include "Location.h"
using namespace std;

class DistanceCalculator{

public:
	DistanceCalculator();
	void initializeInput();
	Location requestLocation();
	int requestDestinationCount();
	double parseCoordinateValue(string coordinateText);
	double calculateDistance(Location start, Location destination);
	double convertDegreesToRadians(double degreeValue);
	double convertRadiansToDegrees(double radianValue);

private:

	int destinationCount;
	Location startLocation;
	vector<Location> destinationsVector;


};

#endif
