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

using namespace NS_Person;

namespace NS_Reservation { //creates a namespace for plant
	class Reservation {    //creates a parent class Plant

	private:
		string firstName;
		int pin;
		
	public:
		//constructors
		Reservation(); //default
		void SetPin(int);
		void createReservation(vector<Person>);
	//	void modifyReservation();
	//	void printReservation();
	//	void deleteReservation();
	};
}