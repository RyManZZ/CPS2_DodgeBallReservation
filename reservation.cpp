//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: reservation.cpp
// Description: Allows users to Create, Modify, Delete, or Display thier vehicle reservations:
//////////////////////////////////////////////

//Header Files:
#include "dogeBall.h"
#include "reservation.h"
#include "sedan.h"
#include "compact.h"
#include "truck.h"
#include "person.h"

//Namespace's:
using namespace NS_Reservation;
using namespace NS_Person;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;

//*****************************************************************************************************
// Defines a lot of stuff. Uses Pointers. -------------------------------------------------------------------------- Fix Comment
//*****************************************************************************************************

//Prototypes:
void low(string&); // <- converts the inputed string to lowercase.
void pinMaker(vector<int>& pinNum); // Assigns a Unique pin to the Reservation.
void nameLow(string&);

//Constructors:
Reservation::Reservation() {
    firstName = "NULL";
	vehicleNum = 0;
	cost = 0;
    pin = 0;
}

void Reservation::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Reservation::SetVehicleNum(int vehicleNum) {
	this->vehicleNum = vehicleNum;
}

void Reservation::SetPin(int pin) {
    this->pin = pin;

}

//used to hold the value of the seat when making a reservation:
void Reservation::SetCost(int cost) {
	this->cost = cost;
}

//returns the value of the seat that was reserved:
int Reservation::GetCost() {
	return cost;
}

int Reservation::GetVehicleNum() {
	return vehicleNum;
}

int Reservation::GetPin() {
	return pin;
}

string Reservation::GetName() {
	return firstName;
}

//*****************************************************************************************************
// Create Reservation:
//*****************************************************************************************************

//This allows a person to make a reservation as long as they have above 0 credits and are not a driver
//Takes in the person class vector (First/Last names and credits) - drivers get -1 credits:
void Reservation::createReservation(vector<Reservation>& completedReservation, vector<Person>& personData, vector<Truck>& trucks, vector<Compact>& compacts, vector<Sedan>& sedans) {
	Reservation tempCompleted;

	string userInput, carType, carColor, tempString;
	int userInt;
	vector<int>pinNum;
	int pinCount = pinNum.size(); //used to keep track of the umber of pins made
	int personLocation;
	bool resCheck; //used to check to see if a reservation was made.


	cout << "\n\nCreate Reservation\n";
	cout << "------------------\n";
	cout << "First Name: ";
	cin >> userInput;

	nameLow(userInput);

	for (personLocation = 0; personLocation < personData.size(); personLocation++) {
		if (userInput == personData.at(personLocation).Person::getFirstName()) {
			
			//Driver Check:
			if (personData.at(personLocation).Person::getCredit() == -1) {
				cout << "You are a driver and cannot reserve a seat\n";
				system("pause");
				return;
			}

			//0 Credit Check:
			else if (personData.at(personLocation).Person::getCredit() == 0) {
				cout << "\nYou have 0 credits, you must dirve your self\n";
				system("pause");
				return;
			}

			//Make a Reservation Portion:
			else {
				system("cls");
				//Displays the persons name and the number of credits they have:
				cout << "Hello ";    personData.at(personLocation).Person::displayFirstName();
				cout << "you have ";  personData.at(personLocation).Person::displayCredit();
				cout << "credits\n\n";

				//Display for all of the current reservations for all:
				cout << "\n\n Truck      Compact      Sedan\n";
				cout << "-------    ---------    --------\n";
				
				//First row of cars:
				cout << "Purple        Red         Blue \n";
				cout << "(-)" << "(" << trucks.at(0).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(0).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(0).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(0).Compact::displaySeatCompact(1) << ") (" << compacts.at(0).Compact::displaySeatCompact(2) << ")     (" << sedans.at(0).Sedan::displaySeatSedan(1) << ")(" << sedans.at(0).Sedan::displaySeatSedan(2) << ")(" << sedans.at(0).Sedan::displaySeatSedan(3) << ")\n\n";
				
				//second row of cars:
				cout << "Green        Blue         Black\n";
				cout << "(-)" << "(" << trucks.at(1).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(1).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(1).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(1).Compact::displaySeatCompact(1) << ") (" << compacts.at(1).Compact::displaySeatCompact(2) << ")     (" << sedans.at(1).Sedan::displaySeatSedan(1) << ")(" << sedans.at(1).Sedan::displaySeatSedan(2) << ")(" << sedans.at(1).Sedan::displaySeatSedan(3) << ")\n\n";
				
				//third row of cars:
				cout << "Black       Yellow        Green\n";
				cout << "(-)" << "(" << trucks.at(2).Truck::displySeatTruck() << ")      " << "(-) " << "(" << compacts.at(2).Compact::displaySeatCompact(0) << ")     (-)   (" << sedans.at(2).Sedan::displaySeatSedan(0) << ")\n";
				cout << "            (" << compacts.at(2).Compact::displaySeatCompact(1) << ") (" << compacts.at(2).Compact::displaySeatCompact(2) << ")     (" << sedans.at(2).Sedan::displaySeatSedan(1) << ")(" << sedans.at(2).Sedan::displaySeatSedan(2) << ")(" << sedans.at(2).Sedan::displaySeatSedan(3) << ")\n\n\n";


				//option between auto assign and vehicle choice
				cout << "Option: Enter a 1 or a 2\n(1) Any avaiable seat\n(2) A specific Vehicle\n\n";
				cout << "choice: "; cin >> userInt;

//***************************************************
// Any available Seat Option:
//***************************************************
				if (userInt == 1) {
					cout << "\n\nEnter 1-4 for the seat type you want\n";

					//cost menu to display seat costs with its option
					cout << "     Position                Cost \n";
					cout << "(1) Front Seat                5\n";
					cout << "(2) Compact Back Seat         3\n";
					cout << "(3) Sedan Back Seat Outside   2\n";
					cout << "(4) Sedan Back Seat Middle    1\n";
					cout << "Seat: "; cin >> userInt;

					//Auto Shotgun
					if (userInt == 1) {
						if (personData.at(personLocation).getCredit() >= 5) {
							//loop through the all front seats  if an option is avaiable ask the user to confirm then make pin and return to main
							for (int i = 0; i < trucks.size(); i++) {
								if (trucks.at(i).seatCheckTruck() == true) {
									tempCompleted.SetCost(5);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(i);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

									system("pause");
									return;
								}
								//compact front seat is a 1 because inside the compact.cpp file it subrtacts one from it
								else if (compacts.at(i).seatCheckCompact(1) == true) {
									tempCompleted.SetCost(5);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(i+3);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

									system("pause"); 
									return;

								}
								//sedan front seat is a 1 because inside the compact.cpp file it subrtacts one from it
								else if (sedans.at(i).seatCheckSedan(1) == true) {
									tempCompleted.SetCost(5);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(i+6);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

									system("pause"); 
									return;
								}
							}
						}
					}

					//Auto Compact Back Seat:
					else if (userInt == 2) {
						//loop through the three comapacts back seats if an option is avaiable ask the user to confirm then make pin and return to main
						for (int i = 0; i < compacts.size(); i++)
						{
							if (compacts.at(i).seatCheckCompact(userInt) == true)
							{
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(5);

								pinMaker(pinNum);
								tempCompleted.SetPin(pinNum.at(pinCount));
								cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(4);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);

								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

								system("pause"); 
								return;
							}
						}
						
					}

					//Auto Sedan Back Seat Outside:
					else if (userInt == 3) {
						for (int i = 0; i < compacts.size(); i++)
						{
							if (sedans.at(i).seatCheckSedan(userInt-1) == true)
							{
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(2);

								pinMaker(pinNum);
								tempCompleted.SetPin(pinNum.at(pinCount));
								cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(i + 6);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);

								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 2);

								system("pause"); 
								return;
							}
						}
						cout << "No seat was avaliable, reuning to main.\n";
						system("pause");
						return;
					}

					//Auto Sedan Back Seat Middle:
					else if (userInt == 4) {
						for (int i = 0; i < compacts.size(); i++)
						{
							if (sedans.at(i).seatCheckSedan(userInt-1) == true)
							{
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(1);

								pinMaker(pinNum);
								tempCompleted.SetPin(pinNum.at(pinCount));
								cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(i+6);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);

								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 1);

								system("pause");
								return;
							}
						}
					}

					//Error Check:
					else {
						cout << "You did not enter a number 1-4 going back to main menu\n";
						system("pause");
						return;
					}
				}
	
