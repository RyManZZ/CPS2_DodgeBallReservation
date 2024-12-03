


#pragma once


#include "DogeBall.h"
#include "vehicle.h"
#include "Sedan.h"

using namespace NS_Sedan;
using namespace NS_Vehicle;

Sedan::Sedan() {                            // pos  val
	seat_S.push_back('5'); //passanger seat    0    5
	seat_S.push_back('2'); //back seat left    1    2
	seat_S.push_back('1'); //back seat middle  2    1
	seat_S.push_back('2'); //back seat right   3    2
}

//still needs to be completed
//prints the Sedan image
void Sedan::displaySedan() {
	//    Sedan
	//    _   _
	//  --|---|--
	//  | X   - |
	//  |       |
	//  | - - - |
	//  ---------
	//Print Driver Name

	//Extra (add if time allows)
	//Print Passanger 1
	//Print Passanger 2
	//Print Passanger 3
}

//reutens back the vector of seat
char Sedan::displaySeatSedan(int i) {
	return seat_S.at(i);
}

//checks to see if the seat is valid
//returns true if the seat is open
//else false
bool Sedan::seatCheckSedan(vector<char>) {
	int userSeatVal = 0;
	while (true) {
		cout << "Enter a 1 for the shotgun\nEnter a 2 for back Left\nEnter a 3 for back right\nSeat: ";
		cin >> userSeatVal;
		if (userSeatVal > seat_S.size()) {
			cout << "please enter a value 1-3\n\n";
			system("pause");
			system("cls");
			continue;
		}

		if (seat_S.at(userSeatVal - 1) = '-') {
			return true;
		}
		else {
			return false;
		}
	}
}