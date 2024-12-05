//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: truck.h
// Description: Serves as Header File for the Truck class (truck.cpp):
//////////////////////////////////////////////

//Header Files:
#pragma once

#include "DogeBall.h"
#include "vehicle.h"

using namespace NS_Vehicle;

namespace NS_Truck { //creates a namespace for Truck
	class Truck : public Vehicle { //creates the Truck class as a child of Vehicle

	private:
		vector<char> seat_T;

	public:
		Truck();             //constructor.
		void setSeatTruck();
		char displySeatTruck();
		bool seatCheckTruck(); //checks to see if the seat is valid.
	};
}
