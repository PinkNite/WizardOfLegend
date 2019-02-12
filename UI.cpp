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
		_pNumbers[i]->init(WINSIZEX / 2+25, WINSIZEY - 115 + i * 50);

	}
	_pGoldHD[1]->setFrameX(1);
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
}

void UI::render(HDC hdc)
{
	if (_isClick)
	{
		_pStatusUI->render(hdc);
	}
	_pSkillUI->render(hdc);
	for (int i = 0; i < 2; i++)
	{

		_pGoldHD[i]->render(hdc);
		
		_pNumbers[i]->render(hdc);
	}
}
