#pragma once



// ------------------------------ Major systems											#~
#include "AssetMng.h"
#include "OPENGL_Facade.h"
#include "SFML_Clock.h"
#include "SFML_Facade.h"
#include "SFML_Input.h"
#include "SFML_Texture.h"
#include "GameObjectFactory.h"
#include "Input.h"
#include "RenderEngine.h"
#include "gameScript.h"
#include "AI.h"
#include "SoundEngine.h"



// ------------------------------ Misc systems											#`
#include <stdlib.h>
#include <time.h>

#include "Clock.h"



/**
 * @brief The Inflatable Strawberries Engine Class
 * @details This is the Inflatable Strawberries Engine Class
 * @author Welsley Lui
 */
class ISE
{
public:
// ------------------------------ Inflatable Strawberries Engine						#-----
	/**
	 * @brief Constructor of the Inflatable Strawberries Engine.
	 * @details This is the constructor of the Inflatable Strawberries Engine.
	 */
	ISE();

	/**
	 * @brief Destructor of the Inflatable Strawberries Engine.
	 * @details This is the destructor of the Inflatable Strawberries Engine.
	 */
	~ISE();

	/**
	 * @brief Updates all essential functions and variables in the ISE.
	 * @details Called in the beginning of the program loop to update all the essential functions and variables within the Inflatable Strawberries Engine.
	 */
	void ISEupdate();


	
// ------------------------------ Misc													#`
	/**
	 * @brief Gets the delta time.
	 * @details Returns the delta time.
	 * @return Float of the delta time.
	 */
	float MIgetDeltaTime();



// ------------------------------ Asset Manager											#I
	/**
	 * @brief Loads in a model.
	 * @details Loads in a model from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadModel(std::string l);

	/**
	 * @brief Loads in a texture.
	 * @details Loads in a texture from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadTexture(std::string l);

	/**
	 * @brief Loads in a sound.
	 * @details Loads in a sound from a given location into the Inflatable Strawberries Engine.
	 * 
	 * @param l String of the location of the model.
	 */
	void AMloadSound(std::string l);



// ------------------------------ Game Object											#II
	/**
	 * @brief Creates a game object.
	 * @details Creates a game object into the Inflatable Strawberries Engine via the locations of the model and the texture.
	 * 
	 * @param name String of the location of the model.
	 * @param texture String of the location of the texture.
	 */
	void GOcreate3DObject(std::string name, std::string texture);

	/**
	 * @brief Sets the game object's model.
	 * @details Sets the game object's model by location. The game object is denoted by the index.
	 * 
	 * @param i Integer index of the game object.
	 * @param l String of the location of the model.
	 */
	void GOset3DObjectModel(int i, std::string l);

	/**
	 * @brief Sets the game object's texture.
	 * @details Sets the game object's texture by location. The game object is denoted by the index.
	 * 
	 * @param i Integer index of the game object.
	 * @param l String of the location of the texture.
	 */
	void GOset3DObjectTexture(int i, std::string l);

	/**
	 * @brief Sets the game object's visibility.
	 * @details Turns the visibility of the 3D game object on or off depending on the boolean given. The game object is denoted by the index.
	 * 
	 * @param i Integer index of the game object.
	 * @param e Boolean indicating visibility.
	 */
	void GOenable3DObject(int i, bool e);

	/**
	 * @brief Translates the game object's position.
	 * @details Translates the game object's position. The game object is denoted by the index.
	 * 
	 * @param i Integer index of the game object.
	 * @param x Float x value.
	 * @param y Float y value.
	 * @param z Float z value.
	 */
	void GOtranslate3DObject(int i, float x, float y, float z);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void GOsetPosition3DObject(int i, float x, float y, float z);

	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 */
	float GOget3DObjectX(int i);
	
	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 */
	float GOget3DObjectY(int i);
	
