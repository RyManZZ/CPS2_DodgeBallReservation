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

	protected:
		string firstName;
		string lastName;
		int credit;

	public:
			 Person();			     //constructor
		void setPersonData(string, string, int); //get the First, Last names, & credits of each person
		
		//check for driver? 
		//or give driver -1 credit to serve as a sentinal value?
	};
}

