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
	int w;
	int h;

	void CreateBuffer(int wIn, int hIn);
	void ClearScreen();
	void DrawString(Bird bird);
	void DrawBird(Bird bird);
	void DrawPlayAgain(Bird bird);
	void DisplayFrame();
	void Draw(Bird bird);
};