//***************************************************
// User Specific Vehicle and Seat:
//***************************************************	

				else if (userInt == 2) {
					//allows the user to choose a vehicle type and color:
					cout << "What Vechicle do you want to ride in and seat location\n";
					cout << "Car Type: ";  cin >> carType;
					cout << "car Color: "; cin >> carColor;

					low(carType);
					low(carColor);

					
					//*****************************************************************
					//Truck and its three options for user specified vehicle:
					//*****************************************************************
					if (carType == "truck") {
						//credit check for the truck
						if (personData.at(personLocation).getCredit() < 5) {
							cout << "You do not have enough credits to ride in a truck, returning to main";
							system("pause");
							return;
						}

						//Purple Truck:
						else if (carColor == "purple") {
							
							if (trucks.at(0).seatCheckTruck() == true) {
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(5);

								pinMaker(pinNum);
								tempCompleted.SetPin(pinNum.at(pinCount));
								cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(0);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);
								
								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

								system("pause");
								return;
							}
						}

						//Green Truck:
						else if (carColor == "green"){
							if (trucks.at(1).seatCheckTruck() == true) {
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(5);

								pinMaker(pinNum);
								tempCompleted.SetPin(pinNum.at(pinCount));
								cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(1);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);

								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

								system("pause");
								return;
							}
						}

						//Black Truck:
						else if (carColor == "black"){
							if(trucks.at(2).seatCheckTruck() == true)
							{
								cout << "\nReservation Made\n\n";
								tempCompleted.SetCost(5);

								tempCompleted.SetPin(999);//needs to be set random 100-999?
								
								//print the pin to the user
								////////////////////////

								tempCompleted.SetVehicleNum(2);
								tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
								completedReservation.push_back(tempCompleted);

								//subtracts 5 credits from the persons current credit ammount
								personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);


								system("pause");
								return;
							}
						}

						//Error Check:
						else {
							cout << "The truck you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}

			        //*****************************************************************
				    //Compact and its three options for user specified vehicle:
				    //*****************************************************************
					else if (carType == "compact") {


						//Red Compact:
						if (personData.at(personLocation).getCredit() < 3) {
							cout << "\nyou do not have eough credits to ride in a compact, returing to main\n";
							system("pause");
							return;
						}

						//Cost Menu to Display seat costs with its option:
						cout << "\n\nEnter 1-4 for the seat type you want\n";
						cout << "     Position                Cost \n";
						cout << "(1) Front Seat                5\n";
						cout << "(2) Compact Back Seat         3\n";
						cout << "Seat: "; cin >> userInt;

						

						if (carColor == "red") {
							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride front seat in a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(0).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(3);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);
										
										system("pause"); 
										return;
									}
								}
							}// front seat compact

							//----------------------------------------------------------------------------------------------------
							//Back Seat 
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 3) {
									cout << "You do not have enough credits to ride in the back seat of a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(0).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(3);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(3);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 3);
										
										system("pause"); 
										return;
									}
								}
							}// back seat comppact

							else {
								cout << "Invalid input, returing to main.";
								system("pause");
								return;
							}
						}

						//Blue Compact:
						else if (carColor == "blue") {
							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride front seat in a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(1).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(4);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

										system("pause");
										return;
									}
								}
							}// front seat compact

							//----------------------------------------------------------------------------------------------------
							//Back Seat 
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 3) {
									cout << "You do not have enough credits to ride in the back seat of a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(1).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(3);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(4);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 3);

										system("pause"); 
										return;
									}
								}
							}// back seat comppact

							else {
								cout << "Invalid input, returing to main.";
								system("pause");
								return;
							}
						}

						//Yellow Compact:
						else if (carColor == "yellow") {
							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride front seat in a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(2).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(5);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

										system("pause"); 
										return;
									}
								}
							}// front seat compact

							//----------------------------------------------------------------------------------------------------
							//Back Seat 
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 3) {
									cout << "You do not have enough credits to ride in the back seat of a compact, returning to main";
									system("pause");
									return;
								}

								else {
									if (compacts.at(2).seatCheckCompact(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(3);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(5);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 3);

										system("pause"); 
										return;
									}
								}
							}// back seat comppact

							else {
								cout << "Invalid input, returing to main.";
								system("pause");
								return;
							}
						}

						//Error Check:
						else {
							cout << "The Compact you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}


						
					//*****************************************************************
					//Sedan and its three options for user specified vehicle
					//*****************************************************************
					else if (carType == "sedan") {
						
					//Cost Menu to Display seat costs with its option:
					cout << "\n\nEnter 1-4 for the seat type you want\n";
					cout << "     Position                Cost \n";
					cout << "(1) Front Seat                5\n";
					cout << "(2) Sedan Back Seat Outside   2\n";
					cout << "(3) Sedan Back Seat Middle    1\n";
					cout << "Seat: "; cin >> userInt;

						//----------------------------------------------------------------------------------------------------
						//Blue Sedan:
						//----------------------------------------------------------------------------------------------------
						if (carColor == "blue") {
							//if avaiable ask the user to confirm then make pin and return to main

							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride front seat in a Sedan, returning to main";
									system("pause");
									return;
								}

								else {
									if (sedans.at(0).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(6);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

										system("pause"); 
										return;
									}
								} // front seat sedan
							}

							//----------------------------------------------------------------------------------------------------
							//Back Seat Outside
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 2) {
									cout << "You do not have enough credits to ride in the outside back seat of a sedan, returning to main";
									system("pause");
									return;
								}

								else {
									if (sedans.at(0).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(2);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(6);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 2);

										system("pause"); 
										return;
									}
								} 
							}// back seat outside sedan	

							//----------------------------------------------------------------------------------------------------
							//Back Seat Middle
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 3) {
								if (sedans.at(0).seatCheckSedan(userInt) == true)
								{
									cout << "\nReservation Made\n\n";
									tempCompleted.SetCost(1);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(6);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 1);
									
									system("pause"); 
									return;
								}
							}// back seat middle sedan

							else { //error check for the seat map from user input
								cout << "Invalid input, returning to main.\n";
								system("pause");
								return;
							}
						}

						//----------------------------------------------------------------------------------------------------
						//Black Sedan:
						//----------------------------------------------------------------------------------------------------						
						else if (carColor == "black") {
							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride in a truck, returning to main";
									system("pause");
									return;
								}

								else {
									if (sedans.at(1).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(7);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

										system("pause"); 
										return;
									}
								}
							} // front seat sedan

							//----------------------------------------------------------------------------------------------------
							//Back Seat Outside
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 2) {
									cout << "You do not have enough credits to ride in a truck, returning to main";
									system("pause");
									return;
								}

								else {
									if (sedans.at(1).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(2);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(7);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 2);

										system("pause"); 
										return;
									}
								}
							}// back seat outside sedan
	
							//----------------------------------------------------------------------------------------------------
							//Back Seat Middle
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 3) {

								if (sedans.at(1).seatCheckSedan(userInt) == true)
								{
									cout << "\nReservation Made\n\n";
									tempCompleted.SetCost(1);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(7);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 1);

									system("pause"); 
									return;
								}
							}// back seat middle sedan
							
							else { //error check for the seat map from user input
								cout << "Invalid input, returning to main.\n";
								system("pause");
								return;
							}
						}

						//----------------------------------------------------------------------------------------------------
						//Green Sedan:
						//----------------------------------------------------------------------------------------------------
						else if (carColor == "green") {

							//----------------------------------------------------------------------------------------------------		
							//Front Seat
							//----------------------------------------------------------------------------------------------------
							if (userInt == 1) {
								if (personData.at(personLocation).getCredit() < 5) {
									cout << "You do not have enough credits to ride in a truck, returning to main";
									system("pause");
									return;
								}

								else {
									if (sedans.at(2).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(5);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(8);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 5);

										system("pause"); 
										return;
									}
								} // front seat sedan
							}

							//----------------------------------------------------------------------------------------------------
							//Back Seat Outside
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 2) {
								if (personData.at(personLocation).getCredit() < 2) {
									cout << "You do not have enough credits to ride in a truck, returning to main";
									system("pause");
									return;
								}

								else {

									if (sedans.at(2).seatCheckSedan(userInt) == true)
									{
										cout << "\nReservation Made\n\n";
										tempCompleted.SetCost(2);

										pinMaker(pinNum);
										tempCompleted.SetPin(pinNum.at(pinCount));
										cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
										//print the pin to the user
										////////////////////////

										tempCompleted.SetVehicleNum(8);
										tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
										completedReservation.push_back(tempCompleted);

										//subtracts 5 credits from the persons current credit ammount
										personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 2);

										system("pause");
										return;
									}
								}
							}// back seat outside sedan

							//----------------------------------------------------------------------------------------------------
							//Back Seat Middle
							//----------------------------------------------------------------------------------------------------
							else if (userInt == 3) {

								if (sedans.at(2).seatCheckSedan(userInt) == true)
								{
									cout << "\nReservation Made\n\n";
									tempCompleted.SetCost(1);

									pinMaker(pinNum);
									tempCompleted.SetPin(pinNum.at(pinCount));
									cout << "Remeber Your PIN  : " << /*insert PIN Here*/ pinNum.at(pinCount) << "\n";
									//print the pin to the user
									////////////////////////

									tempCompleted.SetVehicleNum(8);
									tempCompleted.SetFirstName(personData.at(personLocation).Person::getFirstName());
									completedReservation.push_back(tempCompleted);

									//subtracts 5 credits from the persons current credit ammount
									personData.at(personLocation).setCreditData(personData.at(personLocation).getCredit() - 1);
									
									system("pause");
									return;
								}
							}// back seat middle sedan


							else { //error check for the seat map from user input
								cout << "Invalid input, returning to main.\n";
								system("pause");
								return;
							}
						}


						//Error Check for sedan color:
						else {
							cout << "The Sedan you entered does not exist, returing to main menu.";
							system("pause");
							return;
						}
					}//car type == sedan 

					//Error check for vehicle make:
					else {
						cout << "You did not enter a valid vehicle type, returning to main.\n";
						system("pause");
						return;
					}
				}

				//----------------------------------------------------------------------------------------------------
				//Error check option between vehicle choice or auto:
				//----------------------------------------------------------------------------------------------------
				else {
					cout << "you did not enter a 1 or a 2, returning to main.\n";
					system("pause");
					return;
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

//*****************************************************************************************************
// Delete Reservation:
//*****************************************************************************************************
//This allows a person to delete an existing reservation that they have.
// Takes in the person class and Reservation class to verify a user has a created Reservation and a saved PIN:
void Reservation::deleteReservation(vector<Reservation>& completedReservation, vector<Person>& personData, vector<Truck>& trucks, vector<Compact>& compacts, vector<Sedan>& sedans) {

	string userInput, carType, carColor, tempString;
	int userInt; //pin input from user
	vector<int>pinNum;
	bool resCheck; //used to check to see if a reservation was made.

	int reservationLocation;

	cout << "\n\nDelete Reservation\n";
	cout << "------------------\n";
	cout << "First Name: "; cin >> userInput;
	cout << "Pin       : "; cin >> userInt;

	nameLow(userInput); //modifies the user name to have first letter uppercase and the rest lower

	for (reservationLocation = 0; reservationLocation < completedReservation.size(); reservationLocation++) {

		if (userInput == completedReservation.at(reservationLocation).GetName() && userInt == completedReservation.at(reservationLocation).GetPin()) {
			cout << "Reservation found\n";
			if (completedReservation.at(reservationLocation).GetVehicleNum() == 0) {
				//Truck Purple
				cout << "Purple Truck\nCost 5";
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 1) {
				//Truck Green
				cout << "Green Truck\nCost 5";
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 2) {
				//Truck Black
				cout << "Black Truck\nCost 5";
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 3) {
				//Compact Red
				cout << "Red Compact\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 4) {
				//Compact Blue
				cout << "Blue Compact\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 5) {
				//Compact Yellow
				cout << "Yellow Compact\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 6) {
				//Sedan Blue
				cout << "Blue Sedan\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 7) {
				//Sedan Black
				cout << "Black Sedan\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else if (completedReservation.at(reservationLocation).GetVehicleNum() == 8) {
				//Sedan Green
				cout << "Green Sedan\nCost " << completedReservation.at(reservationLocation).GetCost();
			}
			else {
				"ERROR<><>Returning to main.";
				system("pause");
				return;
			}
			cout << "\nWould you like to cancel your reservation (Y/N)\n";
			cout << "choice: "; cin >> userInput;

			if (userInput == "Y" || userInput == "y") {
				for (int i = 0; i < personData.size(); i++) {
					if (personData.at(i).getFirstName() == completedReservation.at(reservationLocation).GetName()) {
						personData.at(i).setCreditData(personData.at(i).getCredit() + completedReservation.at(reservationLocation).GetCost());
					}
				}

				//----------------------------------------------------------------------------------
				//Trucks
				//----------------------------------------------------------------------------------

				//Truck Purple
				if (completedReservation.at(reservationLocation).GetVehicleNum() == 0) {
					trucks.at(0).setSeatTruck();
				}

				//Truck Green
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 1) {
					trucks.at(1).setSeatTruck();
				}

				//Truck Black
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 2) {
					trucks.at(2).setSeatTruck();
				}


				//----------------------------------------------------------------------------------
				//Compacts
				//----------------------------------------------------------------------------------

				//Compact Red
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 3) {

					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(0).setSeatCompact(0);
					}
					//back Seats
					if (completedReservation.at(reservationLocation).GetCost() == 3) {
						//Back Left Seat
						if (compacts.at(0).displaySeatCompact(1) == 'X') {
							compacts.at(0).setSeatCompact(1);
						}
						//back Rigth Seat
						else {
							compacts.at(0).setSeatCompact(2);
						}
					}
				}

				//Compact Blue
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 4) {
					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(1).setSeatCompact(0);
					}
					//back Seats
					if (completedReservation.at(reservationLocation).GetCost() == 3) {
						//Back Left Seat
						if (compacts.at(1).displaySeatCompact(1) == 'X') {
							compacts.at(1).setSeatCompact(1);
						}
						//back Rigth Seat
						else {
							compacts.at(1).setSeatCompact(2);
						}
					}
				}
				//Compact Yellow
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 5) {
					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(2).setSeatCompact(0);
					}
					//back Seats
					if (completedReservation.at(reservationLocation).GetCost() == 3) {
						//Back Left Seat
						if (compacts.at(2).displaySeatCompact(1) == 'X') {
							compacts.at(2).setSeatCompact(1);
						}
						//back Rigth Seat
						else {
							compacts.at(2).setSeatCompact(2);
						}
					}
				}


				//----------------------------------------------------------------------------------
				//Sedans
				//----------------------------------------------------------------------------------

				//Sedan Blue
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 6) {
					//Front Seat
					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(0).setSeatCompact(0);
					}
					//Back Seats Outside
					else if (completedReservation.at(reservationLocation).GetCost() == 2) {
						//Back Left Seat
						if (sedans.at(0).displaySeatSedan(1) == 'X') {
							sedans.at(0).setSeatSedan(1);
						}
						//back Rigth Seat
						else {
							sedans.at(0).setSeatSedan(3);
						}
					}
					//Back seat Middle
					else if (completedReservation.at(reservationLocation).GetCost() == 1) {
						sedans.at(0).setSeatSedan(2);
					}
				}

				//Sedan Black
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 7) {
					//Front Seat
					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(1).setSeatCompact(0);
					}
					//Back Seats Outside
					else if (completedReservation.at(reservationLocation).GetCost() == 2) {
						//Back Left Seat
						if (sedans.at(1).displaySeatSedan(1) == 'X') {
							sedans.at(1).setSeatSedan(1);
						}
						//back Rigth Seat
						else {
							sedans.at(1).setSeatSedan(3);
						}
					}
					//Back seat Middle
					else if (completedReservation.at(reservationLocation).GetCost() == 1) {
						sedans.at(1).setSeatSedan(2);
					}
				}

				//Sedan Green
				else if (completedReservation.at(reservationLocation).GetVehicleNum() == 8) {
					//Front Seat
					if (completedReservation.at(reservationLocation).GetCost() == 5) {
						compacts.at(2).setSeatCompact(0);
					}
					//Back Seats Outside
					else if (completedReservation.at(reservationLocation).GetCost() == 2) {
						//Back Left Seat
						if (sedans.at(2).displaySeatSedan(1) == 'X') {
							sedans.at(2).setSeatSedan(1);
						}
						//back Rigth Seat
						else {
							sedans.at(2).setSeatSedan(3);
						}
					}
					//Back seat Middle
					else if (completedReservation.at(reservationLocation).GetCost() == 1) {
						sedans.at(2).setSeatSedan(2);
					}

				}
				else {
					"ERROR<><>Returning to main.";
					system("pause");
					return;
				}

				system("cls");
				cout << "Deletion canceled, you have ben refunded. Returning to main.\n";
				system("pause");
				completedReservation.erase(completedReservation.begin() + reservationLocation);
				return;
			}


			else {
				cout << "Deletion cancled, returning to main\n";
				system("pause");
				return;
			}
		}

	}
	cout << "No reservation found with " << userInt << " for " << userInput << "\nReturning to Main\n\n";
	system("pause");
	return;




} // Reservation::deleteReservation;


