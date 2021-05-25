## exxcellent Challenge

# --- Exxcellent Programming-Challenge ---


Implemented by Michael Mathy

Start: 23.5.2021

End: 25.5.2021

Language: C++ 14

IDE: Visual Studio 2019

Data: The data given by "weather.csv" and "football.csv" are saved the folder "data".

# --- Branches ---

"main": First created branch. Includes the "WeatherDataClass" which is the solution for weather challenge.

"football": Second created branch. Includes a modified  "WeatherDataClass" and a new "FootballDataClass" which are the solutions for weather and football challenge at the same time using a main "DataClass" to inherit from.


# --- Code Explanation for "Football Branch" ---

The c++ source and header files are saved in ".\exxcellent\exxcellent\*".  The files are:

- exxellent.cpp (includes the main function)

- DataClass.h (Handles data reading from files)

- DataClass.cpp

- WeatherDataClass.h (Handles weather data for the weather challenge. Inherits from DataClass)

- WeatherDataClass.cpp

- FootballDataClass.h (Handles football data for the football challenge. Inherits from DataClass)

- FootballDataClass.cpp

The "main()" function in "exxellent.cpp" defines the program. The function creates two Objects: A "WeatherDataClass" and a "FootballDataClass". Both classes handle the two below given tasks by searching through the given data. Both classes inherit basic variables and functions from a base class called "DataClass". This "DataClass" contains all functions which are needed to read the data from csv-files, save them in a vector, prepare the data and print them to the console if wanted.

A short definition of each variable and function is given in the corresponding header file as a comment next to its deceleration.


# --- Naming Scheme ---

- All variable names begin with a small letter (e.g. int numColumns).

- All function and class names begin with a capital letter (e.g. string GetFileType()).

- All constant names are written completely in capital letters (e.g. const int VERBOSE).


# --- Output of the "Football Branch" ----

If the program in the "Football Branch" is executed to total output in the console is given by:

