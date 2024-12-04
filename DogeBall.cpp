//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: DodgeBall.cpp
// Description: Program serves as a function allowing for players to Create, Modify, and Reserve seating options based on thier credits
//////////////////////////////////////////////

#include "DogeBall.h"
#include "person.h"
#include "reservation.h"
#include "truck.h"
#include "sedan.h"
#include "compact.h"


ifstream openInputFile();
ofstream openOutputFile();

using namespace NS_Person;
using namespace NS_Reservation;
using namespace NS_Truck;
using namespace NS_Sedan;
using namespace NS_Compact;


void createTruck(vector<Truck>&);
void createSedan(vector<Sedan>&);
void createCompact(vector<Compact>&);

//updated

int main() {
	
	//Variables
	//**************************************************************************************\\
	//file
	ifstream inFile_dodgeball;
	ofstream outFIle_dodgeball; 	

	//Person class variables
	vector<Person> personData; //Stores First and Last names and the credits
	

	//Reservation Class Variables
	Reservation reservationTemp; //
	vector<Reservation> completedReservation;
	

	//Vehicle Class Variables
	vector<Truck>   trucks;
	vector<Sedan>   sedans;
	vector<Compact> compacts;
	string carType; //user input to get the type of the car


	//variables main
	string userInput, pin, firstName, lastName;
	int credit;
	int counts = 0; //used to get the drivers
	bool reservationCheck = false; //used to make sure a reservation was made

//*****************************************************************************************************
//  Reads in dodgeball.dat input file and puts all the Drivers, Passengers, and thier credits into Person Class:
//*****************************************************************************************************
	
	//opens the input file of dodgeball.dat:
	inFile_dodgeball = openInputFile();
	
	//put person class function here
	//populate person class from input file
	while (inFile_dodgeball.good()) {
		//Grabs the first 9 people from the txt file
		//As they are drivers it assigns -1 crdits to them
		while (counts < 9) {
			inFile_dodgeball >> firstName >> lastName; //run 9 times for driver
			credit = -1; //used as a sentinal value
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


	//used for testing to display all names
	//for (auto i : personData) {
	//	i.displayFirstName();
	//	i.displayLastName();
	//	i.displayCredit();
	//	cout << endl;
	//}
	//////////////////////////////////////////


	//opens the output files
	outFIle_dodgeball = openOutputFile();
	
	while (true) {
		system("cls"); //clear the cmd for every loop

		//menu display
		cout << "Dodge Ball Car pool Reservation:\n";
		cout << "-------------------------------\n\n";
		cout << "(1) Create Reservation\n";
		cout << "(2) Modify Reservation\n";
		cout << "(3) Delete Reservation\n";
		cout << "(4) Print  Reservations\n\n";


		//user input for menu
		cout << "option: ";
		cin >> userInput;

		
		//options 1	
		//this will allow the user to create a reservation
		if (userInput == "1") {
			 reservationTemp.createReservation(completedReservation, personData, trucks, compacts, sedans);

		}

		//Option 2
		//This will allow the user to modify a reservation that has already been made
		else if (userInput == "2") {

		}

		//Option 3
		//This will allow a user to delete a reservation that has been made delete reservation
		else if (userInput == "3") {

		}

		//Option 4
		//This will print all made reservation
		else if (userInput == "4") {

		}

		else {
			cout << "Error invalid input\nPlease enter a number 1-4";
			system("pause");
			continue;
		}
	}

	return 0;
}

//*****************************************************************************************************
// Car Object Creations and Input / Output File definitions:
//*****************************************************************************************************

//creates the three objects of Truck as a vector
//with driver name first, last, and car color
void createTruck(vector<Truck>& trucks) {
	Truck tempTruck;
	//purple pat cooper
	tempTruck.SetDriverName("Pat", "Cooper", "Purple");
	tempTruck.Truck::Truck();
	trucks.push_back(tempTruck);

	//Green Jane Cox
	tempTruck.SetDriverName("Jane", "Cox", "Green");
	tempTruck.Truck::Truck();
	trucks.push_back(tempTruck);

	//Black  Tim Taylor
	tempTruck.SetDriverName("Tim", "Taylor", "Black");
	tempTruck.Truck::Truck();
	trucks.push_back(tempTruck);
}

//Creates the three objects of Compact as a vector
//with driver name first, last, and car color
void createCompact(vector<Compact>& compacts) {
	Compact tempCompact;
	//red Ben Butler
	tempCompact.SetDriverName("Ben", "Butler", "Red");
	tempCompact.Compact::Compact();
	compacts.push_back(tempCompact);

	//Blue Art Campbell
	tempCompact.SetDriverName("Art", "Campbell", "Blue");
	tempCompact.Compact::Compact();
	compacts.push_back(tempCompact);

    //Yellow Ann Edwards
	tempCompact.SetDriverName("Ann", "Edwards", "Yellow");
	tempCompact.Compact::Compact();
	compacts.push_back(tempCompact);
}

//Crteates the three objects of Sedan as a vector
//with driver name first, last, and car color
void createSedan(vector<Sedan>& sedans) {
	//Blue Grace Wan
	Sedan tempSedan;
	tempSedan.SetDriverName("Grace", "Wan", "Blue");
	tempSedan.Sedan::Sedan();
	sedans.push_back(tempSedan);
	//Black Lary Adams
	tempSedan.SetDriverName( "Larry", "Adams", "Black");
	tempSedan.Sedan::Sedan();
	sedans.push_back(tempSedan);

	//Green Jessie Quirk
	tempSedan.SetDriverName("Jessie", "Quirk", "Green");
	tempSedan.Sedan::Sedan();
	sedans.push_back(tempSedan);
}


//Input file fuction
ifstream openInputFile() {
	//------------------------------------------------------
	//variable ste up
	//------------------------------------------------------
	ifstream inPutFile("dodgeball.dat"); //read file

	//------------------------------------------------------
	//usedd to open a file in read mode
	//------------------------------------------------------
		if (!inPutFile.is_open()) {			 //error check
		cout << "\nBad File Path... Program Terminated\n";
		exit(1);
	}
	return inPutFile; //returns the file path to main
}


//Output file function
ofstream openOutputFile() {
	//------------------------------------------------------
	//variable ste up
	//------------------------------------------------------
	ofstream OutPutFile; //write file
	string userFile_out; //user defined file name

	//------------------------------------------------------
	//used to open a file in write mode
	//------------------------------------------------------
	OutPutFile.open("OUT_dodgeball.dat"); //opens the file
	if (!OutPutFile.is_open()) {      //error check for if file cannot be opened
		cout << "\nBad File Path... Program Terminated\n";
		exit(1);
	}


	return OutPutFile; //returns the file path to main
}

//*****************************************************************************************************
