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
	IMAGEMANAGER->addFrameImage("skillUI", "resource/image/skillUI.bmp", 102, 51, 2, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(OBJECT::getImage()->getFrameWidth(), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());
	return S_OK;
}

void UI::release()
{
	OBJECT::setImage(nullptr);
}

void UI::update()
{

}

void UI::render(HDC hdc)
{
	
	//OBJECT::getImage()->frameRender(hdc, 295, 95, 1, 0);
	for (int i = 0; i < 6; i++)
	{

	OBJECT::getImage()->frameRender(hdc, OBJECT::getImage()->getFrameWidth()+(i* OBJECT::getImage()->getFrameWidth()+2*i), WINSIZEY-OBJECT::getImage()->getFrameHeight()- OBJECT::getImage()->getFrameHeight()/2,1,0);
	}
}
