// Programm to solve the exxcellent programming-challenge
// Created by Michael Mahty
// See README.md for more information


// Include Standard libraries
#include <iostream>
#include <string>

// Include own written classes
#include "WeatherDataClass.h"

// Use std namespace
using namespace std;

// Settings and constants
const string FILENAME_WEATHER = "./../../data/weather.csv";
const string FILENAME_FOOTBALL = "./../../data/football.csv";
//Verbose Level: 1: show all, 0: show minimum
const unsigned int VERBOSE = 1;

// Main funton
int main()
{
   cout << "# Programm started." << endl;


   // Create weather data class
   WeatherDataClass* weatherData = new WeatherDataClass(FILENAME_WEATHER, VERBOSE);
   // Read input file
   weatherData->ReadFile();
   // Print all values if wanted
   if (VERBOSE == 1)
	   weatherData->PrintAllValues();
   // Search day with smallest temp spread
   weatherData->FindDaySmallestTempSpread();


   cout << "# Programm successfully finished." << endl;
   return 0;
}
