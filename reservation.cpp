

//Header Files
#include "dogeBall.h"
#include "reservation.h"
#include "sedan.h"
#include "compact.h"
#include "truck.h"
#include "person.h"


//Namespace's
using namespace NS_Reservation;
using namespace NS_Person;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;

//constructors
Reservation::Reservation() {
    firstName = "NULL";
	cost = 0;
    pin = 0;
}


void Reservation::SetPin(int pin) {
    this->pin = pin;
}

//used to hold the value of the seat when making a reservation
void Reservation::SetCost(int cost) {
	this->cost = cost;
}

//returns the value of the seat that was reserved
int Reservation::GetCost() {
	return cost;
}

//This allows a person to make a reservation as long as they have above 0 credits and are not a driver
//Takes in the person class vecotor (First/Last names and credits) - drivers get -1 credits
void Reservation::createReservation(vector<Person> personData, vector<Truck> trucks, vector<Compact> compacts, vector<Sedan> sedans){
	string firstNameUser, carType, carColor, tempString;

	cout << "\n\nCreate Reservation\n";
	cout << "------------------\n";
	cout << "First Name: ";
	cin >> firstNameUser;

	//Forces first letter of the person name to upper case and the rest to lower
	tempString.push_back(toupper(firstNameUser.at(1)));
	for (int i = 1; i < carType.size(); i++) {
		tempString.push_back(tolower(carColor.at(i)));
	}
	firstNameUser = tempString;


	

	//display for the currently made reservations
	cout << "\n\n Truck        Compact        Sedan\n";
	cout << "-------      ---------      -------\n";
	cout << "Purple          Red           Blue \n";
	cout << "(-) " << "(" << trucks.at(0).Truck::displySeatTruck() << ")   " << "(-) " << "(" << compacts.at(0).Compact::displaySeatCompact(0) << ")   (-)   (" << sedans.at(0).Sedan::displaySeatSedan(0) << ")\n";


	for (int i = 0; i < personData.size(); i++) {
		if (firstNameUser == personData.at(i).Person::getFirstName()) {
			//Driver Check
			if (personData.at(i).Person::getCredit() == -1) {
				cout << "You are a driver and cannot reserve a seat\n";
				system("pause");
				return;
			}
			//0 creddit check
			else if (personData.at(i).Person::getCredit() == 0) {
				cout << "\nYou have 0 credits, you must dirve your self\n";
				system("pause");
				return;
			}
			//Make a reservation portion
			else {
				system("cls");
				//displays the persons name and the number of credits they have
				cout << "Hellow ";    personData.at(i).Person::displayFirstName();
				cout << "you have ";  personData.at(i).Person::displayCredit();
				cout << "credits";

				//Prompts the user for their vehicle choice
				cout << "\n\nPlease select one of the vehicle types below\n\n";
				cout << "Truck, Compact, Sedan\n";
				cout << "------------\n";
				cout << "Vehicle Type: ";  cin >> carType;
				cout << "Vehicle Color: "; cin >> carColor;

				//used to convert user input to lower case for car type
				for (int i = 0; i < carType.size(); i++) {
					tempString.push_back(tolower(carType.at(i)));
				}
				carType = tempString;

				
				//used to convert user input to lower case for car color
				for (int i = 0; i < carType.size(); i++) {
					tempString.push_back(tolower(carColor.at(i)));
				}
				carColor = tempString;


				if (carType == "truck") {
					if (personData.at(i).Person::getCredit() >= 5) {
						

					}
					else {
						cout << "You do not have enough credits to reserve a seat in a Truck\nGoing Back to main menu\n";
						system("pause");
						return;
					}
				}
				else if (carType == "compact") {
					if (personData.at(i).Person::getCredit() >= 3) {




					}
					else {
						cout << "You do not have enough credits to reserve a seat in a Truck\nGoing Back to main menu\n";
						system("pause");
						return;
					}
				}
				else if (carType == "sedan") {
					
				}
				else {

				}

			}
		}
	}

	//error surrently always displays
		//make error check for if name was not found and send the user back to the menu
		cout << "Sorry, " << firstNameUser << " was not found\n\n";
		system("pause");
		return;
	
}