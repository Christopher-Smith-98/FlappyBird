#pragma once
#include <list>

class Pipe 
{
	float fLevelPosition;
	float fSectionWidth;
	list<int> listSection;

	void Update(float fElapsedTime);
};