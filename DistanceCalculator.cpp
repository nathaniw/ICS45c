#include "stdafx.h"
#include "DistanceCalculator.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

DistanceCalculator::DistanceCalculator(){
	initializeInput();
}

void DistanceCalculator::initializeInput(){
	cout << "Please Enter a Start Location: \n";
	startLocation = requestLocation();
	cout << "Please Enter a Number of Destinations: \n";
	destinationCount = requestDestinationCount();
	cout << "Destination Count: " << destinationCount << " \n";
	for (int i = 0; i < destinationCount; i++){
		//cout << "i: " << i << '\n';
		cin.ignore();
		Location destinationLocation = requestLocation();
		cout << calculateDistance(startLocation, destinationLocation);
		/*destinationsVector.push_back(destinationLocation);*/
	}

}

Location DistanceCalculator::requestLocation(){
	string locationText, latitudeText, longitudeText, airportText;
	double latitudeValue, longitudeValue;
	Location location;

	string str;

	//Take input and separate into components
	getline(cin, locationText);
	cout << "locationText: " << locationText << '\n';
	istringstream iss(locationText);
	iss >> latitudeText >> longitudeText;
	getline(iss, airportText);
	
	//Parse strings into lat and lon values
	latitudeValue = parseCoordinateValue(latitudeText);
	longitudeValue = parseCoordinateValue(longitudeText);

	//Create Location object
	location = Location(latitudeValue,longitudeValue,airportText);
	return location;
}

int DistanceCalculator::requestDestinationCount(){
	int dCount;
	cin >> dCount;
	cin.clear();
	return dCount;
}

double DistanceCalculator::parseCoordinateValue(string coordinateText){
	//cout << "coordinateText: " << coordinateText << '\n';
	vector<string> tokens;
	stringstream ss(coordinateText);
	string token;
	char delimiter = '/';

	//Iterate through ss(coordinateText) and split based on delimiter '/'
	while(getline(ss,token,delimiter)){
		tokens.push_back(token);
	}

	//Convert string to double
	double coordinateValue = stod(tokens[0]);

	//If Latitude/Longitude == S or W, adjust coordinateValue to be negative
	if(tokens[1] == "S" || tokens[1] == "W"){
		coordinateValue = coordinateValue*-1;
	}

	//cout << "coordinateValue: " << coordinateValue << '\n';
	return coordinateValue;
}

double DistanceCalculator::calculateDistance(Location start, Location destination){
	double startLatDegrees = start.getLatitudeValue();
	double startLatRadians = convertDegreesToRadians(startLatDegrees);
	double startLonDegrees = start.getLongitudeValue();
	double startLonRadians = convertDegreesToRadians(startLonDegrees);

	double destinationLatDegrees = destination.getLatitudeValue();
	double destinationLatRadians = convertDegreesToRadians(destinationLatDegrees);
	double destinationLonDegrees = destination.getLongitudeValue();
	double destinationLonRadians = convertDegreesToRadians(destinationLonDegrees);

	double dlatDegrees = destinationLatDegrees - startLatDegrees; // -23 - 33 = -56
	double dlatRadians = convertDegreesToRadians(dlatDegrees);
	double dlonDegrees = destinationLonDegrees - startLonDegrees; // -46 - (-118)  = 72
	double dlonRadians = convertDegreesToRadians(dlonDegrees);

	double R = 3959.9;

	//a should equal 0.899
	double a1 = sin(dlatRadians/2)*sin(dlatRadians/2);
	//cout << "a1: " << a1 << '\n';
	double a2a = cos(startLatRadians);
	//cout << "a2a: " << a2a << '\n';
	double a2b = cos(destinationLatRadians);
	//cout << "a2b: " << a2b << '\n';
	double a2c = sin(dlonRadians/2) * sin(dlonRadians/2);
	//cout << "a2c: " << a2c << '\n';
	double a2 = a2a * a2b * a2c;
	//cout << "a2: " << a2 << '\n';
	double a = a1 + a2;

	//c should equal 1.557 for LAX and SFO
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	
	//cout << "c: " << c << '\n';
	 

	double d = R * c;
	cout << "Distance from " << start.getAirportName() << " to " << destination.getAirportName() << ": " << d << '\n';
	return d;
}

double DistanceCalculator::convertDegreesToRadians(double degreeValue){
	return degreeValue*3.1415926/180;
}

double DistanceCalculator::convertRadiansToDegrees(double radianValue){
	return radianValue * 180/3.1415926;
}
