#include "stdafx.h"
#include "UI.h"



UI::UI()
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
	_pStatusUI->update();

}

void UI::render(HDC hdc)
{
	_pStatusUI->render(hdc);
	_pSkillUI->render(hdc);
	for (int i = 0; i < 2; i++)
	{

		_pGoldHD[i]->render(hdc);
	}
}
