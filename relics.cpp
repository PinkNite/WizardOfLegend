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
	for (int i = 0; i < 3; i++)
	{
		_pCover[i] = new RELICS_COVER;
		_pCover[i]->init(x+64, y + 60);

	}
	_pOffenceType = new RELICS_TYPE;
	_pOffenceType->init(x, y);
	_pDefenceType = new RELICS_TYPE;
	_pDefenceType->init(x, y+100);
	_pDefenceType->setFrameY(1);
	_pMISCType = new RELICS_TYPE;
	_pMISCType->init(x, y+200);
	_pMISCType->setFrameY(2);

	for (int i = 0; i < 6; i++)
	{
	_pRing[i] = new RELICS_RING;
	_pRing[i]->init(x+100, y);
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
	for (int i = 0; i < 6; i++)
	{
		_pRing[i]->update();
		
	}
	for (int i = 0; i < 3; i++)
	{

	_pCover[i]->update();
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
	_pOffenceType->render(hdc);
	_pDefenceType->render(hdc);
	_pMISCType->render(hdc);
	for (int i = 0; i < 6; i++)
	{
	_pRing[i]->render(hdc);

	}
	for (int i = 0; i < 2; i++)
	{
		_pSelect[i]->render(hdc);
	}
}
