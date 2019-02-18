#include "stdafx.h"
#include "statusBox.h"



STATUSBOX::STATUSBOX()
	:_alpha(255), _frameX(0), _frameY(0), _isCollision(0),_isClick(0),_index(0)
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
	
		_pSkillIcon = new SKILLICON;
		_pSkillIcon->init(_x-2, _y-2);
		
		//_pSkillIcon->setNum(i);

		
	
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
	
	_pSkillIcon->move(_x-2, _y-2);
	
}

void STATUSBOX::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, _x, _y, _frameX, _frameY, _alpha);
	
		_pSkillIcon->render(hdc);
		char str[200];
		sprintf_s(str, "%d", _skillNum);
		TextOut(hdc, _x, _y, str, strlen(str));

}

void STATUSBOX::setSkillXY(int x, int y)
{
	_skillX = x;
	_skillY = y;
}

void STATUSBOX::setSkillNum(int num)
{
	_skillNum = num;
}
