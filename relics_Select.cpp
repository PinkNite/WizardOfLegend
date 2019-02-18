#include "stdafx.h"
#include "relics_Select.h"



RELICS_SELECT::RELICS_SELECT()
{
}

RELICS_SELECT::~RELICS_SELECT()
{
}

HRESULT RELICS_SELECT::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsSelect", "resource/item/relicsAndBlack.bmp", 66, 132, 1, 2, true, RGB(255, 0, 255)));
	return S_OK;
}

void RELICS_SELECT::release()
{
}

void RELICS_SELECT::update()
{
}

void RELICS_SELECT::render(HDC hdc)
{
}
