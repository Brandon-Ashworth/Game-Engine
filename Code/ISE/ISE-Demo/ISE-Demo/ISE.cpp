#include "ISE.h"



// ------------------------------ Inflatable Strawberries Engine						#-----
ISE::ISE()
{
	m_RenderEngine.create(1280, 768, "Inflatable Strawberries Engine");
	m_RenderEngine.setPerspective(75.0, 1280.0/768.0, 0.1, 5000.0);
	m_RenderEngine.setWinPos(0.0, 0.0);
	m_RenderEngine.setCameraPosition(0.0, 35.0, 0.0);
	m_RenderEngine.setCameraFocus(0.0, 35.0, -50.0);
	m_RenderEngine.setCameraUp(0.0, 1.0, 0.0);
	m_RenderEngine.setCameraMode(Camera::FREECAM);
	m_RenderEngine.setWireFrame(false);
	m_2DLeft = 0.0;
	m_2DRight = 1.0;
	m_2DDown = 0.0;;
	m_2DUp = 1.0;
	m_FOV = 75.0;
	m_Ratio = 1.0;
	m_Near = 0.1;
	m_Far = 5000.0;
	m_Width = 1280.0;
	m_Far = 768.0;
	m_SkyboxSize = 5000.0;
	m_Skybox[0] = "";
	m_Skybox[1] = "";
	m_Skybox[2] = "";
	m_Skybox[3] = "";
	m_Skybox[4] = "";
	m_Skybox[5] = "";
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\Roof.obj");
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\Wall1.obj");
	m_AssetManager.Load(AssetMng::AS_OBJ, "Data\\wall2.obj");
}

ISE::~ISE()
{
}

void ISE::ISEupdate()
{
	m_Ratio = m_Width/m_Height;
	m_2DRight = m_Width;
	m_2DUp = m_Height;
	m_RenderEngine.update();
	//m_RenderEngine.setPerspective(m_FOV, m_Ratio, m_Near, m_Far);
	m_Input.mouseUpdate();
	for(int i = 0; i < m_GameScript.size(); i++)
	{
		if(m_GameScript[i]->getEnable())
		{
			if(m_GameScript[i]->getEnableModelOverride())
			{
				m_GameObject[i]->setName(m_GameScript[i]->getGameObjectModel());
				AMloadModel(m_GameObject[i]->getName());
				m_GameScript[i]->setEnableModelOverride(false);
			}
			if(m_GameScript[i]->getEnableTextureOverride())
			{
				m_GameObject[i]->setTexture(m_GameScript[i]->getGameObjectTexture());
				AMloadTexture(m_GameObject[i]->getTexture());
				m_GameScript[i]->setEnableTextureOverride(false);
			}
		}
	}
}



// ------------------------------ Misc													#`
float ISE::MIgetDeltaTime()
{
	return m_DeltaTime.getElapsed()/1000.0f;
}



// ------------------------------ Asset Manager											#I
void ISE::AMloadModel(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_OBJ, l);
}

void ISE::AMloadTexture(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, l);
}

void ISE::AMloadSound(std::string l)
{
	m_AssetManager.Load(AssetMng::AS_SOUND, l);
}



// ------------------------------ Game Object											#II
void ISE::GOcreate3DObject(std::string name, std::string texture)
{
	m_GameObject.push_back(m_GameObjectFactory.Create(GameObjectFactory::OBJECT3D));
	m_GameScript.push_back(new gameScript);
	m_AI.push_back(new AI);
	int test = m_GameObject.max_size();
	test;
	test;
	m_GameObject[m_GameObject.size()-1]->setName(name);
	AMloadModel(name);
	m_GameObject[m_GameObject.size()-1]->setTexture(texture);
	AMloadTexture(texture);
}

void ISE::GOset3DObjectModel(int i, std::string l)
{
	m_GameObject[i]->setName(l);
}

void ISE::GOset3DObjectTexture(int i, std::string l)
{
	m_GameObject[i]->setTexture(l);
}

void ISE::GOenable3DObject(int i, bool e)
{
	m_GameObject[i]->enable(e);
}

void ISE::GOtranslate3DObject(int i, float x, float y, float z)
{
	m_GameObject[i]->translate(x, y, z);
}

void ISE::GOsetPosition3DObject(int i, float x, float y, float z)
{
	m_GameObject[i]->setPos(x, y, z);
}

float ISE::GOget3DObjectX(int i)
{
	return m_GameObject[i]->getPosX();
}

float ISE::GOget3DObjectY(int i)
{
	return m_GameObject[i]->getPosY();
}

float ISE::GOget3DObjectZ(int i)
{
	return m_GameObject[i]->getPosZ();
}

void ISE::GOrotate3DObject(int i, float x, float y, float z)
{
	m_GameObject[i]->setRotation(Axis::xAxis, x);
	m_GameObject[i]->setRotation(Axis::yAxis, y);
	m_GameObject[i]->setRotation(Axis::zAxis, z);
}

