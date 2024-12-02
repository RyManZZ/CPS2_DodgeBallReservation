//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: compact.h
// Description: Serves as Header File for the compact class (compact.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"
#include "vehicle.h"


using namespace NS_Vehicle;

namespace NS_Compact { //creates a namespace for tree
	class Compact : public Vehicle { //creates the tree class as a child of plant

	private:
		vector<char> seat_C;

	public:
		Compact();             //constructor
		void displayCompact(); //prints the truck image
		vector <char> getSeatCompact(); //may not be used
		bool seatCheckCompact(vector<char>); //checks to see if the seat is valid
	};
}