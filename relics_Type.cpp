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
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsType", "resource/item/relicsType.bmp", 201, 192, 1, 3, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 201, 192);

	KEYANIMANAGER->addObject("relicsTypeAny");
	KEYANIMANAGER->addDefaultFrameAnimation("relicsTypeAny", "relicsType2", "relicsType", 0.6f, 0, 1);


	_pAni = KEYANIMANAGER->findAnimation("relicsTypeAny", "relicsType2");

	return S_OK;
}

void RELICS_TYPE::release()
{
	_pAni = nullptr;
}

void RELICS_TYPE::update()
{
	_pAni->start();
	KEYANIMANAGER->update();
}

void RELICS_TYPE::render(HDC hdc)
{
	OBJECT::getImage()->aniRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _pAni);


}
