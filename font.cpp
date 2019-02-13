#include "stdafx.h"
#include "font.h"




FONT::FONT()
{
}

FONT::~FONT()
{
}

HRESULT FONT::init()
{
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
	OBJECT::getImage()->render(hdc);
}
