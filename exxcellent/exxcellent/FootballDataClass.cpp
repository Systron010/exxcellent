#include "FootballDataClass.h"


FootballDataClass::FootballDataClass(string in_fileName)
{
	fileName = in_fileName;
	dataName = "team(s)";
}


void FootballDataClass::ParsingLineAndSaveValues_CSV(string currentLine)
{
	// Convert currentLine string into istringstream
	string comma_string;
	std::istringstream textStream(currentLine);

	// Create current dayData struct
	teamData currentTeam;

	// parsing the line to the teamData struct
	// first "vaule" is a string
	string team;
	getline(textStream, team, SEPARATOR);
	currentTeam.team = team;
	textStream >> currentTeam.games;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.wins;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.losses;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.draws;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.goals;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.goalsAllowed;
	getline(textStream, comma_string, SEPARATOR);
	textStream >> currentTeam.points;

	// Save currentTeam struct to 'vector<teamData> totalTeamData'
	totalTeamData.push_back(currentTeam);
}


void FootballDataClass::PrintAllValues()
{
	cout << endl;
	cout << "# Print all read values from '" << fileName << "' (Can be turned off with VERBOSE=0 in 'exxcellent.cpp'):" << endl;
	PrintColumnNames();
	// Loop over all teams in 'vector<teamData> totalTeamData'
	for (size_t i = 0; i < totalTeamData.size(); ++i) {
		teamData currentTeam = totalTeamData.at(i);
		cout << currentTeam.team << ", "
			 << currentTeam.games << ", "
			 << currentTeam.wins << ", "
			 << currentTeam.losses << ", "
			 << currentTeam.draws << ", "
			 << currentTeam.goals << ", "
			 << currentTeam.goalsAllowed << ", "
			 << currentTeam.points;
		cout << endl;
	}
	cout << "# End of data set." << endl;
}


void FootballDataClass::FindTeamWithSmallestDistance()
{
	cout << endl;
	cout << "# Find the team with the smallest distance (absolute difference between 'Goals' and 'Goals Allowed'):" << endl;

	if (totalTeamData.size() > 0) {
		// Search min distance using std::min_element and the <operator defined in 'struct teamData' 
		minDistanceTeam = min_element(totalTeamData.begin(), totalTeamData.end());
		cout << "  The team with the smallest distance is " << minDistanceTeam -> team << endl;
		unsigned int minDistance = abs( minDistanceTeam -> goals - minDistanceTeam -> goalsAllowed );
		cout << "  The distance is: " << minDistance << " goal(s)" << endl;
	}
	else {
		cout << "# WARNING: No football data loaded. So no smallest distance can be found." << endl;
	}
}