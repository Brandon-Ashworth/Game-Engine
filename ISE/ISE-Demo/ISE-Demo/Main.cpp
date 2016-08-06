#include "Main.h"

#include "Sound.h"
#include "Animation.h"
#include "Render.h"
#include "Clock.h"
#include "VAO.h"

int main()
{
	//Sound snd;
	//snd.Load("Data\\lol.wav");
	//snd.play();

	ISE engine;

	engine.REsetSkyboxTopTexture("Data\\Sunny1_up.jpg");
	engine.REsetSkyboxFrontTexture("Data\\Sunny1_front.jpg");
	engine.REsetSkyboxBackTexture("Data\\Sunny1_back.jpg");
	engine.REsetSkyboxLeftTexture("Data\\Sunny1_left.jpg");
	engine.REsetSkyboxRightTexture("Data\\Sunny1_right.jpg");
	engine.REsetSkyboxBottomTexture("Data\\Sunny1_down.jpg");

	engine.REloadTexture("Data\\Menu2.jpg");
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(0, 50.0, 0.0, 0.0);
	engine.GOcreate3DObject("Data\\Terrain.obj","Data\\grass.jpg");
	engine.GOtranslate3DObject(1, 0.0, -40.0, 0.0);
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(2, 300.0, -25.0, 150.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(3, 270.0, -25.0, 190.0);
	engine.GOcreateHUD("Data\\faces2.obj", "Data\\group_photo.jpg");
	engine.GOtranslateHUD(4, winWidth/2, winHeight/2, 0.0f);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOsetPosition3DObject(5, -10.0, 0.0, -340.0);
	engine.GOAIsetBrownian2DGrid(5, 2.25, -100.0, -430.0, 80.0, -250.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(6, 75.0, 0.0, 145.0);
	engine.GOAIsetBrownian2DGrid(6, 3.5, -25.0, -45.0, 175.0, 245.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(7, 540.0, 0.0, -325.0);
	engine.GOAIsetBrownian2DGrid(7, 4.0, 440.0, -425.0, 640, -225.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(8, 395.0, 0.0, -600.0);
	engine.GOAIsetBrownian2DGrid(8, 2.5, 295.0, -700.0, 495, -500.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(9, 215.0, 0.0, -1000.0);
	engine.GOAIsetBrownian2DGrid(9, 2.0, 115.0, -1100.0, 315, -900.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(10, 840.0, 0.0, 1000.0);
	engine.GOAIsetBrownian2DGrid(10, 3.0, 740.0, 900.0, 940, 1100.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(11, 600.0, 0.0, 405.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(12, 120.0, 0.0, -300.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(13, 490.0, 0.0, -400.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(14, 395.0, 0.0, -525.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(15, 1215.0, 0.0, -1255.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(16, 760.0, 0.0, 955.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(17, 430.0, 0.0, 340.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(18, 560.0, 0.0, 420.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(19, 360.0, 0.0, -240.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(20, 125.0, 0.0, 55.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(21, -190.0, 0.0, 375.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(22, -695.0, 0.0, -365.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(23, -660.0, 0.0, 360.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(24, 825.0, 0.0, -1000.0);
	engine.GOcreate3DObject("Data\\SlenderZombie.obj","Data\\zombieTex.jpg");
	engine.GOtranslate3DObject(25, -1260.0, 0.0, 1000.0);
	engine.GOsetScript(0,"Data\\change to faces.lua");
	engine.GOenableScript(0, true);

	/*
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(19, -30.0, -25.0, 590.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(20, -50.0, -25.0, -545.0);
	engine.GOcreate3DObject("Data\\tree.obj","Data\\cannon.bmp");
	engine.GOtranslate3DObject(21, -430.0, -25.0, 750.0);
	engine.GOcreate3DObject("Data\\rock.obj","Data\\rock.jpg");
	engine.GOtranslate3DObject(22, -500.0, -25.0, 695.0);
	*/
	engine.GOenableHUD(4, false);
	engine.GOtranslate3DObject(1, 0.0, -40.0, 0.0);

	engine.REwindowSetSize(winWidth, winHeight);
	engine.IOsetLockMousePosition((int)(winWidth/2), (int)(winHeight/2));
	engine.REcameraChangeMode(Camera::FPS);
	engine.IOunlockMouse();

	//Remove me when finished
	Render render;
	Clock clock;
	Animation ani;
	VAO temp;
	ani.loadList("Data\\anim.txt");
	ani.setSpeed(200.f);

	//Input input;
	bool w = false;
	bool d = false;
	int cool = 0;
	//input.setMouseLockPosition(640, 384);

	bool run = true;
	float time = 0.0;

	while(run)
	{
		render.translate(0.0,0.0,0.0);
		ani.getFrame(clock.getElapsed(),temp);
		render.render(temp);

		float dt = engine.MIgetDeltaTime();
		engine.ISEupdate();
		updateInput(engine, run, dt);
		engine.IOlockMouse();
		render.render(temp);//A
		if(time >= 2.5)
		{
			engine.GOAIbrownian(5, 25.0f * dt);
			engine.GOAIbrownian(6, 30.0f * dt);
			engine.GOAIbrownian(7, 20.0f * dt);
			engine.GOAIbrownian(8, 40.0f * dt);
			engine.GOAIbrownian(9, 55.0f * dt);
			engine.GOAIbrownian(10, 60.0f * dt);
			engine.RErenderGameObjects();
		}
		engine.REdisplaySkyboxTop();
		engine.REdisplaySkyboxFront();
		engine.REdisplaySkyboxBack();
		engine.REdisplaySkyboxLeft();
		engine.REdisplaySkyboxRight();
		engine.REdisplaySkyboxBottom();
		engine.REsystemCycle();
		time += dt;
	}

	return 0;
}

void updateInput(ISE &engine, bool &run, float &dt)
{
	engine.REcameraLookUp(engine.IOgetMouseYVector()*12.5f*dt);
	engine.REcameraLookLeft(engine.IOgetMouseXVector()*20.0f*dt);

	float speed = 250.0f*dt;
	if(engine.IOisKeyPressed(Keyboard::W))
	{
		engine.REcameraMoveForward(speed);
		//std::cout << cool << " W" << std::endl;
		//std::cout<<"W" <<std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::S))
	{
		engine.REcameraMoveBackward(speed);
		//std::cout<<"S" <<std::endl;
		//std::cout << cool << " S" << std::endl;
	}
	if(engine.IOisKeyPressed(Keyboard::A))
	{
		engine.REcameraMoveLeft(speed);
		//std::cout<<"A" <<std::endl;
		//std::cout << cool << " A" << std::endl;
	}
	else if(engine.IOisKeyPressed(Keyboard::D))
	{
		engine.REcameraMoveRight(speed);
		//std::cout<<"D" <<std::endl;
		//std::cout << cool << " D" << std::endl;
	}
	if(engine.IOisKeyReleased(Keyboard::K))
	{
		engine.REenableWireframe(!engine.REwireframeState());
	}
	if(engine.IOisKeyPressed(Keyboard::Escape))
	{
		run = false;
	}
	if(engine.IOisKeyReleased(Keyboard::X))
	{
		enableMenu = false;
		if(gameEnd)
		{
			engine.GOenableHUD(4, false);
			gameEnd = false;
		}
		else
		{
			engine.GOsetHUDTexture(4, "Data\\group_photo.jpg");
			engine.GOenableHUD(4, true);
			gameEnd = true;
		}
	}
	if(engine.IOisKeyReleased(Keyboard::M))
	{
		gameEnd = false;
		if(enableMenu)
		{
			engine.GOsetHUDTexture(4, "Data\\group_photo.jpg");
			engine.GOenableHUD(4, false);
			enableMenu = false;
		}
		else
		{
			engine.GOsetHUDTexture(4, "Data\\Menu2.jpg");
			engine.GOenableHUD(4, true);
			enableMenu = true;
		}
	}
	if(engine.IOisKeyPressed(Keyboard::L))
	{
		engine.IOlockMouse();
	}
	if(engine.IOisKeyPressed(Keyboard::U))
	{
		engine.IOunlockMouse();
	}
	if(gameEnd)
	{
		if((engine.IOisMousePressed(Mouse::Left)) || (engine.IOisMousePressed(Mouse::Right)) || (engine.IOisMousePressed(Mouse::Middle)) || (engine.IOisMousePressed(Mouse::XButton1)) || (engine.IOisMousePressed(Mouse::XButton2)))
		{
			run = false;
		}
	}
}