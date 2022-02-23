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
	for (int i = 0; i < w * h; i++) screen[i] = L' ';
}

void Graphics::DrawString(int x, int y, String string)
{
	for (int i = 0; i < w; i++)
	{
		screen[i] = L'=';
		screen[2 * w + i] = L'=';
	}
	wsprintf(&screen[h + 5], L" F L A P P Y   B I R D                              SCORE: %d", bird.nScore);
}

void Graphics::DrawBird(Bird bird) {
	for (auto s : bird.body)
		screen[s.y * w + s.x] = bird.bDead ? L'+' : L'O';

	screen[bird.body.front().y * w + bird.body.front().x] = bird.bDead ? L'X' : L'@';
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





