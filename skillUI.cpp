#include "stdafx.h"
#include "skillUI.h"
#include "itemManager.h"
#include "statusBox.h"
#include "skillButton.h"
#include "font.h"
#include "item.h"




SKILLUI::SKILLUI()
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	
	_pStatusUI = new STATUSUI;
	_pStatusUI->init();


	//스탯박스 추가해서 그림
	_x = 60 + (6 * 60 + 12 + 36);
	_y = WINSIZEY - 90 + 10;

	

	for (int i = 0; i < 2; i++)
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);
		_pStatusBox[i]->_pSkillIcon->setNum(10);

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



	_pItem = new ITEM;
	_pItem->init();

	_pItem->setX(_x + 55);
	_pItem->setY(_y);
	_pItem->setNum(188);
	_pItem->setAlpha(60);
	_pSkillIcon = new SKILLICON;
	_pSkillIcon->setSkillIcon();
	for (int i = 0; i < 6; i++)
	{
		_pSkillBox[i] = new SKILLBOX;
		
		switch (i)
		{
		case 0:
			
			_name = "0";
			break;
		case 1:
			_name = "1";
			break;
		case 2:
			_name = "2";
			break;
		case 3:
			_name = "3";
			break;
		case 4:
			_name = "4";
			break;
		case 5:
			_name = "5";
			break;
		}	
		

		//_pSkillBox[i]->init(60 + (i *60)+ 3, WINSIZEY - 90,_name,_pSkillIcon->getVSkillIcon()[i].coolDown);//이쪽수정필요

		_pSkillBox[i]->init(_pStatusUI->_pStatusBox[i]->getSkillX(), _pStatusUI->_pStatusBox[i]->getSkillY(), _name, _pSkillIcon->getVSkillIcon()[i].coolDown);//이쪽수정필요

		//_pSkillBox[i]->init(_pStatusUI->getPosX(), _pStatusUI->getPosY(), _name, _pSkillIcon->getVSkillIcon()[i].coolDown);//이쪽수정필요
		if (i == 3)
		{
			_pSkillBox[i]->setFrameX(0);
		}
		//_pSkillBox[i]->_pSkillIcon->setNum(_pStatusUI->_pStatusBox[i]->getSkillNum());
		_pSkillBox[i]->_pSkillIcon->setNum(_pStatusUI->_pStatusBox[i]->_pSkillIcon->getNum());
		
	}
	
	
	
	
	
	return S_OK;
}

void SKILLUI::release()
{
	
}

void SKILLUI::update()
{
	for (int i = 0; i < 6; i++)
	{
		_pSkillBox[i]->setX(_pStatusUI->_pStatusBox[i]->getSkillX());
		_pSkillBox[i]->setY(_pStatusUI->_pStatusBox[i]->getSkillY());
		_pSkillBox[i]->update();
		
		
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_pSkillBox[0]->setSkillUse(USE);

	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_pSkillBox[1]->setSkillUse(USE);

	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_pSkillBox[2]->setSkillUse(USE);

	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_pSkillBox[3]->setSkillUse(USE);

	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_pSkillBox[4]->setSkillUse(USE);

	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_pSkillBox[5]->setSkillUse(USE);

	}

	

}

void SKILLUI::render(HDC hdc)
{
	
	
	for (int i = 0; i < 6; i++)
	{
		
		_pSkillBox[i]->render(hdc);
		/*char str[200];

		sprintf_s(str, "%d", _pStatusUI->_pStatusBox[i]->getSkillX());
		TextOut(hdc, _pStatusUI->_pStatusBox[i]->getSkillX(), _pSkillBox[i]->getY()-50, str, strlen(str));*/

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
	
	_pItem->render(hdc);

	
	

}





 