```
# Program started.

# Read data from file: './../../data/weather.csv'
# Filetpye: csv
# Used SEPERATOR: ,
# Used column names:
Day, MxT, MnT, AvT, AvDP, 1HrPTPcpn, PDir, AvSp, Dir, MxS, SkyC, MxR, Mn, RAvSLP
# 30 day(s) were read.

# Print all read values from './../../data/weather.csv' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):
# Used column names:
Day, MxT, MnT, AvT, AvDP, 1HrPTPcpn, PDir, AvSp, Dir, MxS, SkyC, MxR, Mn, RAvSLP
1, 88, 59, 74, 53.8, 0, 280, 9.6, 270, 17, 1.6, 93, 23, 1004.5
2, 79, 63, 71, 46.5, 0, 330, 8.7, 340, 23, 3.3, 70, 28, 1004.5
3, 77, 55, 66, 39.6, 0, 350, 5, 350, 9, 2.8, 59, 24, 1016.8
4, 77, 59, 68, 51.1, 0, 110, 9.1, 130, 12, 8.6, 62, 40, 1021.1
5, 90, 66, 78, 68.3, 0, 220, 8.3, 260, 12, 6.9, 84, 55, 1014.4
6, 81, 61, 71, 63.7, 0, 30, 6.2, 30, 13, 9.7, 93, 60, 1012.7
7, 73, 57, 65, 53, 0, 50, 9.5, 50, 17, 5.3, 90, 48, 1021.8
8, 75, 54, 65, 50, 0, 160, 4.2, 150, 10, 2.6, 93, 41, 1026.3
9, 86, 32, 59, 61.5, 0, 240, 7.6, 220, 12, 6, 78, 46, 1018.6
10, 84, 64, 74, 57.5, 0, 210, 6.6, 50, 9, 3.4, 84, 40, 1019
11, 91, 59, 75, 66.3, 0, 250, 7.1, 230, 12, 2.5, 93, 45, 1012.6
12, 88, 73, 81, 68.7, 0, 250, 8.1, 270, 21, 7.9, 94, 51, 1007
13, 70, 59, 65, 55, 0, 150, 3, 150, 8, 10, 83, 59, 1012.6
14, 61, 59, 60, 55.9, 0, 60, 6.7, 80, 9, 10, 93, 87, 1008.6
15, 64, 55, 60, 54.9, 0, 40, 4.3, 200, 7, 9.6, 96, 70, 1006.1
16, 79, 59, 69, 56.7, 0, 250, 7.6, 240, 21, 7.8, 87, 44, 1007
17, 81, 57, 69, 51.7, 0, 260, 9.1, 270, 29, 5.2, 90, 34, 1012.5
18, 82, 52, 67, 52.6, 0, 230, 4, 190, 12, 5, 93, 34, 1021.3
19, 81, 61, 71, 58.9, 0, 250, 5.2, 230, 12, 5.3, 87, 44, 1028.5
20, 84, 57, 71, 58.9, 0, 150, 6.3, 160, 13, 3.6, 90, 43, 1032.5
21, 86, 59, 73, 57.7, 0, 240, 6.1, 250, 12, 1, 87, 35, 1030.7
22, 90, 64, 77, 61.1, 0, 250, 6.4, 230, 9, 0.2, 78, 38, 1026.4
23, 90, 68, 79, 63.1, 0, 240, 8.3, 230, 12, 0.2, 68, 42, 1021.3
24, 90, 77, 84, 67.5, 0, 350, 8.5, 10, 14, 6.9, 74, 48, 1018.2
25, 90, 72, 81, 61.3, 0, 190, 4.9, 230, 9, 5.6, 81, 29, 1019.6
26, 97, 64, 81, 70.4, 0, 50, 5.1, 200, 12, 4, 107, 45, 1014.9
27, 91, 72, 82, 69.7, 0, 250, 12.1, 230, 17, 7.1, 90, 47, 1009
28, 84, 68, 76, 65.6, 0, 280, 7.6, 340, 16, 7, 100, 51, 1011
29, 88, 66, 77, 59.7, 0, 40, 5.4, 20, 9, 5.3, 84, 33, 1020.6
30, 90, 45, 68, 63.6, 0, 240, 6, 220, 17, 4.8, 200, 41, 1022.7
# End of data set.

# Find the day with the smallest temperature spread:
  The day with the smallest temperature spread is day 14
  The tempereature spread is: 2 ab.units

# Read data from file: './../../data/football.csv'
# Filetpye: csv
# Used SEPERATOR: ,
# Used column names:
Team, Games, Wins, Losses, Draws, Goals, GoalsAllowed, Points
# 20 team(s) were read.

# Print all read values from './../../data/football.csv' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):
# Used column names:
Team, Games, Wins, Losses, Draws, Goals, GoalsAllowed, Points
Arsenal, 38, 26, 9, 3, 79, 36, 87
Liverpool, 38, 24, 8, 6, 67, 30, 80
Manchester United, 38, 24, 5, 9, 87, 45, 77
Newcastle, 38, 21, 8, 9, 74, 52, 71
Leeds, 38, 18, 12, 8, 53, 37, 66
Chelsea, 38, 17, 13, 8, 66, 38, 64
West_Ham, 38, 15, 8, 15, 48, 57, 53
Aston_Villa, 38, 12, 14, 12, 46, 47, 50
Tottenham, 38, 14, 8, 16, 49, 53, 50
Blackburn, 38, 12, 10, 16, 55, 51, 46
Southampton, 38, 12, 9, 17, 46, 54, 45
Middlesbrough, 38, 12, 9, 17, 35, 47, 45
Fulham, 38, 10, 14, 14, 36, 44, 44
Charlton, 38, 10, 14, 14, 38, 49, 44
Everton, 38, 11, 10, 17, 45, 57, 43
Bolton, 38, 9, 13, 16, 44, 62, 40
Sunderland, 38, 10, 10, 18, 29, 51, 40
Ipswich, 38, 9, 9, 20, 41, 64, 36
Derby, 38, 8, 6, 24, 33, 63, 30
Leicester, 38, 5, 13, 20, 30, 64, 28
# End of data set.

# Find the team with the smallest distance (absolute difference between 'Goals' and 'Goals Allowed'):
  The team with the smallest distance is 'Aston_Villa'
  The distance is: 1 goal(s)

# Program successfully finished.
```

# --- Tasks (Copied from exxcellent / programming-challenge) ---


Weather

In weather.csv you’ll find the daily weather data of a single month. Read the file, then output the day number (column one Day) of the day with the smallest temperature spread (difference between maximum & minimum temperature of the day.) The maximum temperature is the second column MxT, the minimum temperature the third column MnT.

Football

The football.csv file contains results of the English Premier League. The columns labelled ‘Goals’ and ‘Goals Allowed’ contain the total number of goals scored by and against each team (so Arsenal scored 79 goals themselves and had 36 goals scored against them). Read the file, then print the name of the team with the smallest distance (absolute difference) between ‘Goals’ and ‘Goals Allowed’.

Task

Try to write a single program, which is able to solve the "Weather" challenge. Then try to refactor & extend your solution, that it additionally supports the Football challenge.
