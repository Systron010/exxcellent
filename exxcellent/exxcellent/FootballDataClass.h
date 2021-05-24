// Header for the football data class. This class handles the football data read from football.csv


// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include <stdlib.h> 

// Use std namespace
using namespace std;

// Define football class
class FootballDataClass
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
		int Points; // Maybe negativ value possible due to penalty
		bool operator<(const teamData& other) // <Operator to search for minimum in goal distance (Mxt-MnT)
		{
			unsigned int value1 = abs(goals - goalsAllowed);
			unsigned int value2 = abs(other.goals - other.goalsAllowed);
			return value1 < value2;
		}
	};


public:
	FootballDataClass(string in_fileName); // Class Constructor

};

