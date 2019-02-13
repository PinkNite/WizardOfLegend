#include "stdafx.h"
#include "skillButton.h"


SKILLBUTTON::SKILLBUTTON()
	:_frameX(0),_x(0),_y(0)
{
}

SKILLBUTTON::~SKILLBUTTON()
{
}

HRESULT SKILLBUTTON::init(int x, int y)
{
	_x = x;
	_y = y;
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("skillButton", "resource/UI/skillButton.bmp", 446, 41, 10, 1, true, RGB(255, 0, 255)));


	return S_OK;
}

void SKILLBUTTON::release()
{
}

void SKILLBUTTON::update()
{
	
}

void SKILLBUTTON::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc, _x, _y, _frameX, 0);
}
