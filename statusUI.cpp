#include "stdafx.h"
#include "statusUI.h"

STATUSUI::STATUSUI()
{
}

STATUSUI::~STATUSUI()
{
}

HRESULT STATUSUI::init()
{

	IMAGEMANAGER->addImage("statusUI", "resource/UI/statusUI.bmp", 480, 724, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("statusUI"));
	OBJECT::init(51 + (2 * 51 + 2 * 2), 51 + 25, OBJECT::getImage()->GetWidth(), OBJECT::getImage()->GetHeight());

	_pStatusSelect = new STATUSSELECT;
	_pStatusSelect->init();
	return S_OK;
}

void STATUSUI::release()
{
}

void STATUSUI::update()
{
	_pStatusSelect->update();
	
}

void STATUSUI::render(HDC hdc)
{

	OBJECT::getImage()->render(hdc,OBJECT::getPosX(),  OBJECT::getPosY());
	_pStatusSelect->render(hdc);
}
