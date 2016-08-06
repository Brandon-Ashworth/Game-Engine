#include "Animation.h"


Animation::Animation(void)
{
	currentDelta = 0.f;
	currentFrame = 0;
	m_speed = 0.f;
	size =0;
}


Animation::~Animation(void)
{
}

void Animation::loadList(std::string location)
{
	objLoader load;
	std::vector<std::string> loadFiles;
	std::fstream fs;
	std::string text;
	fs.open(location);

	//load the objects 
	fs >> text;
	do
	{
		loadFiles.push_back(text);
		fs >> text;
	}while(!fs.eof());
	loadFiles.push_back(text);

	//set the size of the array
	size = loadFiles.size();

	//actuall load the objects
	int i = 0;
	for(i=0;i<loadFiles.size();i++)
	{
		VAO temp;
		temp = load.load(loadFiles[i]);
		anim[i] = temp;
	}
	
}

void Animation::setSpeed(float speed)
{
	m_speed = speed;
}

void Animation::getFrame(float time, VAO &current)
{
	currentDelta += time;

	if(currentDelta > m_speed)
	{
		currentFrame++;
		currentDelta -=m_speed;
	}

	if(currentFrame >= size)
		currentFrame = 0;

	current = anim[currentFrame];
		
}

