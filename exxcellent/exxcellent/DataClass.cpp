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
			SEPARATOR = ',';
			cout << "# Used SEPERATOR: " << SEPARATOR << endl;
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
	ReadEachLine_CSV(file);
	// Print number of read data sets to console
	cout << "# " << numDataSets << " " << dataName << " were read." << endl;
}


unsigned int DataClass::GetColumnNames_CSV(string currentLine)
{
	// Create a stringstream from current line
	stringstream strStream(currentLine);
	string currentColname;

	// Extract each column name
	while (getline(strStream, currentColname, SEPARATOR)) {
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


void DataClass::ReadEachLine_CSV(fstream& file)
{
	string currentLine;
	// Loop over all lines in the file
	while (getline(file, currentLine))
	{
		// Increase number of read data sets
		numDataSets++;	
		// Check that the currentLine has the correct number of columns
		if (checkNumOfColumns(currentLine) ) {
			// If yes: Pass currentLine to the parsing function (Which is overwritten by the daughter class)
			ParsingLineAndSaveValues_CSV(currentLine);
		}
		else {
			cerr << "# ERROR while reading file '" << fileName << "': Number of columns/commas for line " << numDataSets + 1 << " is wrong! Program stopped!" << endl;
			exit(-1);
		}
		
	}
}


bool DataClass::checkNumOfColumns(string currentLine)
{
	bool result = false;
	// Get numbers of SEPERATORS in line
	size_t numSeperators = count(currentLine.begin(), currentLine.end(), SEPARATOR);
	// Check that numSeperators- +1 is euqal to number of header columns
	if (numSeperators + 1 == numColumns)
		result = true;
	return result;
}


void DataClass::ParsingLineAndSaveValues_CSV(string currentLine)
{
	cerr << "# ERROR: If this function 'void DataClass::parsingIStringStream_CSV(istringstream textStream)' is called it was not overridden be the daughter class."
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