//*****************************************************************************************************
// Print ALL Reservations:
//*****************************************************************************************************
void Reservation::printAllReservations(vector<Reservation> completedReservation, vector<Truck> trucks, vector<Compact> compacts, vector<Sedan> sedans){

	ofstream OutPutFile; //write file
	OutPutFile.open("all_reservations.txt");

	//Truck output
	for (int i = 0; i < 3; i++) {
		int passengerCount = 0;
		OutPutFile << "\n\nTruck " << trucks.at(i).GetColor() << endl;
		OutPutFile << "-------------------\n";
		OutPutFile << "Driver    : " << trucks.at(i).GetDriverFirstName() << endl;
		for (int j = 0; j < completedReservation.size(); j++) {
			if (trucks.at(i).displySeatTruck() == 'X' && completedReservation.at(j).GetVehicleNum() == i) {
				OutPutFile << "Front Seat: " << completedReservation.at(j).GetName() << endl;
				passengerCount++;
			}
		}
		for (passengerCount; passengerCount < 1; passengerCount++) {
			OutPutFile << "Front Seat: Unassigned\n";
		}
	}


	//Compact Output
	
	bool used = false; //used for the double back seats so that way it can get both people 
	vector<string> compactSeatChart;
	compactSeatChart.push_back("Unassigned");
	compactSeatChart.push_back("Unassigned");
	compactSeatChart.push_back("Unassigned");

	for (int i = 0; i < 3; i++) {
		compactSeatChart.at(0) = "Unassigned";
		compactSeatChart.at(1) = "Unassigned";
		compactSeatChart.at(2) = "Unassigned";

		OutPutFile << "\n\nCompact " << compacts.at(i).GetColor() << endl;
		OutPutFile << "-------------------\n";
		OutPutFile << "Driver         : " << compacts.at(i).GetDriverFirstName() << endl;
		for (int j = 0; j < completedReservation.size(); j++) {
			//front seat
			if (compacts.at(i).displaySeatCompact(0) == 'X' && completedReservation.at(j).GetVehicleNum() == i+3) {
				compactSeatChart.at(0) = (completedReservation.at(j).GetName());
			}
			//Back left seat
			else if (compacts.at(i).displaySeatCompact(1) == 'X' && completedReservation.at(j).GetVehicleNum() == i+3 && used == false) {
				compactSeatChart.at(1) = (completedReservation.at(j).GetName());
				//forces it back to the begning to pick up the second back seat
				used = true;
				continue;
			}
			//back right seat
			else if (compacts.at(i).displaySeatCompact(2) == 'X' && completedReservation.at(j).GetVehicleNum() == i+3) {
				compactSeatChart.at(2) = (completedReservation.at(j).GetName());
			}
		}
		OutPutFile << "Front      Seat: " << compactSeatChart.at(0) << endl;
		OutPutFile << "Back Left  Seat: " << compactSeatChart.at(1) << endl;
		OutPutFile << "Back Right Seat: " << compactSeatChart.at(2) << endl;
	}

	used = false;
	//Sedan Output
	vector<string> sedanSeatChart;
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");

	for (int i = 0; i < 3; i++) {
		sedanSeatChart.at(0) = "Unassigned";
		sedanSeatChart.at(1) = "Unassigned";
		sedanSeatChart.at(2) = "Unassigned";
		sedanSeatChart.at(3) = "Unassigned";


		OutPutFile << "\n\nSedan " << sedans.at(i).GetColor() << endl;
		OutPutFile << "-------------------\n";
		OutPutFile << "Driver          : " << sedans.at(i).GetDriverFirstName() << endl;
		for (int j = 0; j < completedReservation.size(); j++) {
			if (sedans.at(i).displaySeatSedan(0) == 'X' && completedReservation.at(j).GetVehicleNum() == i+6) {
				sedanSeatChart.at(0) = (completedReservation.at(j).GetName());
			}
			else if (sedans.at(i).displaySeatSedan(1) == 'X' && completedReservation.at(j).GetVehicleNum() == i+6 && used == false) {
				sedanSeatChart.at(1) = (completedReservation.at(j).GetName());
				//forces it back to the begning to pick up the second back seat
				used = true;
				continue;
			}
			else if (sedans.at(i).displaySeatSedan(2) == 'X' && completedReservation.at(j).GetVehicleNum() == i+6) {
				sedanSeatChart.at(2) = (completedReservation.at(j).GetName());
			}
			else if (sedans.at(i).displaySeatSedan(3) == 'X' && completedReservation.at(j).GetVehicleNum() == i + 6) {
				sedanSeatChart.at(3) = (completedReservation.at(j).GetName());
			}
		}
		OutPutFile << "Front       Seat: " << sedanSeatChart.at(0) << endl;
		OutPutFile << "Back Left   Seat: " << sedanSeatChart.at(1) << endl;
		OutPutFile << "Back Middle Seat: " << sedanSeatChart.at(2) << endl;
		OutPutFile << "Back Right  Seat: " << sedanSeatChart.at(3) << endl;

	}
	cout << "all_reservations.txt made\n\n";
	system("pause");
	OutPutFile.close();
	return;
}


