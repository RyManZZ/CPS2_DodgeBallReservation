//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: vehicle.cpp
// Description: Contains Vehicle Class. Allows access to Vehicle Driver, and Vehicle Description information:
//////////////////////////////////////////////

//Header Files & NameSpace Definitions:
#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

//Default:
Vehicle::Vehicle() {
	string driverFirstName = "NULL";
	string driverLastName = "NULL";
	string color = "NULL";
} 

//Sets the Driver's Name:
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
