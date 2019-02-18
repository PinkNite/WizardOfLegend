#include "stdafx.h"
#include "relics_Home.h"




RELICS_HOME::RELICS_HOME()
{
}

RELICS_HOME::~RELICS_HOME()
{
}

HRESULT RELICS_HOME::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsHome", "resource/item/relicsHome.bmp", 1251, 503, 2, 1, true, RGB(255, 0, 255)));
	return S_OK;
}


void RELICS_HOME::release()
{
}

void RELICS_HOME::update()
{
}

void RELICS_HOME::render(HDC hdc)
{
}
