//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: person.h
// Description: Serves as Header File for the person class (person.cpp):
//////////////////////////////////////////////

//Header Files:
#pragma once
#include "DogeBall.h"

namespace NS_Person {
	class Person {    //creates a parent class Person

	private:
		string firstName;
		string lastName;
		int credit;

	public:
		//constructors:
		Person(); //Default
		Person(string, string, int ); //Paramertarized.
		
		//Seting:
		void setPersonData(string, string); //Sets the first and last names.
		void setCreditData(int); //sets the # of credits.

		//Returns:
		string getFirstName();
		string getLastName(); 
		int    getCredit();


		//Displays:
		void displayFirstName(void);
		void displayLastName(void);
		void displayCredit(void);

	};
}

