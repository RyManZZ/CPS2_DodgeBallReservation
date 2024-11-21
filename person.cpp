#include "dogeBall.h"
#include "person.h"

using namespace NS_Person;

NS_Person::Person::Person() {
    string firstName = "NULL";
    string lastName = "NULL";
    int credit = 0;
}

void NS_Person::Person::setPersonData(string firstName, string lastName, int credit) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->credit = credit;
}

