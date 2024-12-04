//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: sedan.h
// Description: Serves as Header File for the Sedan class (sedan.cpp):
//////////////////////////////////////////////

//Header Files:
#pragma once

#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

namespace NS_Sedan { //creates a namespace for Sedan
	class Sedan : public Vehicle { //creates the Sedan class as a child of Vehicle

	private:
		vector<char> seat_S;

	public:
		Sedan();             //constructor.
		void setSeatSedan(int);
		void displaySedan(); //prints the Sedan image.
		char displaySeatSedan(int); //may not be used.
		bool seatCheckSedan(int); //checks to see if the seat is valid.
	};
}
