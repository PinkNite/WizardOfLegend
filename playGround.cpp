#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}



HRESULT playGround::init()
{
	gameNode::init(true);
	
	//intro
	SOUNDMANAGER->addSound("title", "resource/sound/TitleScreen.wav", 1, 1);
	SOUNDMANAGER->addSound("mapEditor", "resource/sound/PlayerRoom.wav", 1, 1);
	SOUNDMANAGER->addSound("boss", "resource/sound/ice.wav", 1, 1);
	SOUNDMANAGER->addSound("happy", "resource/sound/Tutorial.wav", 1, 1);
	SOUNDMANAGER->addSound("ending", "resource/sound/Ending.wav", 1, 1);
	SOUNDMANAGER->addSound("credit", "resource/sound/Credits.wav", 1, 1);
	SOUNDMANAGER->addSound("correct", "resource/sound/Correct.wav", 1, 0);
	SOUNDMANAGER->addSound("crowdCheer", "resource/sound/CrowdCheer.wav", 1, 0);
	
	_pMapEditScene = new MAPEDIT();
	_pstageScene = new STAGESCENE();
	_pMinTest = new MINTESTSCENE();
	_pBossStageScene = new BossStageScene();
	_pLeeTest = new LEETEST();
	_pIntroScene = new INTROSCENE();
	_pGameScene = new GAMESCENE();

	SCENEMANAGER->addScene("mapEditScene", _pMapEditScene);
	SCENEMANAGER->addScene("stageScene", _pstageScene);
	SCENEMANAGER->addScene("bossStage", _pBossStageScene);
	SCENEMANAGER->addScene("MinTest", _pMinTest);
	SCENEMANAGER->addScene("leeTest", _pLeeTest);
	SCENEMANAGER->addScene("intro", _pIntroScene);
	SCENEMANAGER->addScene("gameScene", _pGameScene);

	SCENEMANAGER->changeScene("mapEditScene");
	//SCENEMANAGER->changeScene("MinTest");
	//SCENEMANAGER->changeScene("bossStage");
	//SCENEMANAGER->changeScene("intro");
	SCENEMANAGER->changeScene("leeTest");
	//SCENEMANAGER->changeScene("gameScene");

	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	
	SCENEMANAGER->update();
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//===========================================================
	SCENEMANAGER->render();


	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
