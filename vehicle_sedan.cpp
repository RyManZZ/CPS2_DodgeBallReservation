//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: vehicle_sedan.cpp
// Description: Contains the Sedan Vehicle Class. Stores and processes information on Sedan Vehicle Seating arrangements:
//////////////////////////////////////////////


//Header Files & NameSpace Definitions:
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

void Sedan::setSeatSedan(int seat) {
	if (seat == 0) {
		seat_S.at(0) = '5';
	}
	else if (seat == 1) {
		seat_S.at(1) = '2';
	}
	else if (seat == 2) {
		seat_S.at(2) = '1';
	}
	else if (seat == 3) {
		seat_S.at(3) = '2';
	}
}

//reutens back the vector of seat
char Sedan::displaySeatSedan(int i) {
	return seat_S.at(i);
}

//checks to see if the seat is valid
//returns true if the seat is open
//else false
bool Sedan::seatCheckSedan(int seatSelection) {
	string userInput;


	//Front Seat
	//*****************************************************************************
	if (seat_S.at(seatSelection - 1) == '5') {
		cout << "The front seat is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;
		//conformation check to make the reservation
		if (userInput == "Y" || userInput == "y") {
			//update the truck to show the spot has been claimed
//			cout << "congrats, reservation made, returing to main.";

			seat_S.at(0) = 'X';
			return true;
		}
		else { //if user cancels reservation
			cout << "reservation cancled, returing to main";
			system("pause");
		}
	}

	
	//*****************************************************************************

	//Back Seat Middle
	//*****************************************************************************
	else if (seat_S.at(seatSelection - 1) == '1') {
		cout << "The center back seat is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;
		//conformation check to make the reservation
		if (userInput == "Y" || userInput == "y") {
			//update the truck to show the spot has been claimed
		//	cout << "congrats, reservation made, returing to main.";

			seat_S.at(2) = 'X';
			return true;
		}
		else { //if user cancels reservation
			cout << "reservation cancled, returing to main";
			system("pause");
		}
	}

	
	//*****************************************************************************

	//Back Seat Outside
	//*****************************************************************************
	else if (seat_S.at(seatSelection - 2) == '2' || seat_S.at(seatSelection + 1) == '2') { //checks both seats at once to see if they are avaliable

		cout << "A back Seat on the outisde is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;


		if (userInput == "Y" || userInput == "y") { //conformation check to make the reservation

		//	cout << "congrats, reservation made, returing to main.";

			//assigns the seat that the user reserved going left to right
			if (seat_S.at(1) == '2') seat_S.at(1) = 'X';
			else if (seat_S.at(3) == '2') seat_S.at(3) = 'X';

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
