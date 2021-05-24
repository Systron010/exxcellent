#include "DataClass.h"


void DataClass::ReadFile()
{
	cout << endl;
	cout << "# Read data from file: '" << fileName << "'" << endl;

	// Get file type
	fileType = GetFileType(fileName);

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
		// Check the file type
		if (fileType == "csv") {
			ReadFile_CSV(file);
		}		
		else {
			cerr << "# ERROR: Filetpye is not csv but no other file type is supported so far! Program stopped!" << endl;
			exit(-1);
		}		
	}

	// Close file
	file.close();
}


string DataClass::GetFileType(string fileName)
{
	string::size_type index;
	index = fileName.rfind('.');
	string fT = fileName.substr(index + 1);
	cout << "# Filetpye: " << fT << endl;
	return fT;
}


void DataClass::ReadFile_CSV(fstream& file)
{
	// Read first line to get the column names
	string currentLine;
	getline(file, currentLine);
	numColumns = GetColumnNames_CSV(currentLine);
	// Print all column names to console
	PrintColumnNames();
	// Read each line of the file and save the read data to a struct vector (defined by daughter class)
	ReadEachLine_CSV(file, currentLine);
	// Print number of read data sets to console
	cout << "# " << numDataSets << " " << dataName << " were read." << endl;
}


unsigned int DataClass::GetColumnNames_CSV(string currentLine)
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


void DataClass::ReadEachLine_CSV(fstream& file, string currentLine)
{

	// Loop over all lines in the file
	while (getline(file, currentLine))
	{
		// Increase number of read data sets
		numDataSets++;
		
		// Create a stringstream from current line
		stringstream strStream(currentLine);
		
		// Extract all values of current line
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

		// Checks that the number of column is correct for each line and then calls 'SaveAllValuesPerLine' to save all values for the current line to a struct data vector (defined by daughter class)
		CheckNumberOfColumnsAndSave(currentNumCol, allValuesCurrentLine);

	}

}


void DataClass::CheckNumberOfColumnsAndSave(unsigned int currentNumCol, vector<float> allValuesCurrentLine)
{
	if (currentNumCol == numColumns || true) {
		SaveAllValuesPerLine(allValuesCurrentLine);
	}
	else if (currentNumCol < numColumns) {
		cerr << "# ERROR: Number of columns for " << dataName << " " << numDataSets << " does NOT match number of columns in the headerline (too few columns found)! Program stopped!" << endl;
		exit(-1);
	}
	else {
		cerr << "# ERROR: Number of columns for " << dataName << " " << numDataSets << " does NOT match number of columns in the headerline (too many columns found)! Program stopped!" << endl;
		exit(-1);
	}
}


void DataClass::SaveAllValuesPerLine(vector<float> allValuesCurrentLine)
{
	cerr << "# ERROR: If this function 'void DataClass::SaveAllValuesPerLine(vector<float> allValuesCurrentLine)' is called it was not overridden be the daughter class."
		 << " But the function has to be overridden because a global valid pre-definton in 'DataClass' is unfeasible." << endl;
	cerr << "# Program stopped!" << endl;
	exit(-1);
}


void DataClass::PrintAllValues()
{
	cerr << "# ERROR: If this function 'void DataClass::PrintAllValues()' is called it was not overridden be the daughter class."
		<< " But the function has to be overridden because a global valid pre-definton in 'DataClass' is unfeasible." << endl;
	cerr << "# Program stopped!" << endl;
	exit(-1);
}

