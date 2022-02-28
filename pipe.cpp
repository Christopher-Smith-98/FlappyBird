#include "pipe.h"

float scrollSpeed = 14.0f;

void Pipes::Update(float fElapsedTime) 
{
	// change 14.0 to local 'scrollSpeed' variable 
	fLevelPosition += scrollSpeed * fElapsedTime;

	if (fLevelPosition > fSectionWidth)
	{

	}
}

void Pipes::PickNewPipe()
{
	fLevelPosition -= fSectionWidth;
	listSection.pop_front();
	int i = rand() % (ScreenHeight() - 20);
	if (i <= 10) i = 0;
	listSection.push_back(i);
}