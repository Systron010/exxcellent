// Header for the weather data class. This class handles the weather data.
// The class inherits variables and methods from 'DataClass'
// The data for each day are stored in a 'struct dayData' datatype. All days are stored in a vector of 'struct dayData' datatype.
// The private function 'void FindDayWithSmallestTempSpread()' searches the day with the smallest temperatur spread (This is the solution of the weather challenge).


// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm> // for 'std::min_element()'

// Include own written data class
#include "DataClass.h"

// Use std namespace
using namespace std;

// Define weather data class. Inherits from 'DataClass'
class WeatherDataClass : public DataClass
{

private:
	struct dayData { // Store different values for one day
		unsigned short int day;
		float mxT;
		float mnT;
		float avT;
		float avDP;
		float hrPTPcpn;
		float pDir;
		float avSp;
		float dir;
		float mxS;
		float skyC;
		float mxR;
		float mn;
		float rAvSLP;
		bool operator<(const dayData& other) // <Operator to search minimum in temperatur spread (mxt-mnT) using 'std::min_element()'
		{
			float value1 = mxT - mnT;
			float value2 = other.mxT - other.mnT;
			return value1 < value2;
		}
	};
	vector<dayData> totalDayData; // The data of all days, which means all days found in the file 'fileName'
	vector<dayData>::iterator minTempSpreadDay; // Data of the day with the smallest temperatur spread (This is the solution of the weather challenge)

	void ParsingLineAndSaveValues_CSV(string currentLine); // Function for parsing the current string line read from the csv file. It saves the values of one day to "struct dayData". Override the function from DataClass.
	
public:
	WeatherDataClass(string in_fileName); // Class Constructor
	void PrintAllData(); // Function to print all read values to console. Override the function from DataClass.
	void FindDayWithSmallestTempSpread(); // Function to find the day with the smallest temperatur spread (This is the goal of the weather challenge)

};

