// Jake Huxell 2016

#include "Traverser.h"

#include <iostream>
#include <map>
#include <math.h>
#include <string>

// ------------------------------------------------------

using std::cout;
using std::map;
using std::string;

// ------------------------------------------------------

const int Traverser::DIRECTION_NORTH = 0;
const int Traverser::DIRECTION_EAST = 1;
const int Traverser::DIRECTION_SOUTH = 2;
const int Traverser::DIRECTION_WEST = 3;

const int Traverser::ASCII_MODIFIER = -48;

// ------------------------------------------------------

Traverser::Traverser()
	: PointsVisited()
	, CurrentDirection(0)
	, CurrentX(0)
	, CurrentY(0)
	, DistanceOfRevisitedLocation(-1)
	, RevisitedLocation(false)
{

}

// ------------------------------------------------------

void Traverser::ExecuteInstruction(const string& NewInstruction)
{
	if (NewInstruction.length() < 3)
	{
		cout << "\nERROR! Instruction was ill-formed!\n";
	}
	else
	{
		SetDirection(NewInstruction);
		SetMagnitude(NewInstruction);
	}
	
	cout << "(" << CurrentX << ", " << CurrentY << ")\n";		
}

// ------------------------------------------------------

int Traverser::GetDistanceTravelled() const
{
	cout << "(" << CurrentX << ", " << CurrentY << ")";
	if (CurrentX * CurrentY < -1)
	{
		return CurrentX - CurrentY;
	}		
	return CurrentX + CurrentY;	
}

// ------------------------------------------------------

bool Traverser::HasRevisitedLocation() const
{
	return RevisitedLocation;
}

// ------------------------------------------------------

int Traverser::GetDistanceOfRevisitedLocation() const
{
	return DistanceOfRevisitedLocation;
}

// ------------------------------------------------------

void Traverser::SetDirection(const string& NewInstruction)
{
	if (NewInstruction[1] == 'R')
	{
		CurrentDirection += 1;
		if (CurrentDirection > 3)
		{
			CurrentDirection = 0;
		}
	}
	else
	{
		CurrentDirection -= 1;
		if (CurrentDirection < 0)
		{
			CurrentDirection = 3;
		}
	}
}

// ------------------------------------------------------

void Traverser::SetMagnitude(const string& NewInstruction)
{
	int ChangeInMagnitude = GetMagnitudeBasedOnInput(NewInstruction);
	cout << "Magnitude change of " << ChangeInMagnitude << ". ";
	
	switch (CurrentDirection)
	{
		case DIRECTION_NORTH:
			cout << "Now Facing North at ";
			CurrentY += ChangeInMagnitude;
			break;
		case DIRECTION_EAST:
		cout << "Now Facing East at ";
			CurrentX += ChangeInMagnitude;	
			break;
		case DIRECTION_SOUTH:
		cout << "Now Facing South at ";
			CurrentY -= ChangeInMagnitude;
			break;
		case DIRECTION_WEST:
		cout << "Now Facing West at ";
			CurrentX -= ChangeInMagnitude;
			break;
		default:
			cout << "\nInvalid Direction!\n";
			break;
	}
	
	string Key = std::to_string(CurrentX) + ", " + std::to_string(CurrentY);
	if (PointsVisited.count(Key) > 0 && !RevisitedLocation)
	{
		cout << "\nHas Already Visited this Location! Yahoo!\n";
		RevisitedLocation = true;
		DistanceOfRevisitedLocation = PointsVisited[Key];
	}
	else
	{
		PointsVisited.emplace(Key, GetDistanceTravelled());
	}
}

// ------------------------------------------------------

int Traverser::GetMagnitudeBasedOnInput(const string& NewInstruction) const
{
	int CurrentDigit = 1;
	int ChangeInMagnitude = 0;
	for (int i = NewInstruction.length() - 1; i > 1; i--)
	{
		ChangeInMagnitude += ((int)NewInstruction[i] + ASCII_MODIFIER) * CurrentDigit;
		CurrentDigit *= 10;
	}
	
	return ChangeInMagnitude;
}

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

