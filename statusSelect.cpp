#include "stdafx.h"
#include "statusSelect.h"



STATUSSELECT::STATUSSELECT()
:_x(0),_y(0)
{
}

STATUSSELECT::~STATUSSELECT()
{
}

HRESULT STATUSSELECT::init()
{
	IMAGEMANAGER->addImage("statusSelect", "resource/UI/statusSelect.bmp", 46, 46, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("statusSelect"));
	OBJECT::init(211, 146, OBJECT::getWidth(), OBJECT::getHeight());
	_x = OBJECT::getPosX();
	_y = OBJECT::getPosY();
	return S_OK;
}

void STATUSSELECT::release()
{
}

void STATUSSELECT::update()
{
		OBJECT::setPosX(_x);
		OBJECT::setPosY(_y);
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_x -= 66;
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_x += 66;
		
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_y -= 2;
	
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_y += 2;
	
	}
}

void STATUSSELECT::render(HDC hdc)
{
	OBJECT::getImage()->render(hdc, OBJECT::getPosX(), OBJECT::getPosY());
	char str[128];
	sprintf_s(str, "%2lf%2lf", _x, _y);
	TextOut(hdc, 400, 400, str, strlen(str));
}
