//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: DodgeBall.cpp
// Description: Program serves as a function allowing for players to Create, Modify, and Reserve seating options based on thier credits:
//////////////////////////////////////////////

//Header Files, NameSpace Definitions, Vehicle initiation Function Prototypes:
#include "DogeBall.h"
#include "person.h"
#include "reservation.h"
#include "truck.h"
#include "sedan.h"
#include "compact.h"

//In-Out Files
ifstream openInputFile();

void updateRoster(vector<Person>);



using namespace NS_Person;
using namespace NS_Reservation;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;

// Creates All 9 cars and assigns Approprioate Values:
void createTruck(vector<Truck>&);
void createSedan(vector<Sedan>&);
void createCompact(vector<Compact>&);

void displayReservations(vector<Truck>, vector<Compact>, vector<Sedan>);


int main() {
	
	//Variables:
	//**************************************************************************************\\

	//file:
	ifstream inFile_dodgeball;
	ofstream outFIle_dodgeball; 	

	//Person Class Variables:
	vector<Person> personData; // <- Stores First and Last names and the credits.

	//Reservation Class Variables:
	Reservation reservationTemp;
	vector<Reservation> completedReservation;

	//Vehicle Class Variables:
	vector<Truck>   trucks;
	vector<Sedan>   sedans;
	vector<Compact> compacts;
	string carType; // <- User input to get the type of the car.

	//Variables used in Main:
	string color, vehicle; //used for the specific print of the reservation
	string userInput, pin, firstName, lastName;
	int credit;
	int counts = 0; //<- used to get the drivers.
	bool modify;// <- used to make sure modify is true.

//*****************************************************************************************************
//  Reads in dodgeball.dat input file and puts all the Drivers, Passengers, and thier credits into Person Class:
//*****************************************************************************************************
	
	//opens the input file of dodgeball.dat:
	inFile_dodgeball = openInputFile();
	
	//put person class function here 

	//populate person class from input file:
	while (inFile_dodgeball.good()) {
		//Grabs the first 9 people from the txt file
		//As they are drivers it assigns -1 crdits to them:
		while (counts < 9) {
			inFile_dodgeball >> firstName >> lastName; // <- run 9 times for driver
			credit = -1; //<- used as a sentinal value
			counts++;

			personData.push_back(Person(firstName, lastName, credit)); //populates the person class with the drivers
		}

		inFile_dodgeball >> firstName >> lastName >> credit; //gets the remaing people from the file that are not drivers
		personData.push_back(Person(firstName, lastName, credit)); //populates the person class with the passengers
	}

	inFile_dodgeball.close();
//**********************************************************************************************************
// Initiates Object Calls along with Providing the Main Menu to call Functions and Classes:
//**********************************************************************************************************
 
	//calls the functions for the three vehicle types to create three objects of each:
	createTruck(trucks);
	createCompact(compacts);
	createSedan(sedans);

	while (true) {

		modify = false; //resets at the start of each new run
		system("cls"); //clear the cmd for every loop

		//Menu Display:
		cout << "Dodge Ball Car pool Reservation:\n";
		cout << "-------------------------------\n\n";
		cout << "(1) Create A  Reservation\n";
		cout << "(2) Modify A  Reservation\n";
		cout << "(3) Delete A  Reservation\n";
		cout << "(4) Display   Reservations\n";
		cout << "(5) Print All Reservations\n";
		cout << "(6) Print One Reservation\n";
		cout << "(-1) Quit\n\n";
		cout << "option: ";
		cin >> userInput; 	//user input for menu

		
		//Option 1. This will allow the user to Create a reservation:
		if (userInput == "1") {
			 reservationTemp.createReservation(completedReservation, personData, trucks, compacts, sedans, modify, firstName);
		}

		//Option 2. This will allow the user to Modify a reservation that has already been made:
		else if (userInput == "2") {
			reservationTemp.modifyReservation(completedReservation, personData, trucks, compacts, sedans, modify);
		}

		//Option 3. This will allow a user to Delete a reservation that has been made delete reservation:
		else if (userInput == "3") {
			reservationTemp.deleteReservation(completedReservation, personData, trucks, compacts, sedans, modify, credit, firstName);
		}

		else if (userInput == "4") {
			displayReservations(trucks, compacts, sedans);
		}

		//Option 4. This will Print all reservations:
		else if (userInput == "5") {
			reservationTemp.printAllReservations(completedReservation, trucks, compacts, sedans);
		}
		
		//Option 5. This will print a single car's reservation
		else if (userInput == "6") {
			cout << "Cose a vehicle to print the reservation list for\n"; 
			cout << "Vehicle : "; cin >> vehicle;
			cout << "Color   : "; cin >> color;
			
			reservationTemp.printOneReservation(color, vehicle, completedReservation, trucks, compacts, sedans);
		}

		//Errorr Check Case:
		else if (userInput == "-1") {
			exit(1);
		}
		else {
			cout << "Error invalid input\nPlease enter a number 1-4";
			system("pause");
			continue;
		}
		updateRoster(personData);
	}

	return 0;
}



