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
	if (!file) {
		cerr << "# ERROR: No such file found! Program stopped!";
		exit(-1);
	}
	// Read file line by line if it exists
	else {
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
		if (currentNumCol == numColumns) {
			SaveAllValuesPerDay(allValuesCurrentDay);
		}
		else {
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
	while (getline(strStream, currentColname, ',')) {
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
	for (size_t i = 0; i < columnNames.size(); ++i) {
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
	currentDay.MxT		= allValuesCurrentDay.at(1);
	currentDay.MnT		= allValuesCurrentDay.at(2);
	currentDay.AvT		= allValuesCurrentDay.at(3);
	currentDay.AvDP		= allValuesCurrentDay.at(4);
	currentDay.HrPTPcpn = allValuesCurrentDay.at(5);
	currentDay.PDir		= allValuesCurrentDay.at(6);
	currentDay.AvSp		= allValuesCurrentDay.at(7);
	currentDay.Dir		= allValuesCurrentDay.at(8);
	currentDay.MxS		= allValuesCurrentDay.at(9);
	currentDay.SkyC		= allValuesCurrentDay.at(10);
	currentDay.MxR		= allValuesCurrentDay.at(11);
	currentDay.Mn		= allValuesCurrentDay.at(12);
	currentDay.RAvSLP	= allValuesCurrentDay.at(13);

	// Save current day struct to 'vector<dayData> totalDayData'
	totalDayData.push_back(currentDay);
}


void WeatherDataClass::PrintAllValues()
{
	cout << endl;
	cout << "# Print all read values (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
	PrintColumnNames();
	// Loop over all days in 'vector<dayData> totalDayData'
	for (size_t i = 0; i < totalDayData.size(); ++i) {
		dayData currentDay = totalDayData.at(i);
		cout << currentDay.day		<< "," 
			 << currentDay.MxT		<< ","
			 << currentDay.MnT		<< ","
			 << currentDay.AvT		<< ","
			 << currentDay.AvDP		<< ","
			 << currentDay.HrPTPcpn << "," 
			 << currentDay.PDir		<< ","
			 << currentDay.AvSp		<< ","
			 << currentDay.Dir		<< ","
			 << currentDay.MxS		<< ","
			 << currentDay.SkyC		<< ","
			 << currentDay.MxR		<< "," 
			 << currentDay.Mn		<< ","
			 << currentDay.RAvSLP;
		cout << endl;
	}
	cout << "# End of data set." << endl;
}


void WeatherDataClass::FindDayWithSmallestTempSpread()
{
	cout << endl;
	cout << "# Find the day with the smallest temperature spread:" << endl;
	// Search min temprature spread using std::min_element and the <operator defined in 'struct dayData' 
	minTempSpreadDay = min_element(totalDayData.begin(), totalDayData.end());
	cout << "  The day with the smallest temperature spread is day " << minTempSpreadDay -> day << endl;
	cout << "  The tempereature spread is: " << minTempSpreadDay -> MxT - minTempSpreadDay -> MnT << " ab.units" << endl;
}