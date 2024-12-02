
#include "DogeBall.h"
#include "vehicle.h"
#include "truck.h"

using namespace NS_Truck;
using namespace NS_Vehicle;

Truck::Truck() {            //pos   val
	seat_T.push_back('-');  // 0     5
}

//prints the truck image
void Truck::displayTruck() {

	//    Truck
	//    _   _
	//  --|---|--
	//  | X   - |
	//  |       |
	//  ---------	
	//Print Driver Name

	//Extra (add if time allows)
	//Print Passanger 1
	//Print Passanger 2
	//Print Passanger 3

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