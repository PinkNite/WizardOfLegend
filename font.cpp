#include "stdafx.h"
#include "font.h"




FONT::FONT()
	:_x(0),_y(0),_frameX(0)
{
}

FONT::~FONT()
{
}

HRESULT FONT::init(int x,int y)
{
	_x = x;
	_y = y;
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("menuMap", "resource/UI/menuMap.bmp", 88, 11, 2, 1, true, RGB(255, 0, 255)));
	return S_OK;
}

void FONT::release()
{
}

void FONT::update()
{
}

void FONT::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc,_x,_y,_frameX,0);
}
