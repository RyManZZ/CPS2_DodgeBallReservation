
#include "DogeBall.h"
#include "vehicle.h"
#include "truck.h"

using namespace NS_Truck;
using namespace NS_Vehicle;

Truck::Truck() {
	seat_T.push_back('-');
}

//prints the truck image
void Truck::displayTruck() {
	cout << "------";
	cout << "|X   " << seat_T.at(0) << "|";
}

//reutens back the vector of seat
vector <char> Truck::getSeat() {
	return seat_T;
} 

//checks to see if the seat is valid
//returns true if the seat is open
//else false
bool Truck::seatCheck(vector<char>) {
	if (seat_T.at(0) = '-') {
		return true;
	}

	else {
		return false;
	}
} 