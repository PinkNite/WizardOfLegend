#include "stdafx.h"
#include "introScene.h"




INTROSCENE::INTROSCENE()

{
}

INTROSCENE::~INTROSCENE()
{
}

HRESULT INTROSCENE::init()
{




	ShowCursor(false);
	imageSetting();
	_pOpening = new OPENING;
	_pOpening->init();
	return S_OK;
}

void INTROSCENE::release()
{

	_pMouse = nullptr;
}

void INTROSCENE::update()
{
	_pOpening->update();

}

void INTROSCENE::render()
{
	_pOpening->render(getMemDC());
	_pMouse->render(getMemDC(), _ptMouse.x - 32, _ptMouse.y - 32);
}

void INTROSCENE::imageSetting()
{

	_pMouse = new image;
	_pMouse = IMAGEMANAGER->addImage("mouse", "resource/intro/mouseCursor.bmp", 64, 64, true, RGB(255, 0, 255));

}


