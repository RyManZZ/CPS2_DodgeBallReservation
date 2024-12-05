//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: vehicle.h
// Description: Serves as Header File for the Vehicle class (vehicle.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"


//car order goes:
// Color   Vehicle  Name

// Purple  Truck    Pat Cooper
// Green   Truck    Jane Cox
// Black   Truck    Tim Taylor

// Red     Compact  Ben Butler
// Blue    Compact  Art Campbell
// Yellow  Compact  Ann Edwards
 
// Blue    Sedan    Grace Wan
// Black   Sedan    Lary Adams
// Green   Sedan    Jessie Quirk

namespace NS_Vehicle{ //creates a namespace for Vehicle

	class Vehicle {    //creates a parent class Vehicle

	protected:
		string driverFirstName;
		string driverLastName;
		string color;
		
	public:

		//constructors
		Vehicle(); //default
		void SetDriverName(string, string, string); //sets the driver's Name
		string GetDriverFirstName();
		string GetDriverLastName();
		string GetColor();
		void PrintColor();
	};
}
