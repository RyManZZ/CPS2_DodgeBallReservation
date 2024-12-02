//test
#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

//default
Vehicle::Vehicle() {
	string driverFirstName = "NULL";
	string driverLastName = "NULL";
	string color = "NULL";
} 

//sets the drives name
void Vehicle::SetDriverName(string driverFirstName, string driverLastName, string color) {
	this->driverFirstName = driverFirstName;
	this->driverLastName = driverLastName;
	this->color = color;
} 

string Vehicle::GetDriverFirstName() {
	return driverFirstName;
}

string Vehicle::GetDriverLastName() {
	return driverLastName;
}

string Vehicle::GetColor() {
	return color;
}