void ISE::GOcreateHUD(std::string name, std::string texture)
{
	m_GameObject.push_back(m_GameObjectFactory.Create(GameObjectFactory::hud));
	m_GameScript.push_back(new gameScript);
	m_AI.push_back(new AI);
	int test = m_GameObject.max_size();
	test;
	test;
	m_GameObject[m_GameObject.size()-1]->setName(name);
	AMloadModel(name);
	m_GameObject[m_GameObject.size()-1]->setTexture(texture);
	AMloadTexture(texture);
}

void ISE::GOsetHUDModel(int i, std::string l)
{
	m_GameObject[i]->setName(l);
}

void ISE::GOsetHUDTexture(int i, std::string l)
{
	m_GameObject[i]->setTexture(l);
}

void ISE::GOenableHUD(int i, bool e)
{
	m_GameObject[i]->enable(e);
}

void ISE::GOtranslateHUD(int i, float x, float y, float z)
{
	m_GameObject[i]->translate(x, y, z);
}

void ISE::GOrotateHUD(int i, float x, float y, float z)
{
	m_GameObject[i]->setRotation(Axis::xAxis, x);
	m_GameObject[i]->setRotation(Axis::yAxis, y);
	m_GameObject[i]->setRotation(Axis::zAxis, z);
}

void ISE::GOsetScript(int i, std::string l)
{
	m_GameScript[i]->load(l);
}

void ISE::GOenableScript(int i, bool e)
{
	m_GameScript[i]->setEnable(e);
}

void ISE::GOAIsetBrownian2DGrid(int i, float seconds, float startX, float startZ, float endX, float endZ)
{
	m_AI[i]->setSecondsGoal(seconds);

	m_AI[i]->setStartX(startX);
	m_AI[i]->setStartZ(startZ);
	m_AI[i]->setEndX(endX);
	m_AI[i]->setEndZ(endZ);

	m_AI[i]->brownian2DGrid(m_GameObject[i]->getPosX(), m_GameObject[i]->getPosZ());
	m_AI[i]->resetAccumulativeSeconds();
}

void ISE::GOAIbrownian(int i, float speed)
{
	if(m_AI[i]->getAccumulativeSeconds() <= m_AI[i]->getSecondsGoal())
	{
		float tempDT = m_DeltaTime2.elapsed()/1000.0f;
		m_AI[i]->addAccumulativeSeconds(tempDT);
	}
	else
	{
		m_AI[i]->brownian2DGrid(m_GameObject[i]->getPosX(), m_GameObject[i]->getPosZ());
		m_AI[i]->resetAccumulativeSeconds();
	}
	m_GameObject[i]->translate(m_AI[i]->getVecX() * speed, 0.0, m_AI[i]->getVecZ() * speed);
}



// ------------------------------ Input													#III
bool ISE::IOisKeyPressed(Keyboard::Key k)
{
	return m_Input.isPress(k);
}

bool ISE::IOisKeyReleased(Keyboard::Key k)
{
	return m_Input.isReleased(k);
}

bool ISE::IOisMousePressed(Mouse::Button m)
{
	return m_Input.isMousePress(m);
}

bool ISE::IOisMouseReleased(Mouse::Button m)
{
	return m_Input.isMouseReleased(m);
}

void ISE::IOlockMouse()
{
	m_Input.lockMouse();
}

void ISE::IOunlockMouse()
{
	m_Input.releaseMouse();
}

void ISE::IOsetLockMousePosition(int x, int y)
{
	m_Input.setMouseLockPosition(x, y);
}

int ISE::IOgetMouseXPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return x;
}

int ISE::IOgetMouseYPosition()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseLocation(x, y);

	return y;
}

int ISE::IOgetMouseXVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return x;
}

int ISE::IOgetMouseYVector()
{
	int x = 0;
	int y = 0;

	m_Input.getMouseVec(x, y);

	return y;
}



// ------------------------------ Render Engine											#IV
void ISE::REwindowSetSize(int w, int h)
{
	m_Width = w;
	m_Height = h;
	m_RenderEngine.setWidth(m_Width);
	m_RenderEngine.setHeight(m_Height);
}

int ISE::REwindowGetWidth()
{
	return m_RenderEngine.getWidth();
}

int ISE::REwindowGetHeight()
{
	return m_RenderEngine.getHeight();
}

void ISE::REwindowSetTitle(std::string t)
{
	m_RenderEngine.setTitle(t);
}

void ISE::RErenderGameObjects()
{
	VAO tempVAO;
	//Texture tempTex;
	for(int i = 0; i < m_GameObject.size(); i++)
	{
		if(m_GameObject[i]->getEnable())
		{
			m_AssetManager.getData(m_GameObject[i]->getName(), tempVAO);
			//m_AssetManager.getData(m_GameObject[i]->getTexture(), tempTex);
			m_AssetManager.getData(m_GameObject[i]->getTexture());
			m_RenderEngine.translate(m_GameObject[i]->getPosX(), m_GameObject[i]->getPosY(), m_GameObject[i]->getPosZ());
			m_RenderEngine.rotate(Axis::xAxis, m_GameObject[i]->getRotationX());
			m_RenderEngine.rotate(Axis::yAxis, m_GameObject[i]->getRotationY());
			m_RenderEngine.rotate(Axis::zAxis, m_GameObject[i]->getRotationZ());
			//m_RenderEngine.bindTex(tempTex);

			m_RenderEngine.setOrtho2D(m_2DLeft, m_2DRight, m_2DDown, m_2DUp);
			m_RenderEngine.Ortho2DBegin();
			if(m_GameObject[i]->isType() == 3)
			{
				m_RenderEngine.renderV(tempVAO);
			}
			m_RenderEngine.Ortho2DEnd();
			if(m_GameObject[i]->isType() == 1)
			{
				m_RenderEngine.renderV(tempVAO);
			}
		}
	}
}

