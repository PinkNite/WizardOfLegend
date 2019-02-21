#include "stdafx.h"
#include "changeScene.h"




CHANGESCENE::CHANGESCENE()
{
}

CHANGESCENE::~CHANGESCENE()
{
}

HRESULT CHANGESCENE::init()
{
	
	return S_OK;
}

void CHANGESCENE::update()
{
	if (_pPlayer->getPosX() >= 3920&& _pPlayer->getPosX()<=4150 &&_pPlayer->getPosY() >=1280&& _pPlayer->getPosY() <= 1410)
	{
	
		SCENEMANAGER->changeScene("bossStage");
	}
	
}

void CHANGESCENE::release()
{
}

void CHANGESCENE::render(HDC hdc)
{
	char str[200];
	sprintf_s(str, "%2.1lf,%2.1lf", _pPlayer->getPosX(), _pPlayer->getPosY());
	TextOut(hdc, 300, 300, str, strlen(str));
}
