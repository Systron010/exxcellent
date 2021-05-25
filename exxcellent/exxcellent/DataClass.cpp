#include "DataClass.h"


void DataClass::ReadFile()
{
	cout << endl;
	cout << "# Read data from file: '" << fileName << "'" << endl;

	// Open file with 'fileName'
	fstream file;
	file.open(fileName, ios::in);

	// Check if file exists
	if (!file) 
	{
		cerr << endl;
		cerr << "# ERROR: No such file found! Program stopped!" << endl;
		exit(-1);
	}

	// Get file type
	fileType = GetFileType(fileName);

	// Check filetype and load the corresponding file reading function if implemented
	if (fileType == "csv") 
	{
		SEPARATOR = ',';
		cout << "# Used SEPARATOR: " << SEPARATOR << endl;
		ReadFile_CSV(file);
	}
	else if (fileType == "json") 
	{
		ReadFile_JSON(file);
	}
	else 
	{
		cerr << endl;
		cerr << "# ERROR: Filetpye '." << fileType << "' is not supported! Program stopped!" << endl;
		exit(-1);
	}
	
	// Close file
	file.close();
}


string DataClass::GetFileType(string fileName)
{
	// Get index of "." in the string
	string::size_type index;
	index = fileName.rfind('.');
	// Get fileType string
	string fT = fileName.substr(index + 1);
	cout << "# Filetpye: " << fT << endl;
	// Return fileType
	return fT;
}


void DataClass::ReadFile_CSV(fstream& file)
{
	// Read first line to get the column names and their number
	string currentLine;
	getline(file, currentLine);
	numColumns = GetColumnNames_CSV(currentLine);
	// Print all column names to console
	PrintColumnNames_CSV();
	// Read each line of the file and save the read data to a struct vector
	ReadEachLine_CSV(file);
	// Print number of read data sets to console
	cout << "# " << numDataSets << " " << dataName << " were read." << endl;
}


unsigned int DataClass::GetColumnNames_CSV(string currentLine)
{
	// Create a stringstream from current line
	stringstream strStream(currentLine);

	// Extract each column name
	string currentColName;
	while (getline(strStream, currentColName, SEPARATOR)) 
	{
		// Remove 'space' in 'currentColName
		std::string::iterator end_pos = std::remove(currentColName.begin(), currentColName.end(), ' ');
		currentColName.erase(end_pos, currentColName.end());
		// Add current column name to 'columnNames' vector
		columnNames.push_back(currentColName);
	}

	// Return number of columns
	return columnNames.size();
}


void DataClass::PrintColumnNames_CSV()
{
	cout << "# Used column names:" << endl;
	// Loop over all coulumn names in 'columnNames' vector and print to console
	for (size_t i = 0; i < columnNames.size(); ++i) 
	{
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
		// Increase number of read data sets by 1
		numDataSets++;	
		// Check that the currentLine has the correct number of columns
		if (checkNumOfColumns(currentLine) ) 
		{
			// If true: Pass currentLine to the parsing function (Which is overwritten by the daughter class)
			ParsingLineAndSaveValues_CSV(currentLine);
		}
		else 
		{
			cerr << endl;
			cerr << "# ERROR while reading file '" << fileName << "': Number of columns/commas for line " << numDataSets + 1 << " is wrong! Program stopped!" << endl;
			exit(-1);
		}
	}

}


bool DataClass::checkNumOfColumns(string currentLine)
{
	bool result = false;
	// Get numbers of SEPARATORS in line
	size_t numSeparators = count(currentLine.begin(), currentLine.end(), SEPARATOR);
	// Check that numSeparators+1 is euqal to the number of header columns
	if (numSeparators + 1 == numColumns)
		result = true;
	return result;
}


void DataClass::ParsingLineAndSaveValues_CSV(string currentLine)
{
	cerr << endl;
	cerr << "# ERROR: If this function 'void DataClass::ParsingLineAndSaveValues_CSV(string currentLine)' is called, it is not overridden by the calling daughter class."
		 << " But this function has to be overridden because a global valid pre-definton in 'DataClass' is unfeasible." << endl;
	cerr << "# Program stopped!" << endl;
	exit(-1);
}


void DataClass::PrintAllData()
{
	cerr << endl;
	cerr << "# ERROR: If this function 'void DataClass::PrintAllData()' is called, it is not overridden by the calling daughter class."
		 << " But this function has to be overridden because a global valid pre-definton in 'DataClass' is unfeasible." << endl;
	cerr << "# Program stopped!" << endl;
	exit(-1);
}


void DataClass::ReadFile_JSON(fstream& file)
{
	cerr << endl;
	cerr << "# ERROR: Filetpye '." << fileType << "' is not supported so far! Program stopped!" << endl;
	exit(-1);
}