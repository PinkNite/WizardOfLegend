#include "stdafx.h"
#include "relics_Cover.h"




RELICS_COVER::RELICS_COVER()
{
}

RELICS_COVER::~RELICS_COVER()
{
}

HRESULT RELICS_COVER::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsCover", "resource/item/relicsCover.bmp", 514, 701, 1, 5, true, RGB(255, 0, 255)));
	return S_OK;
}

void RELICS_COVER::release()
{
}

void RELICS_COVER::update()
{
}

void RELICS_COVER::render(HDC hdc)
{
}
