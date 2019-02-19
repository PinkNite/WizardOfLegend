#include "stdafx.h"
#include "relics.h"

RELICS::RELICS()
{
}

RELICS::~RELICS()
{
}

HRESULT RELICS::init(int x, int y)
{
	_pHome = new RELICS_HOME;
	_pHome->init(x, y);
	_pHome->setFrameX(1);

	_point1.x = 0;
	_point1.y = 0;
	_point2.x = 0;
	_point2.y = 4;
	for (int i = 0; i < 3; i++)
	{
		_pCover[i] = new RELICS_COVER;
		_pCover[i]->init(x+64, y + 170+i*115);
		_pButton[i] = new button;
		
		switch (i)
		{
		case 0:
		_pButton[i]->init("relicsCover", x +64+ 293 - 23, y+170 + i * 115 + 21, _point1, _point2, bind(&RELICS::animaitionStart1, this));
		
			break;
		case 1:
			_pButton[i]->init("relicsCover", x + 64 + 293 - 23, y + 170 + i * 115 + 21, _point1, _point2, bind(&RELICS::animaitionStart2, this));
			_pCover[i]->_pType->setFrameY(1);
			break;
		case 2:
			_pButton[i]->init("relicsCover", x + 64 + 293 - 23, y + 170 + i * 115 + 21, _point1, _point2, bind(&RELICS::animaitionStart3, this));
			_pCover[i]->_pType->setFrameY(2);
			break;
		}

	}
	

	
	for (int i = 0; i < 2; i++)
	{

		_pSelect[i] = new RELICS_SELECT;
		_pSelect[i]->init(x, y+20);
	}
	
	
	return S_OK;
}

void RELICS::release()
{
}

void RELICS::update()
{
	
	for (int i = 0; i < 3; i++)
	{

	_pCover[i]->update();
	_pButton[i]->update();
	}
}

void RELICS::render(HDC hdc)
{
	//홈
	_pHome->render(hdc);
	//타이프들
	for (int i = 0; i < 3; i++)
	{
	_pCover[i]->render(hdc);

	}
	
	
	for (int i = 0; i < 2; i++)
	{
		_pSelect[i]->render(hdc);
	}
	
}

void RELICS::animaitionStart1()
{
	_pCover[0]->aniStart();
}

void RELICS::animaitionStart2()
{
	_pCover[1]->aniStart();
}

void RELICS::animaitionStart3()
{
	_pCover[2]->aniStart();
}

