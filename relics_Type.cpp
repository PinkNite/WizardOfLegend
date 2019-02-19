#include "stdafx.h"
#include "relics_Type.h"



RELICS_TYPE::RELICS_TYPE()
	:_frameY(0)
{
}

RELICS_TYPE::~RELICS_TYPE()
{
}

HRESULT RELICS_TYPE::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsType", "resource/item/relicsType.bmp", 46, 128, 1, 3, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 46, 128);

	



	return S_OK;
}

void RELICS_TYPE::release()
{
	OBJECT::setImage(nullptr);
}

void RELICS_TYPE::update()
{

	
}

void RELICS_TYPE::render(HDC hdc)
{
	OBJECT::getImage()->frameRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(),0,_frameY);


}