//*****************************************************************************************************
// Updated Roster credit list function
//*****************************************************************************************************

void updateRoster(vector<Person> personData) {
	int counts = 0;
	ofstream OutPutFile;
	OutPutFile.open("UpdatedRoster.dat");
	//populate the output file with the 
	for (int i = 0; i < personData.size(); i ++) {
		//Grabs the first 9 people (Drivers) and adds them to the file
		while (i < 9) {
			OutPutFile << personData.at(i).getFirstName() << " " << personData.at(i).getLastName() << endl; // <- run 9 times for driver
			i++;
		}

		OutPutFile << personData.at(i).getFirstName() << " " << personData.at(i).getLastName() << " " << personData.at(i).getCredit() << endl; //gets the remaing people from the file that are not drivers
	}

	OutPutFile.close();
}


//*****************************************************************************************************
// Display all Vehices:
//*****************************************************************************************************

void displayReservations(vector<Truck> trucks, vector<Compact> compacts, vector<Sedan>sedans) {

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

	system("pause");
}

//*****************************************************************************************************
// Car Object Creations and Input / Output File definitions:
//*****************************************************************************************************

//creates the three objects of Truck as a vector
//with driver name first, last, and car color:
void createTruck(vector<Truck>& trucks) {
	Truck tempTruck;
	//Purple Pat Cooper:
	tempTruck.SetDriverName("Pat", "Cooper", "Purple");
	trucks.push_back(tempTruck);

	//Green Jane Cox:
	tempTruck.SetDriverName("Jane", "Cox", "Green");
	trucks.push_back(tempTruck);

	//Black Tim Taylor:
	tempTruck.SetDriverName("Tim", "Taylor", "Black");
	trucks.push_back(tempTruck);
}

//Creates the three objects of Compact as a vector
//with driver name first, last, and car color:
void createCompact(vector<Compact>& compacts) {
	Compact tempCompact;
	//Red Ben Butler:
	tempCompact.SetDriverName("Ben", "Butler", "Red");
	compacts.push_back(tempCompact);

	//Blue Art Campbell:
	tempCompact.SetDriverName("Art", "Campbell", "Blue");
	compacts.push_back(tempCompact);

    //Yellow Ann Edwards:
	tempCompact.SetDriverName("Ann", "Edwards", "Yellow");
	compacts.push_back(tempCompact);
}

//Crteates the three objects of Sedan as a vector
//with driver name first, last, and car color:
void createSedan(vector<Sedan>& sedans) {
	//Blue Grace Wan:
	Sedan tempSedan;
	tempSedan.SetDriverName("Grace", "Wan", "Blue");
	sedans.push_back(tempSedan);

	//Black Lary Adams:
	tempSedan.SetDriverName( "Larry", "Adams", "Black");
	sedans.push_back(tempSedan);

	//Green Jessie Quirk:
	tempSedan.SetDriverName("Jessie", "Quirk", "Green");
	sedans.push_back(tempSedan);
}


//Input file fuction:
ifstream openInputFile() {
	
	ifstream inPutFile("dodgeball.dat"); //read file

	// Error Check:
		if (!inPutFile.is_open()) {
		cout << "\nBad File Path... Program Terminated\n";
		exit(1);
	}

	return inPutFile; //returns the file path to main.
}