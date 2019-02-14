#include "stdafx.h"
#include "playerFace.h"

PLAYERFACE::PLAYERFACE()
	:_x(0), _y(0), _alpha(255), _frameY(0)
{
}

PLAYERFACE::~PLAYERFACE()
{
}

HRESULT PLAYERFACE::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("playerFace", "resource/UI/playerFace.bmp", 279, 204, 1, 3, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 275, 201);
	_x = x;
	_y = y;

	return S_OK;
}

void PLAYERFACE::release()
{
}

void PLAYERFACE::update()
{
}

void PLAYERFACE::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), 0, _frameY, _alpha);
}
