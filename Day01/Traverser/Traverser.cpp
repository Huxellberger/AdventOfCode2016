// Jake Huxell 2016

#include "Traverser.h"

#include <string>
#include <math.h>

// ------------------------------------------------------

using std::string;

// ------------------------------------------------------

Traverser::Traverser()
	: CurrentDirection(0)
	, CurrentX(0)
	, CurrentY(0)
{

}

// ------------------------------------------------------

void Traverser::ExecuteInstruction(const string& NewInstruction)
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
	
	switch (CurrentDirection)
	{
		case 0:
			CurrentY += (int)NewInstruction[2];
			break;
		case 1:
			CurrentX += (int)NewInstruction[2];	
			break;
		case 2:
			CurrentY -= (int)NewInstruction[2];
			break;
		case 3:
			CurrentX -= (int)NewInstruction[2];
			break;
		default:
			break;
	}		
}

// ------------------------------------------------------

int Traverser::GetDistanceTravelled() const
{
	return sqrt(pow(CurrentX, 2) + pow(CurrentY, 2));	
}

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------

