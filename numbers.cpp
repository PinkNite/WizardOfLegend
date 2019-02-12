#include "stdafx.h"
#include "numbers.h"



NUMBERS::NUMBERS()
	:_x(0), _y(0), _frameX(0)
{
}

NUMBERS::~NUMBERS()
{
}

HRESULT NUMBERS::init(int x, int y)
{
	_x = x;
	_y = y;
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("numbers", "resource/UI/numbers.bmp", 220, 29, 10, 1, true, RGB(255, 0, 255)));
	return S_OK;
}

void NUMBERS::release()
{
}

void NUMBERS::update()
{
}

void NUMBERS::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc, _x, _y, _frameX, 0);
}
