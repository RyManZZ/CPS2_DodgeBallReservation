//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: vehicle_compact.cpp
// Description: Contains the Compact Vehicle Class. Stores and processes information on Compact Vehicle Seating arrangements:
//////////////////////////////////////////////

//Header Files & NameSpace Definitions:
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
bool Compact::seatCheckCompact(int seatSelection) {
	string userInput;
	
	
    //Front Seat
	//*****************************************************************************
	if (seat_C.at(seatSelection - 1) == '5') {
		cout << "The front seat is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;
		//conformation check to make the reservation
		if (userInput == "Y" || userInput == "y") {
			//update the truck to show the spot has been claimed
			//cout << "congrats, reservation made, returing to main.";

			seat_C.at(0) = 'X';
			return true;
		}
		else { //if user cancels reservation
			cout << "reservation cancled, returing to main";
			system("pause");
		}
	}

	//*****************************************************************************


	//Back Seat
	//*****************************************************************************
	else if (seat_C.at(seatSelection - 1) == '3' || seat_C.at(seatSelection) == '3') { //checks both seats at once to see if they are avaliable
		
		cout << "A back Seat is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;
		
		
		if (userInput == "Y" || userInput == "y") { //conformation check to make the reservation
			
			//cout << "congrats, reservation made, returing to main.";

			//assigns the seat that the user reserved going left to right
			if (seat_C.at(1) == '3') seat_C.at(1) = 'X';
			else if (seat_C.at(2) == '3') seat_C.at(2) = 'X';
			
			return true;
		}
		else { //if user cancels reservation / invlaid input
			cout << "reservation cancled, returing to main";
			system("pause");
		}
	}

	else { //if seat is already claimed
		cout << "This Seat is already claimed, returning to main.\n";
		system("pause");
		return false;
	}
	//*****************************************************************************
}
