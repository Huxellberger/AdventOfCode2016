// Jake Huxell 2016

#include "FileParserFunctions.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ------------------------------------------------------

using std::cout;
using std::getline;
using std::ifstream;
using std::string;
using std::vector;

// ------------------------------------------------------

vector<string> FileParserFunctions::ExtractTextFromFileWithDelimiter(const string& FilePath, const char SuppliedDelimiter)
{
	ifstream InFile(FilePath);
	vector<string> FormattedText;
	
	if(InFile.is_open())
	{
		string CurrentText;
		
		while(getline(InFile, CurrentText, SuppliedDelimiter))
		{
			FormattedText.push_back(CurrentText);
		}
		
		InFile.close();
	}
	else
	{
		cout << "Error. Unable to open file.";
	}
	
	return FormattedText;
}

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

