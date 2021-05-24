#include "DataClass.h"


unsigned int DataClass::GetColumnNames(string currentLine)
{
	// Create a stringstream from current line
	stringstream strStream(currentLine);
	string currentColname;

	// Extract each column name
	while (getline(strStream, currentColname, ',')) {
		// Add current column name to columnNames vector
		columnNames.push_back(currentColname);
	}

	// Return number of columns
	return columnNames.size();
}


void DataClass::PrintColumnNames()
{
	cout << "# Used column names:" << endl;
	// Loop over all coulumn names and print to console
	for (size_t i = 0; i < columnNames.size(); ++i) {
		if (i < columnNames.size() - 1)
			cout << columnNames.at(i) << ", ";
		else
			cout << columnNames.at(i);
	}
	cout << endl;
}


void DataClass::ReadFile()
{
	cout << endl;
	cout << "# Read data from file: '" << fileName << "'" << endl;

	// Open file with 'fileName'
	fstream file;
	file.open(fileName, ios::in);

	// Check if file exists
	if (!file) {
		cerr << "# ERROR: No such file found! Program stopped!";
		exit(-1);
	}
	// Read file line by line if it exists
	else {
		// Read first line: the column names
		string currentLine;
		getline(file, currentLine);
		numColumns = GetColumnNames(currentLine);
		// Print all column names to console
		PrintColumnNames();
		// Read each line of the file and fill the read data to ???????????????
		ReadEachLine(file, currentLine);
		// Print number of data sets to console
		cout << "# " << numDataSets << " " << dataName << " were read." << endl;
	}

	file.close();
}


void DataClass::ReadEachLine(fstream& file, string currentLine)
{

	// Loop over all lines in the file
	while (getline(file, currentLine))
	{
		// Increase number of data sets
		numDataSets++;
		// Create a stringstream from current line
		stringstream strStream(currentLine);
		// Extract each value of current line
		float currentValue;
		vector<float> allValuesCurrentLine;
		unsigned int currentNumCol = 0;
		while (strStream >> currentValue) {
			// Save current value to allValuesCurrentLine vector
			allValuesCurrentLine.push_back(currentValue);
			currentNumCol++;
			// If the next token is a comma, ignore it and move on
			if (strStream.peek() == ',')
				strStream.ignore();
		}

		// Save all values for the current line to 'vector<dayData> totalDayData' if number of columns was correct
		if (currentNumCol == numColumns) {
			//SaveAllValuesPerLine(allValuesCurrentLine);
		}
		else {
			//cerr << "# ERROR: Number of columns for day " << totalDayData.size() + 1 << " does NOT match number of columns in the Headerline! Program stopped!" << endl;
			exit(-1);
		}

	}

}
