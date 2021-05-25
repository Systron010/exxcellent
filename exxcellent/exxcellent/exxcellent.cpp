// Program to solve the exxcellent programming-challenge
// Created by Michael Mathy
// Date: 25.5.21
// See README.md for more information


// Include standard libraries
#include <iostream>
#include <string>

// Include own written classes
#include "WeatherDataClass.h"
#include "FootballDataClass.h"

// Use std namespace
using namespace std;

// Settings and constants
const string FILENAME_WEATHER = "./../../data/weather.csv";
const string FILENAME_FOOTBALL = "./../../data/football.csv";
// Verbose Level: 1: show all, 0: show minimum
const unsigned int VERBOSE = 1;

// Main funton (return=0 -> successfull, return=-1 -> error)
int main()
{

   cout << "# Program started." << endl;

   // Create weather data class
   WeatherDataClass* weatherData = new WeatherDataClass(FILENAME_WEATHER);
   // Read input file
   weatherData -> ReadFile();
   // Print all read data if VERBOSE==1
   if (VERBOSE == 1)
	   weatherData -> PrintAllData();
   // Search day with the smallest temperature spread (Solution of the weather challenge)
   weatherData -> FindDayWithSmallestTempSpread();

   // Create football data class
   FootballDataClass* footballData = new FootballDataClass(FILENAME_FOOTBALL);
   // Read input file
   footballData -> ReadFile();
   // Print all read data if VERBOSE==1
   if (VERBOSE == 1)
	   footballData -> PrintAllData();
   // Search team with the smallest goal distance (Solution of the fotball challenge)
   footballData -> FindTeamWithSmallestDistance();

   cout << endl;
   cout << "# Program successfully finished." << endl;
   return 0;

}
