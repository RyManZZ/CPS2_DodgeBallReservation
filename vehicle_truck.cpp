
#include "DogeBall.h"
#include "vehicle.h"
#include "truck.h"

using namespace NS_Truck;
using namespace NS_Vehicle;

Truck::Truck() {
	seat.push_back('-');
}

//prints the truck image
void displayTruck() {
	cout << "------";
	cout << "|X   " << seat.at(0) << "|";
}
vector <char> getSeat(); //may not be used
bool seatCheck(vector<char>); //checks to see if the seat is valid
