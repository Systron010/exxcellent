// Programm to solve the exxcellent programming-challenge
// Created by Michael Mahty
// See README.md for more information


// Include Standard libraries
#include <iostream>
#include <string>
// Include own classes
#include "WeatherDataClass.h"

// Use std namespace
using namespace std;

//Verbose Level: 1: show all, 0: show minimum
const int VERBOSE = 1;

// Settings and constants
const string FILENAME_WEATHER = "";
const string FILENAME_FOOTBALL = "";


int main()
{
   cout << "Programm started." << endl;

   // Create weather data class
   WeatherDataClass* weatherData = new WeatherDataClass(FILENAME_WEATHER, VERBOSE);


   cout << "Programm successfully finished." << endl;
   return 0;
}
