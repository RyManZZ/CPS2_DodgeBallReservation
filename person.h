//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: person.h
// Description: Serves as Header File for the person class (person.cpp):
//////////////////////////////////////////////
#pragma once
//#include "DogeBall.h"

#include <iostream>
#include <iomanip>
#include <string>



namespace NS_Person { //creates a namespace for plant
	class Person {    //creates a parent class Plant

	private:
		string firstName;
		string lastName;
		int credit;

	public:
		//constructors
		Person(); //default
		Person(string, string, int ); //paramertarized
		
		//seting
		void setPersonData(string, string); //sets the first and last names
		void setCreditData(int); //sets the # of credits

		//returns
		string getFirstName();
		string getLastName();
		int    getCredit();


		//displays
		void displayFirstName(void);
		void displayLastName(void);
		void displayCredit(void);

			//check for driver? 
			//or give driver -1 credit to serve as a sentinal value?
	};
}

