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

void Graphics::DrawString(int x, int y, string s)
{
    int startPos = w * y + x;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        screen[startPos + i] = c;
    }
}

void Graphics::DrawBird(Bird bird) 
{
	// replace with bird.fBirdVelocity etc.
	if (bird.fBirdVelocity > 0)
	{
		DrawString(bird.nBirdX, bird.fBirdPosition + 0, L"\\\\\\");
		DrawString(bird.nBirdX, bird.fBirdPosition + 1, L"<\\\\\\=Q");
	}
	else
	{
		DrawString(bird.nBirdX, bird.fBirdPosition + 0, L"<///=Q");
		DrawString(bird.nBirdX, bird.fBirdPosition + 1, L"///");
	}

	DrawString(1, 1, L"Attempt: " + to_wstring(bird.nAttemptCount) + L" Score: " + to_wstring(bird.nFlapCount) + L" High Score: " + to_wstring(bird.nMaxFlapCount));
}





void Fill(int x1, int x2, int y1, int y2, char c) {
	for (int x = x1; x < x2; x++)
	{
		for (int y = y1; y < y2; y++)
		{
			screen[y * w + x] = c;
		}
	}
}


void Graphics::DrawPlayAgain(Bird bird) {
	if (bird.bHasCollided)
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

void Graphics::DrawPipes()
{

	// Replace with your own Fill function
	

	int gap = 5;
	int pipeW = 7;
	Fill(x - pipeW, x + pipeW, 0, y - gap, 'X');
	Fill(x - pipeW, x + pipeW, y + gap, h, 'X');
	// Collision Detection
	// move to Bird.checkCollision
	CheckCollision();
}



