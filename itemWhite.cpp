#include "stdafx.h"
#include "itemWhite.h"




ITEMWHITE::ITEMWHITE()
	:_x(0), _y(0), _isAction(0), _count(0)
{
}

ITEMWHITE::~ITEMWHITE()
{
}

HRESULT ITEMWHITE::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("itemWhite", "resource/item/itemWhite.bmp", 512, 192, 8, 3, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, 512, 192);
	_x = x;
	_y = y;
	KEYANIMANAGER->addObject("itemWhite1");
	int arr[] = {16,17,18,19};
	KEYANIMANAGER->addArrayFrameAnimation("itemWhite1", "itemAction", "itemWhite", arr, 4, 1, 1);
	_pAni = KEYANIMANAGER->findAnimation("itemWhite1", "itemAction");

	return S_OK;
}

void ITEMWHITE::release()
{
}

void ITEMWHITE::update()
{
	if (_isAction)
	{
		_count++;
		if (_count % 35 == 0)
		{
			_pAni->start();
			_count = 0;
		}
	}

}

void ITEMWHITE::render(HDC hdc)
{
	if (_isAction)
	{
		OBJECT::getImage()->aniRender(hdc, _x, _y, _pAni);
	}
}

