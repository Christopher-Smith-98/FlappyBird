#include "pipe.h"


// Move Draw Pipes to graphics
// none of this should be here
void Pipe::DrawPipes() 
{

	// Replace with your own Fill function
	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

	// Draw Sections
	int nSection = 0;
	for (auto s : listSection)
	{
		if (s != 0)
		{
			Fill(nSection * fSectionWidth + 10 - fLevelPosition, ScreenHeight() - s, nSection * fSectionWidth + 15 - fLevelPosition, ScreenHeight(), PIXEL_SOLID, FG_GREEN);
			Fill(nSection * fSectionWidth + 10 - fLevelPosition, 0, nSection * fSectionWidth + 15 - fLevelPosition, ScreenHeight() - s - 15, PIXEL_SOLID, FG_GREEN);
		}
		nSection++;
	}

	int nBirdX = (int)(ScreenWidth() / 3.0f);

	// Collision Detection
	// move to Bird.checkCollision
	bHasCollided = fBirdPosition < 2 || fBirdPosition > ScreenHeight() - 2 ||
		m_bufScreen[(int)(fBirdPosition + 0) * ScreenWidth() + nBirdX].Char.UnicodeChar != L' ' ||
		m_bufScreen[(int)(fBirdPosition + 1) * ScreenWidth() + nBirdX].Char.UnicodeChar != L' ' ||
		m_bufScreen[(int)(fBirdPosition + 0) * ScreenWidth() + nBirdX + 6].Char.UnicodeChar != L' ' ||
		m_bufScreen[(int)(fBirdPosition + 1) * ScreenWidth() + nBirdX + 6].Char.UnicodeChar != L' ';
}


void Pipe::Update(float fElapsedTime) 
{
	// change 14.0 to local 'scrollSpeed' variable 
	fLevelPosition += 14.0f * fElapsedTime;

	if (fLevelPosition > fSectionWidth)
	{
		fLevelPosition -= fSectionWidth;
		listSection.pop_front();
		int i = rand() % (ScreenHeight() - 20);
		if (i <= 10) i = 0;
		listSection.push_back(i);
	}
}