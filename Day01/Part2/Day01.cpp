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
	Traverser CurrentTraverser;
	
	for (string CurrentInput : FileInput)
	{
		CurrentTraverser.ExecuteInstruction(CurrentInput);
	}
	
	if (CurrentTraverser.HasRevisitedLocation())
	{
		return CurrentTraverser.GetDistanceOfRevisitedLocation();
	}
	else
	{
		return -1;
	}
}

// ------------------------------------------------------

int main()
{
	vector<string> FileInput = FileParserFunctions::ExtractTextFromFileWithDelimiter("Inputs/Puzzle2.txt", ',');
	
	if (!FileInput.empty())
	{
		std::cout << "The repeated block is " << GetTraversedBlocks(FileInput);
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

