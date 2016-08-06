#include "AI.h"

AI::AI()
{
	accumulativeSeconds = 0.0f;
	secondsGoal = 1.0f;
	m_startX = 0.0f;
	m_startZ = 0.0f;
	m_endX = 0.0f;
	m_endZ = 0.0f;
	m_goalX = 0.0f;
	m_goalZ = 0.0f;
	m_vecX = 1.0f;
	m_vecZ = 1.0f;
	srand (time(NULL));
}

AI::~AI()
{
}

void AI::addAccumulativeSeconds(float s)
{
	accumulativeSeconds += s;
}

float AI::getAccumulativeSeconds()
{
	return accumulativeSeconds;
}

void AI::resetAccumulativeSeconds()
{
	accumulativeSeconds = 0.0f;
}

void AI::setSecondsGoal(float s)
{
	secondsGoal = s;
}

float AI::getSecondsGoal()
{
	return secondsGoal;
}

void AI::setStartX(float x)
{
	m_startX = x;
}

float AI::getStartX()
{
	return m_startX;
}

void AI::setStartZ(float z)
{
	m_startZ = z;
}

float AI::getStartZ()
{
	return m_startZ;
}

void AI::setEndX(float x)
{
	m_endX = x;
}

float AI::getEndX()
{
	return m_endX;
}

void AI::setEndZ(float z)
{
	m_endZ = z;
}

float AI::getEndZ()
{
	return m_endZ;
}

void AI::setGoalX(float x)
{
	m_goalX = x;
}

float AI::getGoalX()
{
	return m_goalX;
}

void AI::setGoalZ(float z)
{
	m_goalZ = z;
}

float AI::getGoalZ()
{
	return m_goalZ;
}

void AI::setVecX(float x)
{
	m_vecX = x;
}

float AI::getVecX()
{
	return m_vecX;
}

void AI::setVecZ(float z)
{
	m_vecZ = z;
}

float AI::getVecZ()
{
	return m_vecZ;
}

void AI::brownian2DGrid(float originalX, float originalZ)
{
	m_goalX = (rand() % (int)((m_endX - m_startX) * 100.0)) / 100.0 + m_startX;
	m_goalZ = (rand() % (int)((m_endZ - m_startZ) * 100.0)) / 100.0 + m_startZ;

	float tempVecX = m_goalX - originalX;
	float tempVecZ = m_goalZ - originalZ;

	float uv = 1/(sqrt(pow(tempVecX, 2) + pow(tempVecZ, 2)));

	m_vecX = tempVecX * uv;
	m_vecZ = tempVecZ * uv;
}