#include "FootballDataClass.h"

FootballDataClass::FootballDataClass(string in_fileName)
{
	fileName = in_fileName;
	dataName = "team(s)";
}


void FootballDataClass::SaveAllValuesPerLine(vector<float> allValuesCurrentLine)
{
	// Create current team struct
	teamData currentTeam;
	currentTeam.team			= allValuesCurrentLine.at(0);
	currentTeam.games			= allValuesCurrentLine.at(1);
	currentTeam.wins			= allValuesCurrentLine.at(2);
	currentTeam.losses			= allValuesCurrentLine.at(3);
	currentTeam.draws			= allValuesCurrentLine.at(4);
	currentTeam.goals			= allValuesCurrentLine.at(5);
	currentTeam.goalsAllowed	= allValuesCurrentLine.at(6);
	currentTeam.points			= allValuesCurrentLine.at(7);

	// Save current day struct to 'vector<dayData> totalDayData'
	totalTeamData.push_back(currentTeam);
}
