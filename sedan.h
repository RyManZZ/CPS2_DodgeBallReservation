//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: sedan.h
// Description: Serves as Header File for the sedan class (sedan.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"
#include "vehicle.h"


using namespace NS_Vehicle;

namespace NS_Sedan { //creates a namespace for tree
	class Sedan : public Vehicle { //creates the tree class as a child of plant

	private:
		vector<char> seat_S;

	public:
		Sedan();             //constructor
		void displaySedan(); //prints the truck image
		char displaySeatSedan(int); //may not be used
		bool seatCheckSedan(vector<char>); //checks to see if the seat is valid
	};
}