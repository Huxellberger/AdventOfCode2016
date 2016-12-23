// Jake Huxell 2016

#pragma once

#include <string>

// ------------------------------------------------------

using std::string;

// ------------------------------------------------------

class Traverser
{
public:
	Traverser();
	
	void ExecuteInstruction(const string& NewInstruction);
	int GetDistanceTravelled() const;
	
private:
	int CurrentDirection;
	int CurrentX;
	int CurrentY;
};

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

