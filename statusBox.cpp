#include "stdafx.h"
#include "statusBox.h"



STATUSBOX::STATUSBOX()
	:_alpha(255), _frameX(0), _frameY(0), _isCollision(0),_isClick(0)
{
}

STATUSBOX::~STATUSBOX()
{
}

HRESULT STATUSBOX::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("statusBox", "resource/UI/statusUIBox.bmp", 160, 40, 4, 1, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 160, 40);
	_rc = RectMake(x, y, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());
	_x = x;
	_y = y;
	_skillNumber = SKILL_EMPTY;
	
	return S_OK;
}

void STATUSBOX::release()
{
}

void STATUSBOX::update()
{
	/*if (KEYMANAGER->isStayKeyDown('P'))
	{
		if (_alpha == 255)
		{
			_alpha = 0;
		}
		else
		{
			_alpha = 255;
		}
	}*/
	if (_isCollision)
	{
		_alpha += 4;
		if (_alpha > 250)
		{
			_alpha = 100;
		}
	}
	else
	{
		_alpha = 255;
	}


	//2번으로 바뀌어야함
	_rc = RectMake(_x, _y, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());
}

void STATUSBOX::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _frameX, _frameY, _alpha);

}