	/*
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 */
	float GOget3DObjectZ(int i);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void GOrotate3DObject(int i, float x, float y, float z);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param name [description]
	 * @param texture [description]
	 */
	void GOcreateHUD(std::string name, std::string texture);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param l [description]
	 */
	void GOsetHUDModel(int i, std::string l);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param l [description]
	 */
	void GOsetHUDTexture(int i, std::string l);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param e [description]
	 */
	void GOenableHUD(int i, bool e);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void GOtranslateHUD(int i, float x, float y, float z);
	
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void GOrotateHUD(int i, float x, float y, float z);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param l [description]
	 */
	void GOsetScript(int i, std::string l);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param e [description]
	 */
	void GOenableScript(int i, bool e);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param i [description]
	 * @param startX [description]
	 * @param startZ [description]
	 * @param endX [description]
	 * @param endZ [description]
	 */
	void GOAIsetBrownian2DGrid(int i, float seconds, float startX, float startZ, float endX, float endZ);

	void GOAIbrownian(int i, float speed);
	

	
// ------------------------------ Input													#III
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param k [description]
	 * @return [description]
	 */
	bool IOisKeyPressed(Keyboard::Key k);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param k [description]
	 * @return [description]
	 */
	bool IOisKeyReleased(Keyboard::Key k);
	
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @return [description]
	 */
	bool IOisMousePressed(Mouse::Button m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @return [description]
	 */
	bool IOisMouseReleased(Mouse::Button m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void IOlockMouse();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void IOunlockMouse();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 */
	void IOsetLockMousePosition(int x, int y);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseXPosition();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseYPosition();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseXVector();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int IOgetMouseYVector();



// ------------------------------ Render Engine											#IV
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param w [description]
	 * @param h [description]
	 */
	void REwindowSetSize(int w, int h);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int REwindowGetWidth();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int REwindowGetHeight();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param t [description]
	 */
	void REwindowSetTitle(std::string t);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void RErenderGameObjects();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	void REsystemCycle();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param fov [description]
	 * @param cnear [description]
	 * @param cfar [description]
	 */
	void REcameraSetPerspective(float fov, float cnear, float cfar);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveForward(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveBackward(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveLeft(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveRight(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveUp(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraMoveDown(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 */
	void REcameraChangeMode(Camera::cameraMode m);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookUp(float x);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookDown(float x);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookLeft(float x);

	/**
	 * @brief 
	 * @details [long description]
	 * 
	 * @param x [description]
	 */
	void REcameraLookRight(float x);

	float REcameraX();

	float REcameraY();

	float REcameraZ();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param e [description]
	 */
	void REenableWireframe(bool e);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	bool REwireframeState();

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param t [description]
	 */
	void REloadTexture(std::string t);

	void REsetSkyboxTopTexture(std::string t);

	void REsetSkyboxFrontTexture(std::string t);

	void REsetSkyboxBackTexture(std::string t);

	void REsetSkyboxLeftTexture(std::string t);

	void REsetSkyboxRightTexture(std::string t);

	void REsetSkyboxBottomTexture(std::string t);

	void REdisplaySkyboxTop();
	void REdisplaySkyboxFront();
	void REdisplaySkyboxBack();
	void REdisplaySkyboxLeft();
	void REdisplaySkyboxRight();
	void REdisplaySkyboxBottom();



// ------------------------------ Sound													#V
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEplaySoundOnce(std::string s);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEplaySoundLoop(std::string s);

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param s [description]
	 */
	void SEsetSoundVolume(std::string s, float v);



private:
// ------------------------------ Misc													#`
	Clock								m_DeltaTime;
	SFML_Clock							m_DeltaTime2;



// ------------------------------ Inflatable Strawberries Engine						#-----
	float								m_2DLeft;
	float								m_2DRight;
	float								m_2DDown;
	float								m_2DUp;
	float								m_Width;
	float								m_Height;
	float								m_FOV;
	float								m_Ratio;
	float								m_Near;
	float								m_Far;



// ------------------------------ Asset Manager											#I
	AssetMng							m_AssetManager;



// ------------------------------ Game Object											#II
	std::vector<GameObject*>			m_GameObject;
	GameObjectFactory					m_GameObjectFactory;
	std::vector<gameScript*>			m_GameScript;
	std::vector<AI*>					m_AI;




// ------------------------------ Input													#III
	Input								m_Input;
	


// ------------------------------ Render Engine											#IV
	RenderEngine						m_RenderEngine;
	std::string							m_Skybox[6];
	float								m_SkyboxSize;



// ------------------------------ Sound													#V
	SoundEngine							m_SoundEngine;
};