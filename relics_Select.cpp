#include "stdafx.h"
#include "relics_Select.h"



RELICS_SELECT::RELICS_SELECT()
	:_frameY(0),_alpha(255)
{
}

RELICS_SELECT::~RELICS_SELECT()
{
}

HRESULT RELICS_SELECT::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsSelect", "resource/item/selectAndBlack.bmp", 66, 132, 1, 2, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 66, 132);
	return S_OK;
}

void RELICS_SELECT::release()
{
	OBJECT::setImage(nullptr);
}

void RELICS_SELECT::update()
{
}

void RELICS_SELECT::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, OBJECT::getPosX(),OBJECT::getPosY(), 0, _frameY, _alpha);
}
