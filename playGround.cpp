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
	
	
	_pMapEditScene = new MAPEDIT();
	_pstageScene = new STAGESCENE();
	_pMinTest = new MINTESTSCENE();
	_pBossStageScene = new BossStageScene();

	SCENEMANAGER->addScene("mapEditScene", _pMapEditScene);
	SCENEMANAGER->addScene("stageScene", _pstageScene);
	SCENEMANAGER->addScene("bossStage", _pBossStageScene);
	SCENEMANAGER->addScene("MinTest", _pMinTest);
	
	SCENEMANAGER->changeScene("MinTest");
	//SCENEMANAGER->changeScene("bossStage");

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
