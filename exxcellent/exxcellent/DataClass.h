// Header for the data class. This class handles the reading of different data types. The methodes are inherit to FootballDataClass and WeatherDataClass

// Include standard libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 

// Use std namespace
using namespace std;

// Define data class
class DataClass
{
protected:
	string dataName; // Name of the data type. Will be set by the daughter class (Weather:days or Football:teams)
	string fileName; // Name of file with the data
	vector<string> columnNames; // All column names in the file 'fileName'
	unsigned int numColumns; // Number of columns in the header. Used to check if file format of all lines is correct
	unsigned int numDataSets; // Number of data sets in the file 'fileName' (number of lines without header line)
	
	unsigned int GetColumnNames(string currentLine); // Function to get all column names in the file 'fileName' in the first line and return number of columns
	void PrintColumnNames(); // Function to print all column names
	void ReadEachLine(fstream& file, string currentLine); // Function to read each line of the file 'fileName'
	
	virtual void SaveAllValuesPerDay(vector<float> allValuesCurrentLine) = 0; // Virtual Function to save all read values of one line. Will be overwritten by daughter class

public:
	void ReadFile(); // Function to read the file 'fileName'
};

