// Jake Huxell 2016

#include "FileParserFunctions/FileParserFunctions.h"
#include "Traverser/Traverser.h"

#include <iostream>
#include <string>
#include <vector>

// ------------------------------------------------------

using std::string;
using std::vector;

// ------------------------------------------------------

int GetTraversedBlocks(vector<string> FileInput)
{
	Traverser CurrentTraverser();
	
	for (string CurrentInput : FileInput)
	{
		CurrentTraverser.ExecuteInstruction(CurrentInput);
	}
	
	return CurrentTraverser.GetDistanceTravelled();
}

// ------------------------------------------------------

int main()
{
	vector<string> FileInput = FileParserFunctions::ExtractTextFromFileWithDelimiter("Inputs/Puzzle1.txt", ',');
	
	if (!FileInput.empty())
	{
		std::cout << "The blocks traversed are " << GetTraversedBlocks(FileInput);
	}
	else
	{
		std::cout << "Error. Input is null";
	}
	
	return 0;
}

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

