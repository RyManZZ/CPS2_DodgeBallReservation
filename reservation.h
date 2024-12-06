//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: reservation.h
// Description: Serves as Header File for the reservation class (reservation.cpp):
//////////////////////////////////////////////

//Header Files and NameSpaces:
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

namespace NS_Reservation { //creates a namespace for Reservation
	class Reservation {    //creates a parent class Reservation

	private:
		string firstName;
		int vehicleNum;  //used to identify which vehicle the reservation isX being made for. see chart on line 58
		int cost;
		int pin;
		
	public:
		//Constructors:
		Reservation(); //default
		
		//Sets:
		void SetPin(int);
		void SetCost(int);
		void SetVehicleNum(int);
		void SetFirstName(string);

		//Returns
		int GetCost();
		int GetVehicleNum();
		int GetPin();
		string GetName();
		

		void createReservation(vector<Reservation>&, vector<Person>&, vector<Truck>&, vector<Compact>&, vector<Sedan>&, bool&, string);
		void deleteReservation(vector<Reservation>&, vector<Person>&, vector<Truck>&, vector<Compact>&, vector<Sedan>&, bool&, int, string);
		void modifyReservation(vector<Reservation>&, vector<Person>&, vector<Truck>&, vector<Compact>&, vector<Sedan>&, bool&);
		void printAllReservations(vector<Reservation>, vector<Truck>, vector<Compact>, vector<Sedan>);
		void printOneReservation(string, string, vector<Reservation>, vector<Truck>, vector <Compact>, vector <Sedan>);
	};
}


//Vehicle #   -  Map
// 0 - Truck    Purple
// 1 - Truck    Green
// 2 - Truck    Black
// 3 - Comapct  Red
// 4 - Compact  Blue
// 5 - Compact  Yellow
// 6 - Sedan    Blue
// 7 - Sedan    Black
// 8 - Sedan    Green
