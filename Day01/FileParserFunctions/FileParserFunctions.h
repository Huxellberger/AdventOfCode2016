// Jake Huxell 2016

#pragma once

#include <string>
#include <vector>

// ------------------------------------------------------

using std::string;
using std::vector;

// ------------------------------------------------------

class FileParserFunctions
{
public:

	FileParserFunctions() = delete;
	
	static vector<string> ExtractTextFromFileWithDelimiter(const string& FilePath, const char SuppliedDelimiter);
};

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

