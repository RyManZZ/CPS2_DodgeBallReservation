//test
#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

//default
Vehicle::Vehicle() {
	string driverFirstName = "NULL";
	string driverLastName = "NULL";
} 

//sets the drives name
void Vehicle::SetDriverName(string driverFirstName, string driverLastName) {
	this->driverFirstName = driverFirstName;
	this->driverLastName = driverLastName;

} 

string Vehicle::GetDriverFirstName() {
	return driverFirstName;
}

string Vehicle::GetDriverLastName() {
	return driverLastName;
}