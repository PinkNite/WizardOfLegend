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

	/*_pStatusUI = new STATUSUI;
	_pStatusUI->init();*/


	//스탯박스 추가해서 그림
	_x = 60 + (6 * 60 + 12 + 36);
	_y = WINSIZEY - 90 + 10;
	for (int i = 0; i < 6; i++)
	{
		/*_findX[i] = _pStatusUI->_pStatusBox[i]->getSkillX();
		_findY[i] = _pStatusUI->_pStatusBox[i]->getSkillY();*/
		_findX[i] = 60 + (i * 60) + 3;
		_findY[i] = WINSIZEY - 90;
	}
	for (int i = 0; i < 6; i++)
	{
		_findUpX[i] = 214 + i * 66;
		_findUpY[i] = 150;
		
	}
	//_pStatusBox[i]->setSkillXY(60 + (i * 60) + 3, WINSIZEY - 90);

	for (int i = 0; i < 2; i++)//탭과 지도
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);
		_pStatusBox[i]->_pSkillIcon->setNum(0);

	}
	_pStatusBox[0]->setFrameX(1);

	for (int i = 0; i < 8; i++)
	{
		_pSkillButton[i] = new SKILLBUTTON;
		_pSkillButton[i]->setFrameX(i);
		_pSkillButton[i]->init(60 + (i * 60 + 2 * i) + 10, WINSIZEY - 90 - 45);
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
	_pItem->init(_x + 55, _y);


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




		_pSkillBox[i]->init(_pStatusUI->_pStatusBox[i]->getSkillX(), _pStatusUI->_pStatusBox[i]->getSkillY(), _name, _pStatusUI->_pStatusBox[i]->_pSkillIcon->getVSkillIcon()[_pStatusUI->_pStatusBox[i]->_pSkillIcon->getNum()].coolDown);//이쪽수정필요


		if (i == 3)
		{
			_pSkillBox[i]->setFrameX(0);
		}

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
		//_pSkillBox[i]->_pSkillIcon->setNum(_pStatusUI->_pStatusBox[i]->_pSkillIcon->getNum());
		for (int j = 0; j < 10; j++)
		{
			if (_pStatusUI->_pStatusBox[j]->getX() == _findUpX[i])
			{
				_pSkillBox[i]->setX(_findX[i]);
				_pSkillBox[i]->setY(_findY[i]);
				_pSkillBox[i]->update();
			}
		}

	}
		
	
	//박스에 있는 스킬을 검사해서 해당 넘버로 초기화 해준다.
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			for (int j = 0; j < 10; j++)
			{
				if (_findUpX[i] == _pStatusUI->_pStatusBox[j]->getX())
				{
					_pSkillBox[i]->_pSkillIcon->setNum(_pStatusUI->_pStatusBox[j]->_pSkillIcon->getNum());
					//system("pause");
					break;
				}
			}
			
			break;

		case 1:
			break;
		case 2:
			break;
		case 3:
		
		case 4:
		
		case 5:
			for (int j = 0; j < 10; j++)
			{
				if (_findUpX[i] == _pStatusUI->_pStatusBox[j]->getX())
				{
					_pSkillBox[i]->_pSkillIcon->setNum(_pStatusUI->_pStatusBox[j]->_pSkillIcon->getNum());
					//system("pause");
					break;
				}
			}
			break;

		}
	
	}
	for (int i = 0; i < 6; i++)
	{
		if (_pSkillBox[i]->getX() >= 0)
		{
			if (_findX[i] == _pSkillBox[i]->getX())
			{
				break;
			}
			else
			{
				
				//안 같으면 
				_pSkillBox[i]->setX(_findX[i]);
				_pSkillBox[i]->_pSkillIcon->setX(_findX[i]+8);
				_index = i;
				break;
				
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[0])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[1])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[2])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[3])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[4])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pSkillBox[i]->getX() == _findX[5])
			{
				_pSkillBox[i]->setSkillUse(USE);
				break;
			}
		}
	}



}

void SKILLUI::render(HDC hdc)
{


	for (int i = 0; i < 6; i++)
	{

		_pSkillBox[i]->render(hdc);
		/*char str[200];

		sprintf_s(str, "%d", _pSkillBox[0]->_pSkillIcon->getNum());
		TextOut(hdc, 600, 600, str, strlen(str));*/

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





