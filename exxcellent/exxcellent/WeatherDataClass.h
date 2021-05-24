// Header for the weather data class. This class handles the weather data.
// The class inherits from DataClass
// The data for each day are stored in a 'struct dayData' datatype
// The private function 'void FindDayWithSmallestTempSpread()' searches the day with the smallest temperatur spread (This is the solution of the weather challenge).


// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>

// Include own written data class
#include "DataClass.h"

// Use std namespace
using namespace std;

// Define weather data class
class WeatherDataClass : public DataClass
{

private:
	struct dayData { // Different values for one day
		unsigned short int day;
		float MxT;
		float MnT;
		float AvT;
		float AvDP;
		float HrPTPcpn;
		float PDir;
		float AvSp;
		float Dir;
		float MxS;
		float SkyC;
		float MxR;
		float Mn;
		float RAvSLP;
		bool operator<(const dayData& other) // <Operator to search for minimum in temperatur spread (Mxt-MnT)
		{
			return MxT - MnT < other.MxT - other.MnT;
		}
	};
	vector<dayData> totalDayData; // The data of all days, which means all days in the file 'fileName'
	vector<dayData>::iterator minTempSpreadDay; // Vector with the data for the day with the smallest temperatur spread (This is the solution of the weather challenge)
	void SaveAllValuesPerLine(vector<float> allValuesCurrentLine); // Function to save all read values of one line (one day) to 'vector<dayData> totalDayData'
	
public:
	WeatherDataClass(string in_fileName); // Class Constructor
	void PrintAllValues(); // Function to print all read values to console
	void FindDayWithSmallestTempSpread(); // Function to find the day with the smallest temperatur spread (This is the goal of the weather challenge)

};

