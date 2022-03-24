#include "pipes.h"



void Pipes::Update(float fElapsedTime) 
{
	fLevelPosition += scrollSpeed * fElapsedTime;
	if (fLevelPosition > fSectionWidth)
	{

	}
}

void Pipes::PickNewPipe(int screenHeight)
{
	
	fLevelPosition -= fSectionWidth;
	listSection.pop_front();
	int i = rand() % (screenHeight - 20);
	if (i <= 10) i = 0;
	listSection.push_back(i);
	
}

void Pipes::Reset() {
}