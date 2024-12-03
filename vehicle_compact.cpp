//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: Compact.h
// Description: Serves as Header File for the Compact class (vehicle_compact.cpp):
//////////////////////////////////////////////
#pragma once


#include "DogeBall.h"
#include "vehicle.h"
#include "Compact.h"

using namespace NS_Compact;
using namespace NS_Vehicle;

Compact::Compact() {							//pos val
	seat_C.push_back('5'); //passanger seat        0   5
	seat_C.push_back('3'); //back seat left        1   3
	seat_C.push_back('3'); //back seat right       2   3
}

//still needs to be completed
//prints the Compact image
void Compact::displayCompact() {
	//  Compact
	//    _  _
	//  --|--|--
	//  | X  - |
	//  |      |
	//  | -  - |
	//  --------
	//Print Driver Name

	//Extra (add if time allows)
	//Print Passanger 1
	//Print Passanger 2
	//Print Passanger 3
}

//reutens back the vector of seat
char Compact::displaySeatCompact(int i) {
	return seat_C.at(i);
}

//checks to see if the seat is valid
//returns true if the seat is open
//else false
bool Compact::seatCheckCompact(vector<char>) {
	int userSeatVal = 0;
	while (true) {
		cout << "Enter a 1 for the shotgun\nEnter a 2 for back Left\nEnter a 3 for back right\nSeat: ";
		cin >> userSeatVal;
		if (userSeatVal > seat_C.size()) {
			cout << "please enter a value 1-3\n\n";
			system("pause");
			system("cls");
			continue;
		}

		if (seat_C.at(userSeatVal - 1) = '-') {
			return true;
		}
		else {
			return false;
		}
	}
}