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
	_rc = RectMake(_x, _y, OBJECT::getWidth(), OBJECT::getHeight());
	_selectState = SKILL_STATE;
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
		_alpha += 4;
		if (_alpha > 250)
		{
			_alpha = 100;
		}
	}
	keySetting();
	selectStateChange();
	_rc = RectMake(_x, _y, OBJECT::getWidth(), OBJECT::getHeight());

	/*switch (((int)_x-211)%66)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;

	}*/
}

void STATUSSELECT::render(HDC hdc)
{
	OBJECT::getImage()->alphaRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _alpha);

	//char str[128];
	//sprintf_s(str, "%2d", 11);
	//TextOut(hdc, 800, 600, str, strlen(str));

}

void STATUSSELECT::keySetting()
{
	if ((KEYMANAGER->isOnceKeyDown('A')|| KEYMANAGER->isOnceKeyDown(VK_LEFT)) && _y == 148)
	{
		_x -= 66;
	}
	else if ((KEYMANAGER->isOnceKeyDown('D') || KEYMANAGER->isOnceKeyDown(VK_RIGHT)) && _y == 148)
	{
		_x += 66;


	}
	for (int i = 0; i < 6; i++)
	{


		if ((KEYMANAGER->isStayKeyDown('W') || KEYMANAGER->isOnceKeyDown(VK_UP) )&& _selectState==ITEM_STATE)
		{
			_y = 148;
			_x = 211;
			break;

		}
		else if ((KEYMANAGER->isStayKeyDown('S') || KEYMANAGER->isOnceKeyDown(VK_DOWN) )&&_selectState==SKILL_STATE)
		{
			_y = 330;
			_x = 211;
		
			break;

		}
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

void STATUSSELECT::selectStateChange()
{
	if (_y > 148)
	{
		_selectState = ITEM_STATE;
	}
	else if(_y<=148&&_selectState!=SWAP_STATE)
	{
		_selectState = SKILL_STATE;
	}
}
