#include "stdafx.h"
#include "statusSelect.h"



STATUSSELECT::STATUSSELECT()
	:_x(0), _y(0), _alpha(255), _isCollision(false)
{
}

STATUSSELECT::~STATUSSELECT()
{
}

HRESULT STATUSSELECT::init()
{
	IMAGEMANAGER->addImage("statusSelect", "resource/UI/statusSelect.bmp", 46, 46, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("statusSelect"));
	OBJECT::init(211, 148, 46, 46);
	_x = OBJECT::getPosX();
	_y = OBJECT::getPosY();
	//렉트만들어서 충돌처리
	_rc=RectMake(_x, _y, OBJECT::getWidth(), OBJECT::getHeight());

	return S_OK;
}

void STATUSSELECT::release()
{
}

void STATUSSELECT::update()
{
		OBJECT::setPosX(_x);
		OBJECT::setPosY(_y);
	
	if (_isCollision)
	{
		//충돌이다
		_alpha += 2;
		if (_alpha > 250)
		{
			_alpha = 100;
		}
	}
	keySetting();
	_rc = RectMake(_x, _y, OBJECT::getWidth(), OBJECT::getHeight());
}

void STATUSSELECT::render(HDC hdc)
{
	OBJECT::getImage()->alphaRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(),_alpha);
	
	char str[128];
	sprintf_s(str, "%2lf%2lf", _x,_y);
	TextOut(hdc, 400, 400, str, strlen(str));
	
}

void STATUSSELECT::keySetting()
{
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
	if (_x > 541)//오른쪽 을 넘어가면 왼쪽으로
	{
		_x = 211;
	}
	if (_x < 211)
	{
		_x = 541;
	}

}
