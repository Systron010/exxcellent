// Header for the weatherDataClass. This class handles the weather data read from weather.csv
// The data for each day are stored in a 'struct dayData' datatype
// The private function 'void FindDayWithSmallestTempSpread()' searches the day with the smallest temperature spread (This is the solution of the weather challenge).


// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <algorithm>

// Use std namespace
using namespace std;

// Define weather data class
class WeatherDataClass
{

private:
	string fileName; // Name of file with the weather data
	vector<string> columnNames; // All column names in the file 'fileName'
	unsigned int numColumns; // Number of columns in the header. Used to check if file format of all lines is correct
	struct dayData { // Different values for one day
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
		bool operator<(const dayData& other) // <Operator to search for minimum in temperatur spread (Mxt-MnT) using 'std::min_element()'
		{
			float value1 = mxT - mnT;
			float value2 = other.mxT - other.mnT;
			return value1 < value2;
		}
	};
	vector<dayData> totalDayData; // The data of all days, which means all days in the file 'fileName'
	int numDays; // Number of all days (totalDayData.size())
	vector<dayData>::iterator minTempSpreadDay; // Vector with the data for the day with the smallest temperatur spread (This is the solution of the weather challenge)

	void ReadEachLine(fstream& file, string currentLine); // Function to read each line of the file 'fileName'
	unsigned int GetColumnNames(string currentLine); // Function to get all column names in the file 'fileName' in the first line and return number of columns
	void PrintColumnNames(); // Function to print all column names
	void SaveAllValuesPerDay(vector<float> allValuesPerDay); // Function to save all read values of one day to 'vector<dayData> totalDayData'
	
public:
	WeatherDataClass(string in_fileName); // Class Constructor
	void ReadFile(); // Function to read the file 'fileName'
	void PrintAllValues(); // Function to print all read values to console
	void FindDayWithSmallestTempSpread(); // Function to find the day with the smallest temperature spread (This is the goal of the weather challenge)

};

