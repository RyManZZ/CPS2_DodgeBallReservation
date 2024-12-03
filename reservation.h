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
		int cost;
		int pin;
		
	public:
		//constructors
		Reservation(); //default
		void SetPin(int);
		void SetCost(int);
		int GetCost();
		void createReservation(vector<Person>, vector<Truck>, vector<Compact>, vector<Sedan>);
	//	void modifyReservation();
	//	void printReservation();
	//	void deleteReservation();
	};
}