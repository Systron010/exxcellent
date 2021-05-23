// Include Standard libraries
#include <iostream>
#include <string>
#include <vector>
// Use std namespace
using namespace std;

class WeatherDataClass
{

private:
	string fileName; // Name of file with the weather data
	unsigned int verbose; // Verbose level
	vector<string> columnNames; // All column names in the file 'fileName'
	struct day { // Different values for one day
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
	};
	vector<day> totalData; // All data which means all days in the file 'fileName'
	int numDays; // Number of all days (data.size())
	void GetColumnNames(string currentLine); // Function to get the column names in the file 'fileName'
	void PrintColumnNames(); // Function to print all column names
	void SaveAllValuesPerDay(vector<float> allValuesPerDay); // Function to save all values of one day to 'vector<day> totalData'
	
public:
	WeatherDataClass(string in_fileName, unsigned int  in_verbose); // Class Constructor
	void ReadFile(); // Function to read the file 'fileName'
	void PrintAllValues(); // Function to print all read values to console
	void FindDaySmallestTempSpread(); // Function to find the day with the smallest temperatur spread

};

