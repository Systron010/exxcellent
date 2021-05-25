#include "WeatherDataClass.h"


WeatherDataClass::WeatherDataClass(string in_fileName)
{
	fileName = in_fileName;
	dataName = "day(s)";
}


void WeatherDataClass::ParsingLineAndSaveValues_CSV(string currentLine)
{
	// Convert currentLine string into istringstream
	string comma_string;
	std::istringstream textStream(currentLine);

	// Create current dayData struct for this currentLine
	dayData currentDay;

	// Parsing the line to currentDay. All values are 'int'
	textStream >> currentDay.day;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.mxT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.mnT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.avT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.avDP;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.hrPTPcpn;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.pDir;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.avSp;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.dir;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.mxS;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.skyC;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.mxR;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.mn;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.rAvSLP;

	// Save currentDay to 'vector<dayData> totalDayData'
	totalDayData.push_back(currentDay);
}


void WeatherDataClass::PrintAllData()
{
	cout << endl;
	cout << "# Print all read values from '" << fileName << "' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
	PrintColumnNames_CSV();
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
		// Search min temperature spread in 'totalDayData' using 'std::min_element()' and the <operator defined in 'struct dayData' 
		minTempSpreadDay = min_element(totalDayData.begin(), totalDayData.end());
		cout << "  The day with the smallest temperature spread is day " << minTempSpreadDay -> day << endl;
		cout << "  The tempereature spread is: " << minTempSpreadDay -> mxT - minTempSpreadDay -> mnT << " ab.units" << endl;
	}
	else 
	{
		cout << "# WARNING: No weather data loaded. So no smallest temperature spread can be found." << endl;
	}
}