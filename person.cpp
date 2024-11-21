#include "dogeBall.h"
#include "person.h"

using namespace NS_Person;

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

void NS_Person::Person::setPersonData(string firstName, string lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

void Person::setCreditData(int credit) {
    this->credit = credit;
}


void Person::displayFirstName(void) {
    cout << firstName <<" ";
}

void Person::displayLastName(void) {
    cout << lastName << " ";
}

void Person::displayCredit(void) {
    cout << credit << " ";
}