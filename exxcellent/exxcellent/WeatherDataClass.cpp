#include "WeatherDataClass.h"
#include <fstream>
#include <sstream> 

// Weather data construtor
WeatherDataClass::WeatherDataClass(string in_fileName, unsigned int in_verbose)
{
	fileName = in_fileName;
	verbose = in_verbose;
}


// Read weather data from file
void WeatherDataClass::ReadFile()
{
	cout << "# Read data from file: '" << fileName <<  "'" << endl;
	
	// Open file
	fstream file;
	file.open(fileName, ios::in);

	// Check if file exists
	if (!file) {
		cerr << "# Error: No such file found! Program stopped!";
		exit(-1);
	}
	// Read file line by line if it exists
	else {
	
		// Read and print first line: column names
		string currentLine;
		getline(file, currentLine);
		GetColumnNames(currentLine);
		PrintColumnNames();

		// Loop over all lines
		while (getline(file, currentLine))
		{
			// Create a stringstream from current line
			stringstream strStream(currentLine);
			// Extract each value of current line
			float currentValue;
			vector<float> allValuesPerDay;
			while (strStream >> currentValue) {

				// Save current value
				allValuesPerDay.push_back(currentValue);
				// If the next token is a comma, ignore it and move on
				if (strStream.peek() == ',') 
					strStream.ignore();
			}

			// Save all values for current day to the total 'data'
			SaveAllValuesPerDay(allValuesPerDay);
		}

		// Save number of days (number of data sets)
		numDays = totalData.size();
		cout << "# " << numDays << " days were read." << endl;

	}

	file.close();
}

void WeatherDataClass::GetColumnNames(string currentLine)
{
	// Create a stringstream from current line
	stringstream strStream(currentLine);
	string colname;

	// Extract each column name
	while (getline(strStream, colname, ',')) {
		// Add columnNames
		columnNames.push_back(colname);
	}
}

void WeatherDataClass::PrintColumnNames()
{
	cout << "# Used column names:" << endl;
	for (size_t i = 0; i < columnNames.size(); ++i) {
		if (i < columnNames.size() - 1)
			cout << columnNames.at(i) << ", ";
		else
			cout << columnNames.at(i);
	}
	cout << endl;
}

void WeatherDataClass::SaveAllValuesPerDay(vector<float> allValuesPerDay)
{
	// Create current day struct
	day currentDay;
	currentDay.day		= static_cast<unsigned short int>(allValuesPerDay.at(0));
	currentDay.MxT		= allValuesPerDay.at(1);
	currentDay.MnT		= allValuesPerDay.at(2);
	currentDay.AvT		= allValuesPerDay.at(3);
	currentDay.AvDP		= allValuesPerDay.at(4);
	currentDay.HrPTPcpn = allValuesPerDay.at(5);
	currentDay.PDir		= allValuesPerDay.at(6);
	currentDay.AvSp		= allValuesPerDay.at(7);
	currentDay.Dir		= allValuesPerDay.at(8);
	currentDay.MxS		= allValuesPerDay.at(9);
	currentDay.SkyC		= allValuesPerDay.at(10);
	currentDay.MxR		= allValuesPerDay.at(11);
	currentDay.Mn		= allValuesPerDay.at(12);
	currentDay.RAvSLP	= allValuesPerDay.at(13);

	// Save current Day
	totalData.push_back(currentDay);
}

void WeatherDataClass::PrintAllValues()
{
	cout << endl;
	cout << "# Print all read values (Can be turned off with VERBOSE=0):" << endl;
	PrintColumnNames();
	for (size_t i = 0; i < totalData.size(); ++i) {
		day currentDay = totalData.at(i);
		cout << currentDay.day << "," << currentDay.MxT << "," << currentDay.MnT << "," << currentDay.AvT << "," << currentDay.AvDP << "," << currentDay.HrPTPcpn << "," 
			 << currentDay.PDir << "," << currentDay.AvSp << "," << currentDay.Dir << "," << currentDay.MxS << "," << currentDay.SkyC << "," << currentDay.MxR << "," 
			 << currentDay.Mn << "," << currentDay.RAvSLP;
		cout << endl;
	}
	cout << "# End of data set." << endl;

}

void WeatherDataClass::FindDaySmallestTempSpread()
{
	cout << "# Find day with the smallest tempretur spread." << endl;

}



