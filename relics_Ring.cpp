#include "stdafx.h"
#include "relics_Ring.h"




RELICS_RING::RELICS_RING()
{
}

RELICS_RING::~RELICS_RING()
{
}

HRESULT RELICS_RING::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsRing", "resource/item/relicsRing.bmp", 63, 290, 1, 4, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 63, 290);
	KEYANIMANAGER->addObject("ring");
	int arr[] = { 0,1,2,3 };
	
	KEYANIMANAGER->addArrayFrameAnimation("ring", "action", "relicsRing", arr, 4, 1, 0);
	_pAni = KEYANIMANAGER->findAnimation("ring", "action");

	return S_OK;
}

void RELICS_RING::release()
{
	OBJECT::setImage(nullptr);
}

void RELICS_RING::update()
{
	_pAni->start();
	KEYANIMANAGER->update();
}

void RELICS_RING::render(HDC hdc)
{
	OBJECT::getImage()->aniRender(hdc,OBJECT::getPosX(),OBJECT::getPosX(),_pAni);
}
