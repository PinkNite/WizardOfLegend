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
	//��Ʈ���� �浹ó��
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
		//�浹�̴�
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

	/*char str[128];
	sprintf_s(str, "%2lf%2lf", _x,_y);
	TextOut(hdc, 400, 400, str, strlen(str));*/

}

void STATUSSELECT::keySetting()
{
	if ((KEYMANAGER->isOnceKeyDown('A')|| KEYMANAGER->isOnceKeyDown(VK_LEFT)) && _y == 148)
	{
		_x -= 66;
	}
	if ((KEYMANAGER->isOnceKeyDown('D') || KEYMANAGER->isOnceKeyDown(VK_RIGHT)) && _y == 148)
	{
		_x += 66;


	}
	if (KEYMANAGER->isStayKeyDown('W') || KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_y = 148;
		_x = 211;

	}
	if (KEYMANAGER->isStayKeyDown('S') || KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_y = 330;
		_x = 211;

	}
	if (_x > 541)//������ �� �Ѿ�� ��������
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
