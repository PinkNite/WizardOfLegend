#include "stdafx.h"
#include "relics_Cover.h"




RELICS_COVER::RELICS_COVER()
	:_frameY(0),_alpha(255)
{
}

RELICS_COVER::~RELICS_COVER()
{
}

HRESULT RELICS_COVER::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsCover", "resource/item/relicsCover.bmp", 514, 701, 1, 5, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 514, 701);
	int arr[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addObject("cover1");
	KEYANIMANAGER->addArrayFrameAnimation("cover1", "action", "relicsCover", arr, 5, 1, 0);
	_pAni = KEYANIMANAGER->findAnimation("cover1","action");
	//_pAni->start();
	
	return S_OK;
}

void RELICS_COVER::release()
{
	OBJECT::setImage(nullptr);
}

void RELICS_COVER::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		_pAni->start();
	}
	KEYANIMANAGER->update();
}

void RELICS_COVER::render(HDC hdc)
{
	OBJECT::getImage()->aniRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(),_pAni);
	
}
