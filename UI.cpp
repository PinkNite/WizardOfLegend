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
	_pSkillUI->render(hdc);
	_pStatusUI->render(hdc);
	
}
