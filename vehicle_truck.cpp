
#include "DogeBall.h"
#include "vehicle.h"
#include "truck.h"

using namespace NS_Truck;
using namespace NS_Vehicle;

Truck::Truck() {            //pos   val
	seat_T.push_back('5');  // 0     5
}

//prints the truck image
void Truck::displayTruck() {

	//    Truck
	//    _   _
	//  --|---|--
	//  | X   - |
	//  |       |
	//  ---------	
	//Print Driver Name

	//Extra (add if time allows)
	//Print Passanger 1
	//Print Passanger 2
	//Print Passanger 3

	cout << "------";
	cout << "|X   " << seat_T.at(0) << "|";
}

//reutens back the vector of seat
char Truck::displySeatTruck() {
	return seat_T.at(0);
} 

//checks to see if the seat is valid
//returns true if the seat is open
//else false
bool Truck::seatCheckTruck() {
	string userInput;
	if (seat_T.at(0) = '5') {
		cout << "The front seat is avaliable, would you like to reserve it Y/N\n";
		cout << "choice: "; cin >> userInput;
		//conformation check to make the reservation
		if (userInput == "Y" || userInput == "y") {
			//update the truck to show the spot has been claimed
			cout << "congrats, reservation made, returing to main.";
			seat_T.at(0) = 'X';
			return true;
		}
		else { //if user cancels reservation
			cout << "reservation cancled, returing to main";
			system("pause");
		}
	}

	else { //if seat is already claimed
		return false;
	}
} 