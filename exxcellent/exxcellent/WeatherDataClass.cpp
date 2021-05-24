#include "WeatherDataClass.h"


WeatherDataClass::WeatherDataClass(string in_fileName)
{
	fileName = in_fileName;
	dataName = "day(s)";
}


void WeatherDataClass::SaveAllValuesPerLine(vector<float> allValuesCurrentDay)
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
	cout << "# Print all read values from '" << fileName << "' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
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