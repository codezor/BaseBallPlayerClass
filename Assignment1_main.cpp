// Program 1 
//
// Programmer: Codezor
// Date:       January 23, 2017
// Course:     CS 221
// Section:    2
// Compiler:   Microsoft Visual Studio Community 2015 
// Version:    14.0.25431.01 Update 3
//
// Purpose:
// Read file with baseball players name, class, and batting average 
// Write to output file a formatted 
// Inside the file keep track of the number of players 
// With more that 50 players do not over write the payers in the data file 
// Summary of Program
// 1. Prompt the user for input and output file names (Do not hard code the file name in program)
// 2. Open input file
// 3. Read each player and store them in an array of Player objects
// 4. Keep tack of the number of player in the array
// 5. Open an output file
// 6. Write each player from the array into the output file, along with any other output required by the assignment 
// 7. Remember to close your files when done with them 
//--------------------------------------------------
#include <iostream>
#include <fstream>  // Using for files
#include <string>   // used for strings
#include <iomanip>  // Used to manipulate format
#include "Player.h" // Used to include header file for players

using namespace std;

// --------------------------
// Main Program
//---------------------------
int main()
{
	// Declare things
	Player playerList[50];

	ifstream myInputFile;      // Provided file input
	ofstream myOutputFile;     // Output File writing player data here
	char   inFileName[100];    // Input File Name provided by user
	char   outFileName[100];   // Output File Name Provided by user

	// Prompt  user for inputfile name
	cout << "What is the name of the Input file?";
	cin >> inFileName;  //store file name
	myInputFile.open(inFileName); //open inputfile
	
	
	// read each line in the input file until the end of the file is reached
	int i = 0; // Declare counter for while loop to keep track of players in the file/array
	while (!myInputFile.eof())
	{
		playerList[i].ReadFile(myInputFile);
		i = i + 1;
		if (myInputFile.eof() || i == 50)
		{
			break; // break at the end of file or if the array size reaches 50
		}
	}

	// Close Inputfile
	myInputFile.close();

	// Prompt user for outputfile name
	cout << "What is the Name of the Output file?";
	cin >> outFileName;

	// open the output file
	myOutputFile.open(outFileName);

	// Write data to output file 
	int numPlayers = i;
	myOutputFile << "There were " << numPlayers << " players in the input data file:" << "\n" << endl;
	
	// write each players information in the file
	for (int out = 0; out < i; out++)
	{
		playerList[out].WriteString(myOutputFile);
	}

	// Close OutPut file
	myOutputFile.close();
		
	//getchar();
	return 0;
}
