#pragma once

#include "VAO.h"
#include "objLoader.h"
#include <map>
#include <string>
#include <fstream>
#include <vector>
/**
* @author Umar Badat
*/
class Animation
{
public:
	Animation(void);
	~Animation(void);

	void loadList(std::string location);

	void setSpeed(float speed);

	void getFrame(float time, VAO &current);

private:
	float currentDelta;
	int currentFrame;
	float m_speed;

	std::map<int,VAO> anim;

	int size;


};

