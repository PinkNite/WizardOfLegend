#include "stdafx.h"
#include "skillUI.h"
#include "item.h"
#include "itemManager.h"



SKILLUI::SKILLUI()
: _numA(0),_frameX(1),_frameY(0)
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 102, 51, 2, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(OBJECT::getImage()->getFrameWidth(), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());


	for (int i = 0; i < 6; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init();

		_pItem[i]->update();
		_pItem[i]->setX(OBJECT::getImage()->getFrameWidth() + (i* OBJECT::getImage()->getFrameWidth() + 2 * i) + 5);
		_pItem[i]->setY(WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2 + 5);
		_pItem[i]->setNum(1);
	}
	
	return S_OK;
}

void SKILLUI::release()
{
	OBJECT::setImage(nullptr);
}

void SKILLUI::update()
{
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_numA++;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_numA--;
	}
	
	
}
 
void SKILLUI::render(HDC hdc)
{
	
	//OBJECT::getImage()->frameRender(hdc, 295, 95, 1, 0);
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 3:
			_frameX = 0;
			_frameY = 0;
			break;
		default:
			_frameX = 1;
			_frameY = 0;
			break;
		}
			OBJECT::getImage()->frameRender(hdc, OBJECT::getImage()->getFrameWidth()+(i* OBJECT::getImage()->getFrameWidth()+2*i), WINSIZEY-OBJECT::getImage()->getFrameHeight()- OBJECT::getImage()->getFrameHeight()/2,_frameX,_frameY);
	
	
	
	_pItem[i]->render(hdc);
	}


}
