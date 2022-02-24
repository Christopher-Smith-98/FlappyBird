#pragma once

#include <list>
class Graphics;
class Input;
using namespace std;

// where bird drawing is going, probably.

class Bird
{
public:
	int nScore;

	float fBirdPosition = 0.0f;
	float fBirdVelocity = 0.0f;
	float fBirdAcceleration = 0.0f;
	float fGravity = 100.0f;
	float fLevelPosition = 0.0f;

	float fSectionWidth;
	list<int> listSection;

	int nBirdX = (int)(ScreenWidth() / 3.0f);

	bool bHasCollided = false;
	bool bResetGame = false;

	int nAttemptCount = 0;
	int nFlapCount = 0;
	int nMaxFlapCount = 0;

	void Reset();
	void Move();
	void CheckCollision(Graphics graphics, Input& input);
};