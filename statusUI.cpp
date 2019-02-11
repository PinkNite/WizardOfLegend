#include "stdafx.h"
#include "statusUI.h"

STATUSUI::STATUSUI()
	:_num(0)
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

	for (int i = 0; i < 6; i++)
	{
	_pStatusBox[i] = new STATUSBOX;
	_pStatusBox[i]->init(214+i*66,150);

	}
	return S_OK;
}

void STATUSUI::release()
{
}

void STATUSUI::update()
{
	_pStatusSelect->update();
	for (int i = 0; i < 6; i++)
	{

	_pStatusBox[i]->update();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_num++;
		if (_num > 4)
		{
			_num = 0;
		}
		_pStatusBox[0]->setFrameX(_num);
	}
}

void STATUSUI::render(HDC hdc)
{

	OBJECT::getImage()->render(hdc,OBJECT::getPosX(),  OBJECT::getPosY());
	_pStatusSelect->render(hdc);
	for (int i = 0; i < 6; i++)
	{

	_pStatusBox[i]->render(hdc);
	}
}
