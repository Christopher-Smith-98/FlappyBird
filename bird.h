#pragma once

#include <list>
class Graphics;
class Input;
using namespace std;

// where bird drawing is going, probably.

class Bird
{
public:
	const float fGravity = 100.0f;
	const float minFallingVelocity = fGravity / 10.0f;

	int nBirdX;
	float fBirdPosition;
	float fBirdVelocity;
	float fBirdAcceleration;
	bool bHasCollided = false;
	
	int nMaxFlapCount = 0;
	int nAttemptCount;
	int nFlapCount;
	bool bResetGame;

	void Reset();
	void Move();
	void CheckCollision(Graphics graphics, Input& input);
	void Flap();
	void Fall(float fElapsedTime);
	void Update(float fElapsedTime);
};