//*****************************************************************************************************
// Print Specific Car Reservations:
//*****************************************************************************************************
void Reservation::printOneReservation(string color, string vehicle, vector<Reservation> completedReservation, vector<Truck> trucks, vector <Compact> compacts, vector <Sedan> sedans) {
	ofstream OutPutFile;
	
	//forces color and vehicle to be lowercase
	low(color);
	low(vehicle);

	//creates the custom file name
	string fileName = color;
	fileName.append("_");	
	fileName.append(vehicle);
	fileName.append(".txt");
	OutPutFile.open(fileName);
	
	//Truck loop
	if (vehicle == "truck" ) {
		if (color == "purple") {
			
				int passengerCount = 0;
				OutPutFile << "Truck Purple \n";
				OutPutFile << "-------------------\n";
				OutPutFile << "Driver    : " << trucks.at(0).GetDriverFirstName() << endl;
				for (int j = 0; j < completedReservation.size(); j++) {
					if (trucks.at(0).displySeatTruck() == 'X' && completedReservation.at(j).GetVehicleNum() == 0) {
						OutPutFile << "Front Seat: " << completedReservation.at(j).GetName() << endl;
						passengerCount++;
					}
				}
				for (passengerCount; passengerCount != 1; passengerCount++) {
					OutPutFile << "Front Seat: Unassigned\n";
				}
			cout << "Reservation list purple_truck.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");

			return;
		}
		
		else if (color == "green") {
			
				int passengerCount = 0;
				OutPutFile << "Truck Green \n";
				OutPutFile << "-------------------\n";
				OutPutFile << "Driver    : " << trucks.at(1).GetDriverFirstName() << endl;
				for (int j = 0; j < completedReservation.size(); j++) {
					if (trucks.at(1).displySeatTruck() == 'X' && completedReservation.at(j).GetVehicleNum() == 0) {
						OutPutFile << "Front Seat: " << completedReservation.at(j).GetName() << endl;
						passengerCount++;
					}
				}
				for (passengerCount; passengerCount != 1; passengerCount++) {
					OutPutFile << "Front Seat: Unassigned\n";
				}
			cout << "Reservation list green_truck.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");
			return;
		}

		else if (color ==  "black") {
				int passengerCount = 0;
				OutPutFile << "Truck Black\n";
				OutPutFile << "-------------------\n";
				OutPutFile << "Driver    : " << trucks.at(2).GetDriverFirstName() << endl;
				for (int j = 0; j < completedReservation.size(); j++) {
					if (trucks.at(2).displySeatTruck() == 'X' && completedReservation.at(j).GetVehicleNum() == 0) {
						OutPutFile << "Front Seat: " << completedReservation.at(j).GetName() << endl;
						passengerCount++;
					}
				}
				for (passengerCount; passengerCount != 1; passengerCount++) {
					OutPutFile << "Front Seat: Unassigned\n";
				}
			cout << "Reservation list black_truck.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");
			return;
		}

		else { //no Truck found
			cout << "A Truck mathing that description was not found, returning to main\n";
			system("pause");
			return;
		}
	}
	
	//Compact loop
	else if (vehicle == "compact") {
		vector<string> compactSeatChart;
		compactSeatChart.push_back("Unassigned");
		compactSeatChart.push_back("Unassigned");
		compactSeatChart.push_back("Unassigned");
		
		bool used = false;

		if (color == "red") {

			OutPutFile << "Compact         Red\n";
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver         : " << compacts.at(0).GetDriverFirstName() << endl;
			for (int j = 0; j < completedReservation.size(); j++) {
				if (compacts.at(0).displaySeatCompact(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 3) {
					compactSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (compacts.at(0).displaySeatCompact(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 3 && used == false) {
					compactSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (compacts.at(0).displaySeatCompact(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 3) {
					compactSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front      Seat: " << compactSeatChart.at(0) << endl;
			OutPutFile << "Back Left  Seat: " << compactSeatChart.at(1) << endl;
			OutPutFile << "Back Right Seat: " << compactSeatChart.at(2) << endl;

			cout << "Reservation list red_compact.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");
			return;
		}

		else if (color == "blue") {
			OutPutFile << "Compact        Blue\n";
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver         : " << compacts.at(1).GetDriverFirstName() << endl;
			for (int j = 0; j < completedReservation.size(); j++) {
				if (compacts.at(1).displaySeatCompact(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 4) {
					compactSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (compacts.at(1).displaySeatCompact(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 4 && used == false) {
					compactSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (compacts.at(1).displaySeatCompact(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 4) {
					compactSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front      Seat: " << compactSeatChart.at(0) << endl;
			OutPutFile << "Back Left  Seat: " << compactSeatChart.at(1) << endl;
			OutPutFile << "Back Right Seat: " << compactSeatChart.at(2) << endl;

			cout << "Reservation list blue_compact.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");
			return;
		}

		else if (color == "yellow") {
			OutPutFile << "Compact      Yellow\n";
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver         : " << compacts.at(2).GetDriverFirstName() << endl;
			for (int j = 0; j < completedReservation.size(); j++) {
				if (compacts.at(2).displaySeatCompact(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 5) {
					compactSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (compacts.at(2).displaySeatCompact(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 5 && used == false) {
					compactSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (compacts.at(2).displaySeatCompact(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 5) {
					compactSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front      Seat: " << compactSeatChart.at(0) << endl;
			OutPutFile << "Back Left  Seat: " << compactSeatChart.at(1) << endl;
			OutPutFile << "Back Right Seat: " << compactSeatChart.at(2) << endl;
		
			cout << "Reservation list yellow_compact.txt made, returning to main\n";
			OutPutFile.close();
			system("pause");
			return;
		}

		else { //no compact found
			cout << "A Compact mathing that description was not found, returning to main\n";
			system("pause");
			return;
		}
	}

	//Sedan loop
	else if (vehicle == "sedan") {
	vector<string> sedanSeatChart;
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");
	sedanSeatChart.push_back("Unassigned");

	bool used = false;

		if (color == "blue") {
			OutPutFile << "Sedan          Blue\n";    
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver          : " << sedans.at(0).GetDriverFirstName() << endl;
			
			
			for (int j = 0; j < completedReservation.size(); j++) {
				if (sedans.at(0).displaySeatSedan(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 6) {
					sedanSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(0).displaySeatSedan(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 6 && used == false) {
					sedanSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (sedans.at(0).displaySeatSedan(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 6) {
					sedanSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(0).displaySeatSedan(3) == 'X' && completedReservation.at(j).GetVehicleNum() == 6) {
					sedanSeatChart.at(3) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front       Seat: " << sedanSeatChart.at(0) << endl;
			OutPutFile << "Back Left   Seat: " << sedanSeatChart.at(1) << endl;
			OutPutFile << "Back Middle Seat: " << sedanSeatChart.at(2) << endl;
			OutPutFile << "Back Right  Seat: " << sedanSeatChart.at(3) << endl;


		}

		else if (color == "black") {

			OutPutFile << "Sedan         Black\n" ;
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver          : " << sedans.at(1).GetDriverFirstName() << endl;
			for (int j = 0; j < completedReservation.size(); j++) {
				if (sedans.at(1).displaySeatSedan(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 7) {
					sedanSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(1).displaySeatSedan(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 7 && used == false) {
					sedanSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (sedans.at(1).displaySeatSedan(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 7) {
					sedanSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(1).displaySeatSedan(3) == 'X' && completedReservation.at(j).GetVehicleNum() == 7) {
					sedanSeatChart.at(3) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front       Seat: " << sedanSeatChart.at(0) << endl;
			OutPutFile << "Back Left   Seat: " << sedanSeatChart.at(1) << endl;
			OutPutFile << "Back Middle Seat: " << sedanSeatChart.at(2) << endl;
			OutPutFile << "Back Right  Seat: " << sedanSeatChart.at(3) << endl;


		}

		else if (color == "green") {
			OutPutFile << "Sedan         Green\n";
			OutPutFile << "-------------------\n";
			OutPutFile << "Driver          : " << sedans.at(2).GetDriverFirstName() << endl;
			for (int j = 0; j < completedReservation.size(); j++) {
				if (sedans.at(2).displaySeatSedan(0) == 'X' && completedReservation.at(j).GetVehicleNum() == 8) {
					sedanSeatChart.at(0) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(2).displaySeatSedan(1) == 'X' && completedReservation.at(j).GetVehicleNum() == 8 && used == false) {
					sedanSeatChart.at(1) = (completedReservation.at(j).GetName());
					//forces it back to the begning to pick up the second back seat
					used = true;
					continue;
				}
				else if (sedans.at(2).displaySeatSedan(2) == 'X' && completedReservation.at(j).GetVehicleNum() == 8) {
					sedanSeatChart.at(2) = (completedReservation.at(j).GetName());
				}
				else if (sedans.at(2).displaySeatSedan(3) == 'X' && completedReservation.at(j).GetVehicleNum() == 8) {
					sedanSeatChart.at(3) = (completedReservation.at(j).GetName());
				}
			}
			OutPutFile << "Front       Seat: " << sedanSeatChart.at(0) << endl;
			OutPutFile << "Back Left   Seat: " << sedanSeatChart.at(1) << endl;
			OutPutFile << "Back Middle Seat: " << sedanSeatChart.at(2) << endl;
			OutPutFile << "Back Right  Seat: " << sedanSeatChart.at(3) << endl;

		}

		else { //no sedan found
			cout << "A Sedan mathing that description was not found, returning to main\n";
			system("pause");
			return;
		}

	}

	else { //No vehicle found
		cout << vehicle << " was not found, returning to main\n"; 
		system("pause");
		return;
	}
}


//*****************************************************************************************************
// Lowercase Conversion & pinMaker Functions:
//*****************************************************************************************************

//used to convert user input to lower case for car type
void nameLow(string& userInput) {
	string tempString;
	//Forces first letter of the person name to upper case and the rest to lower:
	tempString.push_back(toupper(userInput.at(0)));
	for (int i = 1; i < userInput.size(); i++) {
		tempString.push_back(tolower(userInput.at(i)));
	}
	userInput = tempString;
}


void low(string& inWord) {
	string tempString;
	for (int i = 0; i < inWord.size(); i++) {
		tempString.push_back(tolower(inWord.at(i)));
	} 
	inWord = tempString;
}

//Generates a Random & Unique Three Digit PIN:
void pinMaker(vector<int>& pinNum) {

	bool notUnique = false;
	srand(time(NULL)); // Seeds the rand()
		int tempPin = (rand() % 898) + 101; //Temporary Generated Pin Value

		//Checks If the PIN has been used Before:
		for (int i = 0; i < pinNum.size(); i++) {

			tempPin = (rand() % 898) + 101; // Assigns tempPin with a Random Value 100 - 998

			if (pinNum.at(i) == tempPin)
			{
				notUnique = true;
				break;  // Leaves loop and will Jump to generating a new pin.
			}
		}

		//If the PIN is unique, then it will add it to the PIN vector:
		if (!notUnique)
		{
			pinNum.push_back(tempPin);
		}
}
