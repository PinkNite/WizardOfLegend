#include "stdafx.h"
#include "relics_Cover.h"




RELICS_COVER::RELICS_COVER()
	:_frameY(0),_alpha(255),_y(0)
{
}

RELICS_COVER::~RELICS_COVER()
{
}

HRESULT RELICS_COVER::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("relicsCover", "resource/item/relicsCover.bmp", 586, 799, 1, 5, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 586, 799);
	int arr[] = { 0,1,2,3,4 };
	KEYANIMANAGER->addObject("cover1");
	KEYANIMANAGER->addArrayFrameAnimation("cover1", "action", "relicsCover", arr, 5, 1, 0);
	_pAni = KEYANIMANAGER->findAnimation("cover1","action");
	//_pAni->start();
	for (int i = 0; i < 2; i++)
	{
		_pRing[i] = new RELICS_RING;
		_pRing[i]->init(x + 500, y);
	}
	_pType = new RELICS_TYPE;
	_pType->init(x+293-23, y+20);
	_y = y;
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

	for (int i = 0; i < 2; i++)
	{
		_pRing[i]->update();

	}

	KEYANIMANAGER->update();
	pixelCollision();
}

void RELICS_COVER::render(HDC hdc)
{
	OBJECT::getImage()->aniRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(),_pAni);
	for (int i = 0; i < 2; i++)
	{
		_pRing[i]->render(hdc);

	}
	_pType->render(hdc);
	
}

void RELICS_COVER::pixelCollision()
{

	//자물쇠 링이랑 숫자 타이프 이미지를 애니메이션동안 내릴수 있게 
	
	for (int i = _pType->getPosY()-9; i < _pType->getPosY(); i++)
	{
		
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("relicsCover")->getMemDC(), _pType->getPosX(), i);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		if (r == 67 && g == 58 && b == 42)
		{
			_pType->setPosY(i+20);
			//system("pause");
			break;
		}
	}
	/*if (_pType->getPosY() > _y)
	{
		_y--;
		_pType->setPosY(_y);
	}*/

}
