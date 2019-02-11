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
	_pLeeTest = new LEETEST();
	_pIntroScene = new INTROSCENE();


	SCENEMANAGER->addScene("mapEditScene", _pMapEditScene);
	SCENEMANAGER->addScene("stageScene", _pstageScene);
	SCENEMANAGER->addScene("MinTest", _pMinTest);
	SCENEMANAGER->addScene("leeTest", _pLeeTest);
	SCENEMANAGER->addScene("intro", _pIntroScene);


	SCENEMANAGER->changeScene("MinTest");
	SCENEMANAGER->changeScene("leeTest");
	SCENEMANAGER->changeScene("intro");
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
