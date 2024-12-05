//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: compact.h
// Description: Serves as Header File for the Compact class (compact.cpp):
//////////////////////////////////////////////

//Header Files:
#pragma once

#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

namespace NS_Compact { //creates a namespace for Compact
	class Compact : public Vehicle { //creates the Compact class as a child of Vehicle

	private:
		vector<char> seat_C;

	public:
		Compact();             //constructor.
		void setSeatCompact(int); 
		char displaySeatCompact(int); //may not be used.
		bool seatCheckCompact(int); //checks to see if the seat is valid.
	};
}
