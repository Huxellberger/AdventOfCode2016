// Jake Huxell 2016

#pragma once

#include <map>
#include <string>

// ------------------------------------------------------

using std::map;
using std::string;

// ------------------------------------------------------

class Traverser
{
public:
	Traverser();
	
	void ExecuteInstruction(const string& NewInstruction);
	int GetDistanceTravelled() const;
	bool HasRevisitedLocation() const;
	int GetDistanceOfRevisitedLocation() const;
	
private:
	map<string, int> PointsVisited;
	int CurrentDirection;
	int CurrentX;
	int CurrentY;
	
	int DistanceOfRevisitedLocation;
	
	bool RevisitedLocation;
	
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

