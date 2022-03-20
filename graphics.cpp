#include <iostream>
#include <thread>
#include <list>
#include <string>
#include "graphics.h"
#include "bird.h"
#include "input.h"
using namespace std;

void Graphics::CreateBuffer(int wIn, int hIn) {
	width = wIn;
	height = hIn;
	screen = new wchar_t[width * height];
	ClearScreen();
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;
}

void Graphics::ClearScreen() {
	for (int i = 0; i < width * height; i++) screen[i] = L' ';
}

void Graphics::DrawString(int x, int y, string s)
{
    int startPos = width * y + x;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        screen[startPos + i] = c;
    }
}

void Graphics::DrawBird(Bird bird) 
{
	// replace with bird.fBirdVelocity etc.
	if (bird.yVelocity > 0)
	{
		DrawString(bird.xPosition, bird.yPosition + 0, "\\\\\\");
		DrawString(bird.xPosition, bird.yPosition + 1, "<\\\\\\=Q");
	}
	else
	{
		DrawString(bird.xPosition, bird.yPosition + 0, "<///=Q");
		DrawString(bird.xPosition, bird.yPosition + 1, "///");
	}

	DrawString(1, 1, "Attempt: " + to_string(bird.nAttemptCount) + " Score: " + to_string(bird.nFlapCount) + " High Score: " + to_string(bird.nMaxFlapCount));
}

void Graphics::Fill(int x1, int x2, int y1, int y2, char c) {
	for (int x = x1; x < x2; x++)
	{
		for (int y = y1; y < y2; y++)
		{
			screen[y * width + x] = c;
		}
	}
}

void Graphics::DrawPlayAgain(Bird bird) {
	if (bird.bHasCollided)
		wsprintf(&screen[15 * width + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
}

void Graphics::DisplayFrame() {
	WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
}

void Graphics::Draw(Bird bird)
{
	ClearScreen();
	DrawBird(bird);
	DrawPlayAgain(bird);
	DisplayFrame();
}

void Graphics::DrawPipes()
{

	// Replace with your own Fill function
	

	int gap = 5;
	int pipeW = 7;
	int pipeLipW = 2;
	int pipeLipH = 1;


	// todo: loop over all pipes in game and 
	//       use their x, y coordinates to draw the pipes
	//Fill(x - pipeW, x + pipeW, 0, y - gap, '#');
	//Fill(x - pipeW, x + pipeW, y + gap, height, '#');
	//Fill(x - pipeW - pipeLipW, x + pipeW + pipeLipW, y - gap - pipeLipH, y - gap, '#');
	//Fill(x - pipeW - pipeLipW, x + pipeW + pipeLipW, y + gap, y + gap + pipeLipH, '#');
}



