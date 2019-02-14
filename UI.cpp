#include "stdafx.h"
#include "UI.h"



UI::UI()
	:_isClick(0)
{
}

UI::~UI()
{
}

HRESULT UI::init()
{
	_pSkillUI = new SKILLUI;
	_pSkillUI->init();

	_pStatusUI = new STATUSUI;
	_pStatusUI->init();
	for (int i = 0; i < 2; i++)
	{
		_pGoldHD[i] = new GOLDHD;
		_pGoldHD[i]->init(WINSIZEX / 2 - 50, WINSIZEY - 120 + i * 50);
		_pNumbers[i] = new NUMBERS;
		_pNumbers[i]->init(WINSIZEX / 2 + 25, WINSIZEY - 115 + i * 50);

	}
	_pGoldHD[1]->setFrameX(1);
	for (int i = 0; i < 3; i++)
	{

		_pPlayerFace[i] = new PLAYERFACE;
		_pPlayerFace[i]->init(40, 40);
		_pPlayerFace[i]->setFrameY(i);
	}
	for (int i = 0; i < 2; i++)
	{
		//0번 hp바의 렉트 라이트가 레프트가 되고 시간에 영향을 받는다.업데이트에서
		_pHpBar[i] = new HPBAR;
		switch (i)
		{
		case 0:
			_pHpBar[i]->init(40 + 65, 40 + 10);
			break;
		case 1:
			_pHpBar[i]->init(40 + 65, 40 + 10);
			break;
		}
		_pHpBar[i]->setFrameY(i);

	}

	_HP = 500;
	_damage = 400;
	return S_OK;
}

void UI::release()
{
}

void UI::update()
{
	_pSkillUI->update();
	//키를 누르면 작동되게
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		if (!_isClick)
		{
			_isClick = true;
		}
		else
		{
			_isClick = false;
			_pStatusUI->setIsClick(0);
		}
	}
	if (_isClick)
	{

		_pStatusUI->update();
	}

	if (KEYMANAGER->isStayKeyDown('U'))
	{
		_HP += _damage;
	}
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		_HP -= _damage;
	}
	_pHpBar[1]->setGauge(_HP, 500);


	//_pHpBar[0]->setX(_pHpBar[1]->getRC().right);
	//_pHpBar[0]->setY(_pHpBar[1]->getRC().top);
	_pHpBar[1]->setDamage(_HP);
	_pHpBar[0]->setRcWidth(_pHpBar[1]->getHpWidth());


	for (int i = 0; i < 2; i++)
	{

		_pHpBar[i]->update();
	}
}

void UI::render(HDC hdc)
{
	_pSkillUI->render(hdc);
	if (_isClick)
	{
		_pStatusUI->render(hdc);
	}
	for (int i = 0; i < 2; i++)
	{

		_pGoldHD[i]->render(hdc);

		_pNumbers[i]->render(hdc);
	}

	for (int i = 0; i < 3; i++)
	{

		_pPlayerFace[i]->render(hdc);
	}

	RECT temp = _pHpBar[1]->getRC();
	//Rectangle(hdc, temp);

	for (int i = 0; i < 2; i++)
	{
		_pHpBar[i]->render(hdc);

	}

	char str[12];
	sprintf_s(str, "%lf", _pHpBar[1]->getDamageWidth());
	TextOut(hdc, 400, 400, str, strlen(str));
}
