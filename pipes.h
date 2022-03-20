#pragma once
#include <list>

using namespace std;

class Pipes
{
public:
	float fLevelPosition;
	float fSectionWidth;
	list<int> listSection;
	float scrollSpeed = 14.0f;
	
	void Reset();
	void Update(float fElapsedTime);
	void PickNewPipe(int screenHeight);
};