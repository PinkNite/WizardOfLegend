#include "stdafx.h"
#include "skillUI.h"
#include "item.h"
#include "itemManager.h"
#include "statusBox.h"



SKILLUI::SKILLUI()
: _numA(0),_frameX(1),_frameY(0)
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 120, 60, 2, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(OBJECT::getImage()->getFrameWidth(), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());

	//스탯박스 추가해서 그림
	_x = OBJECT::getImage()->getFrameWidth() + (6 * OBJECT::getImage()->getFrameWidth() + 12 + 36);
	_y = WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2 + 10;
	for (int i = 0; i < 2; i++)
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);

	}
	_pStatusBox[0]->setFrameX(1);

	for (int i = 0; i < 2; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init();

		_pItem[i]->update();
		
		_pItem[i]->setX(214);
		_pItem[i]->setY(333);
		_pItem[i]->setNum(1);
		switch (i)
		{
		case 1:
			_pItem[i]->setX(_x + ( 55));
			_pItem[i]->setY(_y);
			_pItem[i]->setNum(188);
			_pItem[i]->setAlpha(60);
			break;

		
		}
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
	
	
	
	}

	for (int i = 0; i < 2; i++)
	{

		
		_pStatusBox[i]->render(hdc);
	}

		_pItem[0]->setNum(_numA);
	for (int i = 0; i < 2; i++)
	{
	_pItem[i]->render(hdc);
	}



}
