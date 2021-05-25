// Header for the football data class. This class handles the football data.
// The class inherits variables and methods from 'DataClass'
// The data for each team are stored in a 'struct teamData' datatype. All teams are stored in a vector of 'struct teamData' datatype.
// The private function 'void FindTeamWithSmallestDistance()' searches the team with the smallest goal distance (This is the solution of the football challenge).

// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm> // for 'std::min_element()'
#include <stdlib.h> // for 'abs()'

// Include own written data class
#include "DataClass.h"

// Use std namespace
using namespace std;

// Define football class. Inherits from 'DataClass'
class FootballDataClass : public DataClass
{

private:
	struct teamData { // Different values for one team
		string team; 
		unsigned int games; 
		unsigned int wins;
		unsigned int losses;
		unsigned int draws;
		int goals; // Maybe negativ value possible due to penalty
		int goalsAllowed; // Maybe negativ value possible due to penalty
		int points; // Maybe negativ value possible due to penalty
		bool operator<(const teamData& other) // <Operator to search for minimum in goal distance abs(goals-goalsAllowed) using 'std::min_element()'
		{
			unsigned int value1 = abs(goals - goalsAllowed);
			unsigned int value2 = abs(other.goals - other.goalsAllowed);
			return value1 < value2;
		}
	};
	vector<teamData> totalTeamData; // The data of all teams, which means all teams read in the file 'fileName'
	vector<teamData>::iterator minDistanceTeam; // The data for the team with the smallest goal distance (This is the solution of the football challenge)

	void ParsingLineAndSaveValues_CSV(string currentLine); // Function for parsing the current string line read from the csv file. It saves the values for one team to "struct teamData". Override the function from DataClass.

public:
	FootballDataClass(string in_fileName); // Class Constructor
	void PrintAllData(); // Function to print all read values to console. Override the function from DataClass.
	void FindTeamWithSmallestDistance(); // Function to find the team with the smallest goal distance (absolute difference between ‘Goals’ and ‘Goals Allowed’. This is the goal of the football challenge)

};

