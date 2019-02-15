#include "stdafx.h"
#include "skillBox.h"



SKILLBOX::SKILLBOX()
:_frameX(0),_x(0),_y(0),_alpha(255)
{
}

SKILLBOX::~SKILLBOX()
{
}

HRESULT SKILLBOX::init(int x,int y)
{
	IMAGEMANAGER->addImage("pixelBlack", "resource/UI/coolDown.bmp", 60, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 180, 60, 3, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(x, y, 180, 60);
	_x = x;
	_y = y;
	return S_OK;
}

void SKILLBOX::release()
{
	OBJECT::setImage(nullptr);
}

void SKILLBOX::update()
{
}

void SKILLBOX::render(HDC hdc)
{
	
	OBJECT::getImage()->alphaFrameRender(hdc,_x,_y, _frameX, 0,_alpha);

}
void SKILLBOX::coolDownSetting()
{
	//픽셀 테스트용
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			_poly[i].pos[j].x = 30;//중점
			_poly[i].pos[j].y = 30;//중점

			switch (j)
			{
			case 1:

				_poly[i].angle[j] = PI / 2 - 0.06f;
				break;
			default:
				_poly[i].angle[j] = PI / 2;
				break;
			}
			_poly[i].isUse = UN_USE;
		}
	}
}

void SKILLBOX::coolDownUpdate()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 1:
				_poly[i].pos[j].x = cosf(_poly[i].angle[j]) * 40 + 30;
				_poly[i].pos[j].y = -sinf(_poly[i].angle[j]) * 40 + 30;
				break;
			case 2:
				_poly[i].pos[j].x = cosf(_poly[i].angle[j]) * 50 + 30;
				_poly[i].pos[j].y = -sinf(_poly[i].angle[j]) * 50 + 30;
				break;

			}

		}

	}

	//픽셀테스트용



	for (int i = 0; i < 6; i++)
	{
		switch (_poly[i].isUse)
		{
		case USE:
			_poly[i].angle[1] -= 0.06f;
			_poly[i].angle[2] -= 0.06f;
			break;
		case UN_USE:
			_poly[i].angle[1] = PI / 2 + 0.06f;
			_poly[i].angle[2] = PI / 2;
			break;
		}
		if (KEYMANAGER->isOnceKeyDown('1'))
		{
			_poly[1].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown('2'))
		{
			_poly[2].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown('3'))
		{
			_poly[3].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown('4'))
		{
			_poly[4].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown('5'))
		{
			_poly[5].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown('6'))
		{
			_poly[0].isUse = USE;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_poly[0].isUse = UN_USE;
		}

	}

}

void SKILLBOX::coolDownRender(HDC hdc)
{
	HPEN pen;
	HPEN oldPen;
	HBRUSH brush;
	HBRUSH oldBrush;
	for (int i = 0; i < 6; i++)
	{
		IMAGEMANAGER->findImage("pixelBlack")->alphaRender(hdc, 60 + (i * 60 + 3 * i), WINSIZEY - 90, 255);

		switch (_poly[i].isUse)
		{
		case USE:
			pen = CreatePen(PS_SOLID, 0, RGB(255, 0, 255));
			oldPen = (HPEN)SelectObject(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), pen);
			brush = CreateSolidBrush(RGB(255, 0, 255));
			oldBrush = (HBRUSH)SelectObject(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), brush);
			Polygon(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), _poly[i].pos, 4);


			SelectObject(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), oldBrush);
			DeleteObject(brush);
			SelectObject(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), oldPen);
			DeleteObject(pen);
			break;
		case UN_USE:
			_rc = RectMake(0, 0, 60, 60);
			brush = CreateSolidBrush(RGB(255, 255, 0));
			FillRect(IMAGEMANAGER->findImage("pixelBlack")->getMemDC(), &_rc, brush);
			break;
		}



	}


}
