#pragma once

#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<iostream>

class AI
{
public:
	AI();

	~AI();

	void addAccumulativeSeconds(float s);

	float getAccumulativeSeconds();

	void resetAccumulativeSeconds();

	void setSecondsGoal(float s);

	float getSecondsGoal();

	void setStartX(float x);

	float getStartX();

	void setStartZ(float z);

	float getStartZ();

	void setEndX(float x);

	float getEndX();

	void setEndZ(float z);

	float getEndZ();

	void setGoalX(float x);

	float getGoalX();

	void setGoalZ(float z);

	float getGoalZ();

	void setVecX(float x);

	float getVecX();

	void setVecZ(float z);

	float getVecZ();

	void brownian2DGrid(float originalX, float originalZ);

private:
	float accumulativeSeconds;
	float secondsGoal;
	float m_startX;
	float m_startZ;
	float m_endX;
	float m_endZ;
	float m_goalX;
	float m_goalZ;
	float m_vecX;
	float m_vecZ;
};