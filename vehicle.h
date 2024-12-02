//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: vehicle.h
// Description: Serves as Header File for the vehicle class (vehicle.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"


//car order goes

// Color  Vehcile Name

// Purple  Pick-Up  Pat Cooper
// Green   Pick-Up  Jane Cox
// Black   Pick-Up  Tim Taylor

// Red     Compact  Ben Butler
// Blue    Compact  Art Campbell
// Yellow  Compact  Ann Edwards
 
// Blue    Sedan    Grace Wan
// Black   Sedan    Lary Adams
// Green   Sedan    Jessie Quirk

namespace NS_Vehicle{ //creates a namespace for plant
	class Vehicle {    //creates a parent class Plant

	protected:
		string driverFirstName;
		string driverLastName;
		string color;
		
	public:
		//constructors
		Vehicle(); //default
		void SetDriverName(string, string, string); //sets the drive name
		string GetDriverFirstName();
		string GetDriverLastName();
		string GetColor();
	};
}