// Header for the data class. This class handles the reading of different data types. The methodes are inherit to FootballDataClass and WeatherDataClass

#ifndef DataClass_HEADER
#define DataClass_HEADER

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
	string fileType; // File type of the file 'fileName'
	char SEPARATOR; // value separator in the file. Gets set in function 'void ReadFile()' according to fileType.
	vector<string> columnNames; // All column names in the file 'fileName'
	unsigned int numColumns; // Number of columns in the header. Used to check if file format of all lines is correct
	unsigned int numDataSets; // Number of data sets in the file 'fileName' (number of lines without header line)
	
	string GetFileType(string fileName); // Function to get the filetype (extension) as a string of the file 'fileName'
	unsigned int GetColumnNames_CSV(string currentLine); // Function to save all column names in 'vector<string> columnNames' from the csv file 'fileName' in the first line and return number of columns
	void PrintColumnNames(); // Function to print all column names
	void ReadFile_CSV(fstream& file); // Function to read the csv file 'fileName'
	void ReadEachLine_CSV(fstream& file); // Function to read each line of the csv file 'fileName'
	bool checkNumOfColumns(string currentLine); // Function to check that the number of columns in the currentLine matches the number of columns in the header (numColumns).
	
	virtual void ParsingLineAndSaveValues_CSV(string currentLine); // Virutal Function for parsing the current string line in the csv file and save the values to a data struct. Has to be overwritten by daughter class.
	virtual void PrintAllValues(); // Virtual function to print all read values to console. Has to be overwritten by daughter class.

public:
	void ReadFile(); // Function to open and read a file 'fileName'
};

#endif