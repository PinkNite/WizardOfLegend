#include "stdafx.h"
#include "UI.h"



UI::UI()
	:_isClick(0),_HP(0),_MP(0)
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
	_pMpBar = new MPBAR;
	_pMpBar->init(40+65,50+33);
	_pMpBar->setRcWidth(0);
	_pPlayer = new PLAYER;
	_pPlayer->init();
	
	_HP = 500;//아직 안받는 값
	_damage = 100;
	return S_OK;
}

void UI::release()
{
}

void UI::update()
{
	//_HP = _pPlayer->getCurrentHp();
	
	
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

	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		_HP += _damage;
	}
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		_HP -= _damage;
	}
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		_MP +=10;
	}
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		_MP -= 10;
	}

	_pHpBar[1]->setGauge(_HP, _pPlayer->getMaxHp());
	_pHpBar[0]->setDamage(_HP, _pPlayer->getMaxHp());

	_pMpBar->setGauge(_MP, 100);


	for (int i = 0; i < 2; i++)
	{

		_pHpBar[i]->update();
	}
	_pMpBar->update();
}

void UI::render(HDC hdc)
{
	_pSkillUI->render(hdc);

	for (int i = 0; i < 3; i++)
	{

		_pPlayerFace[i]->render(hdc);
	}
	RECT tt;
	tt = _pHpBar[1]->getRC();
	for (int i = 0; i < 2; i++)
	{
		_pHpBar[i]->render(hdc);

	}
	//Rectangle(hdc, tt);
	_pMpBar->render(hdc);



	if (_isClick)
	{
		_pStatusUI->render(hdc);
	}
	for (int i = 0; i < 2; i++)
	{

		_pGoldHD[i]->render(hdc);

		_pNumbers[i]->render(hdc);
	}

	


	char str[12];
	sprintf_s(str, " %.2lf", _pHpBar[1]->getHP());
	TextOut(hdc, 400, 400, str, strlen(str));
}
