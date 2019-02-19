#include "stdafx.h"
#include "gameScene.h"


GAMESCENE::GAMESCENE()
{
}


GAMESCENE::~GAMESCENE()
{
}

HRESULT GAMESCENE::init()
{
	_pMap = new MAP();
	_pCamera = new CAMERA();

	_pCamera->init(WINSIZEX/2, WINSIZEY/2, WINSIZEX, WINSIZEY, _pMap->getMapCountX() * _pMap->getTileSize(), _pMap->getMapCountY() * _pMap->getTileSize());
	//_pCamera->settingCameraRange(0, 0, _pMap->getMapCountX() * _pMap->getTileSize(), _pMap->getMapCountY() * _pMap->getTileSize());

	_pMap->init("map");
	_pMap->setCamera(_pCamera);
	return S_OK;
}

void GAMESCENE::release()
{
}

void GAMESCENE::update()
{
}

void GAMESCENE::render()
{
	_pMap->render(_pCamera->getMemDC());
	_pCamera->render(getMemDC());
}
