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
	return S_OK;
}

void RELICS_RING::release()
{
}

void RELICS_RING::update()
{
}

void RELICS_RING::render(HDC hdc)
{
}
