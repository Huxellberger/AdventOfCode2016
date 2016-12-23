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
	
	void SetDirection(const string& NewInstruction);
	void SetMagnitude(const string& NewInstruction);
	
	int GetMagnitudeBasedOnInput(const string& NewInstruction) const;
	
	static const int DIRECTION_NORTH;
	static const int DIRECTION_EAST;
	static const int DIRECTION_SOUTH;
	static const int DIRECTION_WEST;
	
	static const int ASCII_MODIFIER;
};

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

