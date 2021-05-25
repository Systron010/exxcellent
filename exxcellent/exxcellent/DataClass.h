// Header for the DataClass. 
// This class handles the reading of data sets from a file. The variables and functions are inherit to 'FootballDataClass' and 'WeatherDataClass'

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

// Define DataClass
class DataClass
{

protected:
	string dataName; // Name of the data type. Will be set by the daughter class (WeatherClass: days or FootballClass: teams)
	string fileName; // Name of the file with the data of interest
	string fileType; // File type of the file 'fileName'
	char SEPARATOR; // Value separator-char in the file 'fileName'. It gets set in function 'void ReadFile()' according to detected 'fileType'
	vector<string> columnNames; // All column names in the file 'fileName'
	unsigned int numColumns; // Number of columns in the header of the file 'fileName'. Used to check if column number of all lines is correct
	unsigned int numDataSets; // Number of data sets in the file 'fileName' (i.e. Number of lines without header line)
	
	string GetFileType(string fileName); // Function to get the 'fileType' (.extension) as a string extracted from 'fileName'
	unsigned int GetColumnNames_CSV(string currentLine); // Function to save all column names (read in the header of the CSV file 'fileName') in 'vector<string> columnNames'
	void PrintColumnNames_CSV(); // Function to print all column names from CSV file 'fileName' to console
	bool checkNumOfColumns(string currentLine); // Function to check that the number of columns in the current read line of the file matches the number of columns in the header (numColumns).
	void ReadFile_CSV(fstream& file); // Function to read CSV file 'fileName'
	void ReadFile_JSON(fstream& file); // Function to read JSON file 'fileName'. NOT IMPLEMENTED YET
	void ReadEachLine_CSV(fstream& file); // Function to read each line of CSV file 'fileName'

	
	virtual void ParsingLineAndSaveValues_CSV(string currentLine); // Virutal Function for parsing the current string line in the CSV file and save the values to a data struct. It has to be overwritten by daughter class.
	virtual void PrintAllData(); // Virtual function to print all read values to console. It has to be overwritten by daughter class.

public:
	void ReadFile(); // Function to open and read the file 'fileName'. This function is called independent of the 'fileType'. It calls the corresponding 'ReadFile_XXX()' functions depending on the given 'fileType'.

};

#endif