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

	// Create current dayData struct
	dayData currentDay;

	// parsing the line to the dayData struct. All values are int
	textStream >> currentDay.day;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.MxT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.MnT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.AvT;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.AvDP;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.HrPTPcpn;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.PDir;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.AvSp;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.Dir;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.MxS;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.SkyC;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.MxR;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.Mn;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentDay.RAvSLP;

	// Save currentDay struct to 'vector<dayData> totalDayData'
	totalDayData.push_back(currentDay);
}


void WeatherDataClass::PrintAllValues()
{
	cout << endl;
	cout << "# Print all read values from '" << fileName << "' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
	PrintColumnNames();
	// Loop over all days in 'vector<dayData> totalDayData'
	for (size_t i = 0; i < totalDayData.size(); ++i) {
		dayData currentDay = totalDayData.at(i);
		cout << currentDay.day		<< ", "
			 << currentDay.MxT		<< ", "
			 << currentDay.MnT		<< ", "
			 << currentDay.AvT		<< ", "
			 << currentDay.AvDP		<< ", "
			 << currentDay.HrPTPcpn << ", "
			 << currentDay.PDir		<< ", "
			 << currentDay.AvSp		<< ", "
			 << currentDay.Dir		<< ", "
			 << currentDay.MxS		<< ", "
			 << currentDay.SkyC		<< ", "
			 << currentDay.MxR		<< ", "
			 << currentDay.Mn		<< ", "
			 << currentDay.RAvSLP;
		cout << endl;
	}
	cout << "# End of data set." << endl;
}


void WeatherDataClass::FindDayWithSmallestTempSpread()
{
	cout << endl;
	cout << "# Find the day with the smallest temperature spread:" << endl;

	if (totalDayData.size() > 0) {
		// Search min temprature spread using std::min_element and the <operator defined in 'struct dayData' 
		minTempSpreadDay = min_element(totalDayData.begin(), totalDayData.end());
		cout << "  The day with the smallest temperature spread is day " << minTempSpreadDay->day << endl;
		cout << "  The tempereature spread is: " << minTempSpreadDay->MxT - minTempSpreadDay->MnT << " ab.units" << endl;
	}
	else {
		cout << "# WARNING: No weather data loaded. So no smallest temperature spread can be found." << endl;
	}

}