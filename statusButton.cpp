#include "stdafx.h"
#include "statusButton.h"

STATUSBUTTON::STATUSBUTTON()
	:_x(0),_y(0),_frameX(0)
{
}

STATUSBUTTON::~STATUSBUTTON()
{
}

HRESULT STATUSBUTTON::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("statusButton", "resource/UI/statusButton.bmp", 168, 26,6,1, true, RGB(255, 0, 255)));
	_x = x;
	_y = y;
	return S_OK;
}

void STATUSBUTTON::release()
{
}

void STATUSBUTTON::update()
{
}

void STATUSBUTTON::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc,_x,_y,_frameX,0);
}
