#include "stdafx.h"
#include "relics_Home.h"




RELICS_HOME::RELICS_HOME()
	:_frameX(0)
{
}

RELICS_HOME::~RELICS_HOME()
{
}

HRESULT RELICS_HOME::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsHome", "resource/item/relicsHome.bmp", 1251, 503, 2, 1, true, RGB(255, 0, 255)));
	OBJECT::init(x, y,125, 503);
	return S_OK;
}


void RELICS_HOME::release()
{
	OBJECT::setImage(nullptr);
}

void RELICS_HOME::update()
{
}

void RELICS_HOME::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _frameX, 0);
}
