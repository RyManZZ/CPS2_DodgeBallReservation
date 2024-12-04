//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: person.cpp
// Description: Contains people Class. Allows access to user's data. Includes Names, and amount of credits.
//////////////////////////////////////////////

//Header Files & NameSpace Definitions:
#include "dogeBall.h"
#include "person.h"

using namespace NS_Person;


//Constructors:
Person::Person() {
     firstName = "NULL";
     lastName = "NULL";
     credit = 0;
}
Person::Person(string firstName, string lastName, int credit) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->credit = credit;
}


//Setting:
void Person::setPersonData(string firstName, string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}
void Person::setCreditData(int credit) {
    this->credit = credit;
}


//Returns:
string Person::getFirstName() {
    return firstName;
}
string Person::getLastName() {
    return lastName;
}
int Person::getCredit() {
    return credit;
}


//Displays:
void Person::displayFirstName(void) {
    cout << firstName <<" ";
}
void Person::displayLastName(void) {
    cout << lastName << " ";
}
void Person::displayCredit(void) {
    cout << credit << " ";
}
