#include "stdafx.h"
#include "statusBox.h"



STATUSBOX::STATUSBOX()
	:_alpha(255),_frameX(0),_frameY(0)
{
}

STATUSBOX::~STATUSBOX()
{
}

HRESULT STATUSBOX::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("statusBox", "resource/UI/statusUIBox.bmp", 160, 40, 4, 1, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());
	return S_OK;
}

void STATUSBOX::release()
{
}

void STATUSBOX::update()
{
	if (KEYMANAGER->isStayKeyDown('P'))
	{
		if (_alpha == 255)
		{
			_alpha = 0;
		}
		else 
		{
			_alpha = 255;
		}
	}
	_alpha += 4;
	if (_alpha > 250)
	{
		_alpha = 100;
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		if (_frameX >= OBJECT::getImage()->getMaxFrameX())
		{
			_frameX = 0;
		}
		else
		{

		_frameX++;
		}
	}
	
}

void STATUSBOX::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _frameX, _frameY,_alpha);
	
}
