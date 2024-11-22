//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: DodgeBall.cpp
// Description: Program serves as a function allowing for players to Create, Modify, and Reserve seating options based on thier credits
//////////////////////////////////////////////

#include "DogeBall.h"
#include "person.h"

ifstream openInputFile();
ofstream openOutputFile();

using namespace NS_Person;

int main() {

	//file variables
	ifstream inFile_dodgeball;
	ofstream dodgeball_updated, all_reservation;
	

	//variables
	vector<Person> personData; //Stores First and Last names and the credits
	string userInput, pin, firstName, lastName;
	int credit;
	int counts = 0; //used to get the drivers

	
	//gets the name list of the dogeball team 
	cout << "Dogeball team roster\n--------------------\n";
	inFile_dodgeball = openInputFile();
	system("cls");


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
	
	//used for testing to diaply all names
	//for (auto i : personData) {
	//	i.displayFirstName();
	//	i.displayLastName();
	//	i.displayCredit();
	//	cout << endl;
	//}
	//////////////////////////////////////////


	//opens the output files
	//dodgeball_updated = openOutputFile(); //output file used for the updated credit values
	//all_reservation  = openOutputFile(); //output file for the gui of car reservation

	
	while (true) {
		system("cls"); //clear the cmd

		//menu display
		cout << "Doge Ball Car pool Reservation:\n";
		cout << "-------------------------------\n\n";
		cout << "(1) Create Reservation\n";
		cout << "(2) Modify Reservation\n";
		cout << "(3) Delete Reservation\n";
		cout << "(4) Print  Reservations\n\n";

		//user input for menu
		cout << "option: ";
		cin >> userInput;

		//Create reservation
		if (userInput == "1") {
			cout << "First Name: ";
			cin >> firstName;

			cout << "Last Name: ";
			cin >> lastName;
			

			for (int i = 0; i < personData.size(); i++) {
				if (firstName == personData.at(i).Person::getFirstName() && lastName == personData.at(i).Person::getLastName()) {
					cout << personData.at(i).Person::getCredit();


					cin >> userInput;
					if (userInput == "yes") {
						cout << "Reservation Made";
					}
					else {
						cout << "Reservation Failed";

					}

					system("pause");
					continue;
				}
			}
			

		}

		//Modify Reservation
		else if (userInput == "2") {

		}

		//Delete Reservation
		else if (userInput == "3") {

		}

		//Print Reservation
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


//Input file fuction
ifstream openInputFile() {
	//------------------------------------------------------
	//variable ste up
	//------------------------------------------------------
	ifstream inPutFile; //read file
	string userFile_in; //user defined file name

	cout << "File: ";
	cin >> userFile_in;

	//------------------------------------------------------
	//usedd to open a file in read mode
	//------------------------------------------------------
	userFile_in.append(".txt");			 //puts .txt on the end of the file for you
	inPutFile.open(userFile_in.c_str()); //opens the file
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

	cout << "OUTPUT file: ";
	cin >> userFile_out;

	//------------------------------------------------------
	//used to open a file in write mode
	//------------------------------------------------------
	userFile_out.append(".txt");		   //puts .txt on the end of the file for you
	OutPutFile.open(userFile_out.c_str()); //opens the file
	if (!OutPutFile.is_open()) {		   //error check
		cout << "\nBad File Path... Program Terminated\n";
		exit(1);
	}


	return OutPutFile; //returns the file path to main
}



