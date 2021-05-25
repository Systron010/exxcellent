#include "WeatherDataClass.h"


WeatherDataClass::WeatherDataClass(string in_fileName)
{
	fileName = in_fileName;
}


void WeatherDataClass::ReadFile()
{
	cout << endl;
	cout << "# Read data from file: '" << fileName <<  "'" << endl;
	
	// Open file with 'fileName'
	fstream file;
	file.open(fileName, ios::in);

	// Check if file exists
	if (!file) 
	{
		cerr << endl;
		cerr << "# ERROR: No such file found! Program stopped!";
		exit(-1);
	}
	// Read file line by line if it exists
	else 
	{
		// Read first line: the column names
		string currentLine;
		getline(file, currentLine);
		numColumns = GetColumnNames(currentLine);
		// Print all column names to console
		PrintColumnNames();
		// Read every line of the file and fill the read data to 'vector<dayData> totalDayData'
		ReadEachLine(file, currentLine);
		// Save number of days (number of data sets)
		numDays = totalDayData.size();
		cout << "# " << numDays << " days were read." << endl;
	}

	file.close();
}

void WeatherDataClass::ReadEachLine(fstream& file, string currentLine)
{

	// Loop over all lines in the file
	while (getline(file, currentLine))
	{
		// Create a stringstream from current line
		stringstream strStream(currentLine);
		// Extract each value of current line
		float currentValue;
		vector<float> allValuesCurrentDay;
		unsigned int currentNumCol = 0;
		while (strStream >> currentValue) {
			// Save current value to allValuesCurrentDay vector
			allValuesCurrentDay.push_back(currentValue);
			currentNumCol++;
			// If the next token is a comma, ignore it and move on
			if (strStream.peek() == ',')
				strStream.ignore();
		}

		// Save all values for the current day to 'vector<dayData> totalDayData' if number of columns was correct
		if (currentNumCol == numColumns) 
		{
			SaveAllValuesPerDay(allValuesCurrentDay);
		}
		else 
		{
			cerr << endl;
			cerr << "# ERROR: Number of columns for day " << totalDayData.size() + 1 << " does NOT match number of columns in the Headerline! Program stopped!" << endl;
			exit(-1);
		}

	}

}


unsigned int WeatherDataClass::GetColumnNames(string currentLine)
{
	// Create a stringstream from current line
	stringstream strStream(currentLine);
	string currentColname;

	// Extract each column name
	while (getline(strStream, currentColname, ',')) 
	{
		// Add current column name to columnNames vector
		columnNames.push_back(currentColname);
	}

	// Return number of columns
	return columnNames.size();
}


void WeatherDataClass::PrintColumnNames()
{
	cout << "# Used column names:" << endl;
	// Loop over all coulumn names and print to console
	for (size_t i = 0; i < columnNames.size(); ++i) 
	{
		if (i < columnNames.size() - 1)
			cout << columnNames.at(i) << ", ";
		else
			cout << columnNames.at(i);
	}
	cout << endl;
}


void WeatherDataClass::SaveAllValuesPerDay(vector<float> allValuesCurrentDay)
{
	// Create current day struct
	dayData currentDay;
	currentDay.day		= static_cast<unsigned short int>(allValuesCurrentDay.at(0));
	currentDay.mxT		= allValuesCurrentDay.at(1);
	currentDay.mnT		= allValuesCurrentDay.at(2);
	currentDay.avT		= allValuesCurrentDay.at(3);
	currentDay.avDP		= allValuesCurrentDay.at(4);
	currentDay.hrPTPcpn = allValuesCurrentDay.at(5);
	currentDay.pDir		= allValuesCurrentDay.at(6);
	currentDay.avSp		= allValuesCurrentDay.at(7);
	currentDay.dir		= allValuesCurrentDay.at(8);
	currentDay.mxS		= allValuesCurrentDay.at(9);
	currentDay.skyC		= allValuesCurrentDay.at(10);
	currentDay.mxR		= allValuesCurrentDay.at(11);
	currentDay.mn		= allValuesCurrentDay.at(12);
	currentDay.rAvSLP	= allValuesCurrentDay.at(13);

	// Save current day struct to 'vector<dayData> totalDayData'
	totalDayData.push_back(currentDay);
}


void WeatherDataClass::PrintAllValues()
{
	cout << endl;
	cout << "# Print all read values (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
	PrintColumnNames();
	// Loop over all days in 'vector<dayData> totalDayData'
	for (size_t i = 0; i < totalDayData.size(); ++i) 
	{
		dayData currentDay = totalDayData.at(i);
		cout << currentDay.day		<< ", " 
			 << currentDay.mxT		<< ", "
			 << currentDay.mnT		<< ", "
			 << currentDay.avT		<< ", "
			 << currentDay.avDP		<< ", "
			 << currentDay.hrPTPcpn << ", " 
			 << currentDay.pDir		<< ", "
			 << currentDay.avSp		<< ", "
			 << currentDay.dir		<< ", "
			 << currentDay.mxS		<< ", "
			 << currentDay.skyC		<< ", "
			 << currentDay.mxR		<< ", " 
			 << currentDay.mn		<< ", "
			 << currentDay.rAvSLP;
		cout << endl;
	}
	cout << "# End of data set." << endl;
}


void WeatherDataClass::FindDayWithSmallestTempSpread()
{

	cout << endl;
	cout << "# Find the day with the smallest temperature spread:" << endl;

	if (totalDayData.size() > 0)
	{
		// Search min temprature spread in 'totalDayData' using 'std::min_element()' and the <operator defined in 'struct dayData' 
		minTempSpreadDay = min_element(totalDayData.begin(), totalDayData.end());
		cout << "  The day with the smallest temperature spread is day " << minTempSpreadDay -> day << endl;
		cout << "  The temperature spread is: " << minTempSpreadDay -> mxT - minTempSpreadDay -> mnT << " ab.units" << endl;
	}
	else 
	{
		cout << "# WARNING: No weather data loaded. So no smallest temperature spread can be found." << endl;
	}

}