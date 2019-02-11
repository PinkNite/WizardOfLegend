#include "stdafx.h"
#include "UImanager.h"



UIMANAGER::UIMANAGER()
{
}

UIMANAGER::~UIMANAGER()
{
}

HRESULT UIMANAGER::init()
{
	_pSkillUI = new SKILLUI;
	_pSkillUI->init();
	_pStatusUI = new STATUSUI;
	_pStatusUI->init();
	
	return S_OK;
}

void UIMANAGER::release()
{
}

void UIMANAGER::update()
{
	_pSkillUI->update();
	_pStatusUI->update();
	
}

void UIMANAGER::render(HDC hdc)
{
	_pSkillUI->render(hdc);
	_pStatusUI->render(hdc);
	
}
