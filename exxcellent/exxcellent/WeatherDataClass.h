// Include Standard libraries
#include <iostream>
#include <string>
// Use std namespace
using namespace std;

class WeatherDataClass
{
public:
	WeatherDataClass(string in_fileName, int in_verbose);


private:
	string fileName;
	int verbose;

};

