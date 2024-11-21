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
		Person();
		Person(string, string, int );			     //constructor
		void setPersonData(string, string); //get the First, Last names, & credits of each person
		void setCreditData(int);
		void displayFirstName(void);
		void displayLastName(void);
		void displayCredit(void);

			//check for driver? 
			//or give driver -1 credit to serve as a sentinal value?
	};
}

