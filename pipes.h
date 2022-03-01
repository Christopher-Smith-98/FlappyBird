#pragma once
#include <list>

// rename class and file to Pipes
class Pipes
{
	float fLevelPosition;
	float fSectionWidth;
	list<int> listSection;
	float scrollSpeed = 14.0f;
	
	// do reset function
	void Update(float fElapsedTime);
	void PickNewPipe();
};