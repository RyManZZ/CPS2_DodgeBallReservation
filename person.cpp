#include "dogeBall.h"
#include "person.h"

using namespace NS_Person;


//constructors
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


//setting
void Person::setPersonData(string firstName, string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}
void Person::setCreditData(int credit) {
    this->credit = credit;
}


//returns
string Person::getFirstName() {
    return firstName;
}
string Person::getLastName() {
    return lastName;
}
int Person::getCredit() {
    return credit;
}


//displayes
void Person::displayFirstName(void) {
    cout << firstName <<" ";
}
void Person::displayLastName(void) {
    cout << lastName << " ";
}
void Person::displayCredit(void) {
    cout << credit << " ";
}