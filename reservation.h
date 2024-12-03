//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: reservation.h
// Description: Serves as Header File for the reservation class (reservation.cpp):
//////////////////////////////////////////////
#pragma once

#include "DogeBall.h"
#include "person.h"
#include "sedan.h"
#include "compact.h"
#include "truck.h"


using namespace NS_Person;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;

namespace NS_Reservation { //creates a namespace for plant
	class Reservation {    //creates a parent class Plant

	private:
		string firstName;
		int vehicleNum;  //used to identify which vehicle the reservation is being made for
		int cost;
		int pin;
		
	public:
		//constructors
		Reservation(); //default
		
		//sets
		void SetPin(int);
		void SetCost(int);
		void SetVehicleNum(int);
		void SetFirstName(string);

		//returns
		int GetCost();
		int GetVehicleNum();

		void createReservation(vector<Reservation>&, vector<Person>, vector<Truck>, vector<Compact>, vector<Sedan>);
	//	void modifyReservation();
	//	void printReservation();
	//	void deleteReservation();
	};
}



//vehicleNum - map
// 1 - Truck    Purple
// 2 - Truck    Green
// 3 - Truck    Black
// 4 - Comapct  Red
// 5 - Compact  Blue
// 6 - Compact  Yellow
// 7 - Sedan    Blue
// 8 - Sedan    Black
// 9 - Sedan    Green