void ISE::REsystemCycle()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	m_RenderEngine.display();
}

void ISE::REdisplaySkyboxTop()
{
	VAO tempVAO;
	
	m_AssetManager.getData("Data\\Roof.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[0].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() + m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.rotate(Axis::zAxis, 180.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxFront()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\wall2.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[1].data());
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() - m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::zAxis, 180);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBack()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\wall2.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[2].data());
	m_RenderEngine.translate(REcameraX(), REcameraY(), REcameraZ() + m_SkyboxSize/2);
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.rotate(Axis::zAxis, 180);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxLeft()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[3].data());
	m_RenderEngine.translate(REcameraX() - m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, -90.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxRight()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Wall1.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[4].data());
	m_RenderEngine.translate(REcameraX() + m_SkyboxSize/2, REcameraY(), REcameraZ());
	m_RenderEngine.rotate(Axis::xAxis, 90.0);
	m_RenderEngine.rotate(Axis::yAxis, 180.0);
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REdisplaySkyboxBottom()
{
	VAO tempVAO;

	m_AssetManager.getData("Data\\Roof.obj", tempVAO);
	m_AssetManager.getData(m_Skybox[5].data());
	m_RenderEngine.translate(REcameraX(), REcameraY() - m_SkyboxSize/2, REcameraZ());
	m_RenderEngine.renderV(tempVAO);
}

void ISE::REcameraSetPerspective(float fov, float cnear, float cfar)
{
	m_FOV = fov;
	m_Near = cnear;
	m_Far = cfar;
}

void ISE::REcameraMoveForward(float x)
{
	m_RenderEngine.moveCameraForward(x);
}

void ISE::REcameraMoveBackward(float x)
{
	m_RenderEngine.moveCameraForward(-x);
}

void ISE::REcameraMoveLeft(float x)
{
	m_RenderEngine.moveCameraLeft(-x);
}

void ISE::REcameraMoveRight(float x)
{
	m_RenderEngine.moveCameraLeft(x);
}

void ISE::REcameraMoveUp(float x)
{
	m_RenderEngine.moveCameraUp(x);
}

void ISE::REcameraMoveDown(float x)
{
	m_RenderEngine.moveCameraUp(-x);
}

void ISE::REcameraChangeMode(Camera::cameraMode m)
{
	m_RenderEngine.setCameraMode(m);
}

void ISE::REcameraLookUp(float x)
{
	m_RenderEngine.rotateCameraUp(x);
}

void ISE::REcameraLookDown(float x)
{
	m_RenderEngine.rotateCameraUp(-x);
}

void ISE::REcameraLookLeft(float x)
{
	m_RenderEngine.rotateCameraLeft(x);
}

void ISE::REcameraLookRight(float x)
{
	m_RenderEngine.rotateCameraLeft(-x);
}

float ISE::REcameraX()
{
	return m_RenderEngine.getCameraPositionX();
}

float ISE::REcameraY()
{
	return m_RenderEngine.getCameraPositionY();
}

float ISE::REcameraZ()
{
	return m_RenderEngine.getCameraPositionZ();
}

void ISE::REenableWireframe(bool e)
{
	m_RenderEngine.setWireFrame(e);
}

bool ISE::REwireframeState()
{
	return m_RenderEngine.getWireFrame();
}

void ISE::REloadTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
}

void ISE::REsetSkyboxTopTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[0].assign(t);
}

void ISE::REsetSkyboxFrontTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[1].assign(t);
}

void ISE::REsetSkyboxBackTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[2].assign(t);
}

void ISE::REsetSkyboxLeftTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[3].assign(t);
}

void ISE::REsetSkyboxRightTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[4].assign(t);
}

void ISE::REsetSkyboxBottomTexture(std::string t)
{
	m_AssetManager.Load(AssetMng::AS_TEXTURE, t);
	m_Skybox[5].assign(t);
}



// ------------------------------ Sound													#V
void ISE::SEplaySoundOnce(std::string s)
{
	m_SoundEngine.playOnce(*m_AssetManager.getData(s, AssetMng::AS_SOUND));
}

void ISE::SEplaySoundLoop(std::string s)
{
	m_SoundEngine.playWithLoop(*m_AssetManager.getData(s, AssetMng::AS_SOUND));
}

void ISE::SEsetSoundVolume(std::string s, float v)
{
	m_SoundEngine.setVolume(*m_AssetManager.getData(s, AssetMng::AS_SOUND), v);
}