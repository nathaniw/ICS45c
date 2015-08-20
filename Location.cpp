#include "stdafx.h"
#include "Location.h"
#include <string>

using namespace std;

Location::Location(){
}

Location::Location(double latitude, double longitude, string airportName){
	latitudeValue = latitude;
	longitudeValue = longitude;
	AirportName = airportName;
}

double Location::getLatitudeValue(){
	return latitudeValue;
}

double Location::getLongitudeValue(){
	return longitudeValue;
}

string Location::getAirportName(){
	return AirportName;
}

string Location::Add(string s1, string s2){
	return s1 + s2;
}

int Location::Add(int i1, int i2){
	return i1 + i2;
}
