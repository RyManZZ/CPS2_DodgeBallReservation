//////////////////////////////////////////////
// DodgeBall Team Reservation Project
// Course: Computational Problem Solving II
// Developers: Ryan Karges & Zachary Fitzgerald
// File: DodgeBall.cpp
// Description: Program serves as a function allowing for players to Create, Modify, and Reserve seating options based on thier credits
//////////////////////////////////////////////

#include "DogeBall.h"


ifstream openInputFile();
ofstream openOutputFile();

//testTESING
//test
//menu function

int main() {

	ifstream dogeball;
	ofstream dogeball_updated, all_reservation;
	
	
	
	
	//gets the name list of the dogeball team 
	cout << "Dogeball team roster\n--------------------\n";
	dogeball = openInputFile();
	
	system("cls");

//put person class function here



	dogeball_updated = openOutputFile(); //output file used for the updated credit values
	all_reservation  = openOutputFile(); //output file for the gui of car reservation

	//variables
	string userInput, pin, firstName, lastName;

	//populate person class from input file
	

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
			
			//
			cout << "First Name: ";
			cin >> firstName;

			cout << "Last Name: ";
			cin >> lastName;
			system("pause");
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



