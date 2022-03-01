#pragma once
#include <list>


class Pipes
{
	float fLevelPosition;
	float fSectionWidth;
	list<int> listSection;
	float scrollSpeed = 14.0f;
	
	void Reset();
	void Update(float fElapsedTime);
	void PickNewPipe();
};