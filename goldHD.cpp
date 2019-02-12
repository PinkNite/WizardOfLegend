#include "stdafx.h"
#include "goldHD.h"



GOLDHD::GOLDHD()
	:_frameX(0), _x(0), _y(0)
{
}

GOLDHD::~GOLDHD()
{
}

HRESULT GOLDHD::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("goldHD", "resource/UI/goldHD.bmp", 80, 40, 2, 1, true, RGB(255, 0, 255)));
	_x = x;
	_y = y;
	return S_OK;
}

void GOLDHD::release()
{
}

void GOLDHD::update()
{
}

void GOLDHD::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc, _x, _y, _frameX, 0);
}
