#include "stdafx.h"
#include "skillUI.h"
#include "itemManager.h"
#include "statusBox.h"
#include "skillButton.h"
#include "font.h"
#include "item.h"
#include "skillIcon.h"



SKILLUI::SKILLUI()
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	



	//스탯박스 추가해서 그림
	_x = 60 + (6 * 60 + 12 + 36);
	_y = WINSIZEY - 90 + 10;

	

	for (int i = 0; i < 2; i++)
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);

	}
	_pStatusBox[0]->setFrameX(1);

	for (int i = 0; i < 8; i++)
	{
		_pSkillButton[i] = new SKILLBUTTON;
		_pSkillButton[i]->setFrameX(i);
		_pSkillButton[i]->init(60 + (i* 60 + 2 * i) + 10, WINSIZEY - 90 - 45);
		switch (i)//알파값도 조정해야됨
		{
		case 6:
			_pSkillButton[i]->init(WINSIZEX / 2 - 338, WINSIZEY - 130);
			_pSkillButton[i]->setAlpha(100);
			break;
		case 7:
			_pSkillButton[i]->init(WINSIZEX / 2 - 282, WINSIZEY - 130);
			_pSkillButton[i]->setAlpha(50);
			break;
		}
	}
	//폰트
	for (int i = 0; i < 2; i++)
	{
		_pFont[i] = new FONT;


		_pFont[i]->init(WINSIZEX / 2 - 332 + i * 54, WINSIZEY - 20);
	}
	_pFont[1]->setFrameX(1);


	_pItem = new ITEM;
	_pItem->init();

	_pItem->setX(_x + 55);
	_pItem->setY(_y);
	_pItem->setNum(188);
	_pItem->setAlpha(60);

	for (int i = 0; i < 6; i++)
	{
		_pSkillBox[i] = new SKILLBOX;
		_pSkillBox[i]->init(60 + (i *60)+ 3, WINSIZEY - 90);
	_pSkillIcon[i] = new SKILLICON;
	_pSkillIcon[i]->init(60 + (i * 60) +8,WINSIZEY- 90+8);

	}


	
	
	
	return S_OK;
}

void SKILLUI::release()
{
	
}

void SKILLUI::update()
{
	


}

void SKILLUI::render(HDC hdc)
{
	
	
	for (int i = 0; i < 6; i++)
	{
		
		_pSkillBox[i]->render(hdc);
		_pSkillIcon[i]->render(hdc);
		
		
		
	}

	

	for (int i = 0; i < 2; i++)
	{


		_pStatusBox[i]->render(hdc);
	}

	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 4:
			break;
		case 5:
			break;

		default:
			_pSkillButton[i]->render(hdc);
			break;
		}

	}
	for (int i = 0; i < 2; i++)
	{
		_pFont[i]->render(hdc);
	}
	_pItem->render(hdc);
	
	
	
	
}



 