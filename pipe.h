#pragma once
#include <list>

// rename class and file to Pipes
class Pipe 
{
	float fLevelPosition;
	float fSectionWidth;
	list<int> listSection;

	// do reset function
	void Update(float fElapsedTime);
};