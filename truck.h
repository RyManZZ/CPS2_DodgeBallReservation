//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: truck.h
// Description: Serves as Header File for the truck class (truck.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"
#include "vehicle.h"


using namespace NS_Vehicle;

namespace NS_Truck { //creates a namespace for tree
	class Truck : public Vehicle { //creates the tree class as a child of plant

	private:
		vector<char> seat;

	public:
		Truck();             //constructor
		void displayTruck(); //prints the truck image
		vector <char> getSeat(); //may not be used
		bool seatCheck(vector<char>); //checks to see if the seat is valid
	};
}
