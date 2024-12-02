#include "dogeBall.h"
#include "reservation.h"
#include "sedan.h"
#include "compact.h"
#include "truck.h"
#include "person.h"

using namespace NS_Reservation;
using namespace NS_Person;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;

//constructors
Reservation::Reservation() {
    firstName = "NULL";
    pin = 0;
}


void Reservation::SetPin(int pin) {
    this->pin = pin;
}

void Reservation::createReservation(vector<Person> personData) {
	string firstNameUser, carType;
	vector<Truck> trucks;

	cout << "\n\nCreate Reservation\n";
	cout << "------------------\n";
	cout << "First Name: ";
	cin >> firstNameUser;



	for (int i = 0; i < personData.size(); i++) {
		if (firstNameUser == personData.at(i).Person::getFirstName()) {
			if (personData.at(i).Person::getCredit() == 0) {
				cout << "You have 0 credits, you must dirve your self\n";
				system("pause");
			}
			else {

				cout << "\n\nVehicle Type\n";
				cout << "Truck, Compact, Sedan\n";
				cout << "------------\n";
				cout << "Vehicle: ";
				cin >> carType;

				if (carType == "Truck") {
					if (personData.at(i).Person::getCredit() >= 5) {

					}
				}
				else if (carType == "Sedan") {
					
				}
				else if (carType == "Compact") {

				}
				else {

				}

			}
		}
	}
		//make error check for if name was not found and send the user back to the menu
		cout << "Sorry, " << firstNameUser << " was not found\n\n";
		system("pause");
		return;
	
}