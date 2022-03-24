#pragma once

// includes
#include <Windows.h>

// forward declars
class Bird;

using namespace std;

class Graphics
{
public:
	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	int width;
	int height;

	void CreateBuffer(int wIn, int hIn);
	void ClearScreen();
	void DisplayFrame();

	void Draw(Bird bird);
	void DrawPipes(int height);
	void DrawBird(Bird bird);
	void DrawPlayAgain(Bird bird);
	void DrawString(int x, int y, string string);
	void Fill(int x1, int x2, int y1, int y2, char c);
};





