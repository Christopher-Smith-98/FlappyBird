//ALL IN SNAKE FORM

#include <iostream>
#include <thread>
#include <list>
#include "graphics.h"
#include "bird.h"
#include "input.h"
using namespace std;

void Graphics::CreateBuffer(int wIn, int hIn) {
	w = wIn;
	h = hIn;
	screen = new wchar_t[w * h];
	for (int i = 0; i < w * h; i++) screen[i] = L' ';
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;
}

void Graphics::ClearScreen() {

}

void Graphics::DrawString(int x, int y, string string)
{
	// have a go at this function, 
	// will be using the screen
	screen[16] = string[0];
}

void Graphics::DrawBird(Bird bird) 
{
	// replace with bird.fBirdVelocity etc.
	if (fBirdVelocity > 0)
	{
		DrawString(nBirdX, fBirdPosition + 0, L"\\\\\\");
		DrawString(nBirdX, fBirdPosition + 1, L"<\\\\\\=Q");
	}
	else
	{
		DrawString(nBirdX, fBirdPosition + 0, L"<///=Q");
		DrawString(nBirdX, fBirdPosition + 1, L"///");
	}

	DrawString(1, 1, L"Attempt: " + to_wstring(nAttemptCount) + L" Score: " + to_wstring(nFlapCount) + L" High Score: " + to_wstring(nMaxFlapCount));
}


}


void Fill(int x1, int x2, int y1, int y2, char fillChar) {
	// have a go at making this
}


void Graphics::DrawPlayAgain(Bird bird) {
	if (bird.bDead)
		wsprintf(&screen[15 * w + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
}

void Graphics::DisplayFrame() {
	WriteConsoleOutputCharacter(hConsole, screen, w * h, { 0,0 }, &dwBytesWritten);
}

void Graphics::Draw(Bird bird)
{
	ClearScreen();
	DrawString(bird);
	DrawBird(bird);
	DrawPlayAgain(bird);
	DisplayFrame();
}





