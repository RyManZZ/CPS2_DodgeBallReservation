

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


//prototypes
void low(string&);


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
void Reservation::createReservation(vector<Person> personData, vector<Truck> trucks, vector<Compact> compacts, vector<Sedan> sedans) {
	string userInput, carType, carColor, tempString;
	int userInt;

	cout << "\n\nCreate Reservation\n";
	cout << "------------------\n";
	cout << "First Name: ";
	cin >> userInput;

	//Forces first letter of the person name to upper case and the rest to lower
	tempString.push_back(toupper(userInput.at(0)));
	for (int i = 1; i < userInput.size(); i++) {
		tempString.push_back(tolower(userInput.at(i)));
	}
	userInput = tempString;

	for (int i = 0; i < personData.size(); i++) {
		if (userInput == personData.at(i).Person::getFirstName()) {
			
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
				cout << "Hello ";    personData.at(i).Person::displayFirstName();
				cout << "you have ";  personData.at(i).Person::displayCredit();
				cout << "credits\n\n";

				//display for all of the current reservations for all 
				cout << "\n\n Truck      Compact      Sedan\n";
				cout << "-------    ---------    --------\n";
				
				//first row of cars
				cout << "Purple        Red         Blue \n";
				cout << "(-)" << "(" << trucks.at(0).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(0).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(0).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(0).Compact::displaySeatCompact(1) << ") (" << compacts.at(0).Compact::displaySeatCompact(2) << ")     (" << sedans.at(0).Sedan::displaySeatSedan(1) << ")(" << sedans.at(0).Sedan::displaySeatSedan(2) << ")(" << sedans.at(0).Sedan::displaySeatSedan(3) << ")\n\n";
				
				//second row of cars
				cout << "Green        Blue         Black\n";
				cout << "(-)" << "(" << trucks.at(1).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(1).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(1).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(1).Compact::displaySeatCompact(1) << ") (" << compacts.at(1).Compact::displaySeatCompact(2) << ")     (" << sedans.at(1).Sedan::displaySeatSedan(1) << ")(" << sedans.at(1).Sedan::displaySeatSedan(2) << ")(" << sedans.at(1).Sedan::displaySeatSedan(3) << ")\n\n";
				
				//third row of cars
				cout << "Black       Yellow        Green\n";
				cout << "(-)" << "(" << trucks.at(2).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(2).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(2).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(2).Compact::displaySeatCompact(1) << ") (" << compacts.at(2).Compact::displaySeatCompact(2) << ")     (" << sedans.at(2).Sedan::displaySeatSedan(1) << ")(" << sedans.at(2).Sedan::displaySeatSedan(2) << ")(" << sedans.at(2).Sedan::displaySeatSedan(3) << ")\n\n\n";


				//option between auto assign and vehicle choice
				cout << "Option: Enter a 1 or a 2\n(1) Any avaiable seat\n(2) A specific Vehicle\n\n";
				cout << "choice: "; cin >> userInt;


				//Any avaiable seat
				if (userInt == 1) {
					cout << "\n\nEnter 1-4 for the seat type you want\n";

					//cost menu to display seat costs with its option
					cout << "     Position                Cost \n";
					cout << "(1) Front Seat                5\n";
					cout << "(2) Compact Back Seat         3\n";
					cout << "(3) Sedan Back Seat Outside   2\n";
					cout << "(4) Sedan Back Seat Middle    1\n";
					cout << "Seat: "; cin >> userInt;

					//Shotgun
					if (userInt == 1) {
						//loop through the all front seats  if an option is avaiable ask the user to confirm then make pin and return to main

					}

					//Compact Back Seat
					else if (userInt == 2) {
						//loop through the three comapacts back seats if an option is avaiable ask the user to confirm then make pin and return to main

					}

					//Sedan Back Seat Outside
					else if (userInt == 3) {
						//loop through the three sedans back seat outside if an option is avaiable ask the user to confirm then make pin and return to main

					}

					//Sedan Back Seat Middle
					else if (userInt == 4) {
						//loop through the three sedans middle seat if an option is avaiable ask the user to confirm then make pin and return to main

					}

					//error check
					else {
						cout << "You did not enter a number 1-4 going back to main menu\n";
						system("pause");
						return;
					}
				}

				//user specific vehicle and seat
				else if (userInt == 2) {
					//allows the user to choose a vehicle type and color
					cout << "What Vechicle do you want to ride in and seat location\n";
					cout << "Car Type: ";  cin >> carType;
					cout << "car Color: "; cin >> carColor;

					low(carType);
					low(carColor);


					//cost menu to display seat costs with its option
					cout << "\n\nEnter 1-4 for the seat type you want\n";
					cout << "     Position                Cost \n";
					cout << "(1) Front Seat                5\n";
					cout << "(2) Compact Back Seat         3\n";
					cout << "(3) Sedan Back Seat Outside   2\n";
					cout << "(4) Sedan Back Seat Middle    1\n";
					cout << "Seat: "; cin >> userInt;

					//add credit check here to make sure they can get a seat of that cost value


					//truck and its three options for user specified vehicle
					if (carType == "truck") {
						//Purple Truck
						if (carColor == "purple") {
							//if avaiable ask the user to confirm then make pin and return to main 

						}

						//Green Truck
						else if (carColor == "green") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Black Truck
						else if (carColor == "black") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Error check
						else {
							cout << "The truck you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}

					//Compact and its three options for user specified vehicle
					else if (carType == "compact") {
						
						//Red Compact 
						if (carColor == "red") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Blue Compact
						else if (carColor == "blue") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Yellow Compact
						else if (carColor == "yellow") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Error Check
						else {
							cout << "The compact you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}

					else if (carType == "sedan") {
						
						//Blue Sedan
						if (carColor == "blue") {
							//if avaiable ask the user to confirm then make pin and return to main

						}
						
						//Black Sedan
						else if (carColor == "black") {
							//if avaiable ask the user to confirm then make pin and return to main
						
						}

						//Green Sedan
						else if (carColor == "green") {
							//if avaiable ask the user to confirm then make pin and return to main

						}

						//Error Check
						else {
							cout << "The sedan you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}

					//error check for vehicle type
					else {
						cout << "You did not enter a valid vehicle type, returning to main.\n";
						system("pause");
						return;
					}
				}

				//error check option between vehicle choice or auto
				else {
					cout << "you did not enter a 1 or a 2, returning to main.\n";
					system("pause");
					return;
				}


				//used to convert user input to lower case for car type
				//for (int i = 0; i < carType.size(); i++) {
				//	tempString.push_back(tolower(carType.at(i)));
				//} 
				//carType = tempString;


				//used to convert user input to lower case for car color
				//for (int i = 0; i < carType.size(); i++) {
				//	tempString.push_back(tolower(carColor.at(i)));
				//}
				//carColor = tempString;


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
	cout << "Sorry, " << userInput << " was not found\n\n";
	system("pause");
	return;

}


//used to convert user input to lower case for car type
void low(string& inWord) {
	string tempString;
	for (int i = 0; i < inWord.size(); i++) {
		tempString.push_back(tolower(inWord.at(i)));
	} 
	inWord = tempString;
}
	