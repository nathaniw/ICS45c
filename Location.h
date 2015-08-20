#ifndef LOCATIONCLASS
#define LOCATIONCLASS

#include <string>
using namespace std;


class Location
{
public: 
	Location();
	Location(double latitude, double longitude, string airportName);
	double getLatitudeValue();
	double getLongitudeValue();
	string getAirportName();

	string Add(string s1, string s2);
	int Add(int i1, int i2);


private:
	double latitudeValue;
	double longitudeValue;
	string AirportName;
};

#endif
