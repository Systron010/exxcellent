# exxcellent
exxcellent programming-challenge done by Michael Mathy

Start: 23.5.2021

Language: C++ 14

IDE: Visual Studio 2019


Branches: 

main: Includes solution for weather challenge. 

football: includes solution for weather and football challenge at the same time using a main DataClass to inherit from.


The "main" function in "exxellent.cpp" creates two Objects: A "WeatherDataClass" and a "FootballDataClass". Both classes handle the two below given tasks. Both classes inherit variables and funtions from a base class called "DataClass". This class contains all functions which are needed to read the data from csv-files, save them and print them to the console if wanted.





Tasks:


Weather

In weather.csv you’ll find the daily weather data of a single month. Read the file, then output the day number (column one Day) of the day with the smallest temperature spread (difference between maximum & minimum temperature of the day.) The maximum temperature is the second column MxT, the minimum temperature the third column MnT.


Football

The football.csv file contains results of the English Premier League. The columns labeled ‘Goals’ and ‘Goals Allowed’ contain the total number of goals scored by and against each team (so Arsenal scored 79 goals themselves and had 36 goals scored against them). Read the file, then print the name of the team with the smallest distance (absolute difference) between ‘Goals’ and ‘Goals Allowed’.


Task

Try to write a single program, which is able to solve the "Weather" challenge.
Then try to refactor & extend your solution, that it additionally supports the Football challenge.

Process

Favour the software design goals described under Goal over other goals like performance or feature set.
Try to follow a test-driven development approach.


