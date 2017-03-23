#include <iostream>
#include <fstream>  // Using for files
#include <string>   // Using for strings
#include <iomanip>  // Using to manipulate format

using namespace std;

/// Declare a class for Batter names
class Player
{
	// Class Members 
	string m_FName; // First Name
	string m_LName; // Last Name
	string m_Pos;   // Batters position
	float  m_Bavg;  // Batters Average

public:
	/// Initializes default Player stats
	Player()
	{
		m_FName = "Joe";
		m_LName = "DiMaggio";
		m_Pos = "OF";
		m_Bavg = 0.325F;
	}

	/// Reads one line of Player information from input file
	void ReadFile(istream &inputFileName)
	{
		// Read data from input file 
		inputFileName >> m_FName >> m_LName >> m_Pos >> m_Bavg;
	}

	/// Writes Player information to output file
	void WriteString(ostream &outputFileName)
	{
		// Format and print information in the class one line at a time
		outputFileName << m_LName << ", " << m_FName << ": " << m_Pos + " (" << setprecision(3) << m_Bavg << ")" << endl;
	}
	
};

