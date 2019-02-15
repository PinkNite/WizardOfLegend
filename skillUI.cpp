#include "stdafx.h"
#include "skillUI.h"
#include "itemManager.h"
#include "statusBox.h"
#include "skillButton.h"
#include "font.h"
#include "item.h"
#include "skillIcon.h"



SKILLUI::SKILLUI()
	: _frameX(1), _frameY(0)
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 180, 60, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pixelBlack", "resource/UI/coolDown.bmp", 60, 60, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));


	//스탯박스 추가해서 그림
	_x = OBJECT::getImage()->getFrameWidth() + (6 * OBJECT::getImage()->getFrameWidth() + 12 + 36);
	_y = WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2 + 10;
	for (int i = 0; i < 2; i++)
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);

	}
	_pStatusBox[0]->setFrameX(1);

	for (int i = 0; i < 8; i++)
	{
		_pSkillButton[i] = new SKILLBUTTON;
		_pSkillButton[i]->setFrameX(i);
		_pSkillButton[i]->init(OBJECT::getImage()->getFrameWidth() + (i* OBJECT::getImage()->getFrameWidth() + 2 * i) + 10, WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2 - 45);
		switch (i)//알파값도 조정해야됨
		{
		case 6:
			_pSkillButton[i]->init(WINSIZEX / 2 - 338, WINSIZEY - 130);
			_pSkillButton[i]->setAlpha(100);
			break;
		case 7:
			_pSkillButton[i]->init(WINSIZEX / 2 - 282, WINSIZEY - 130);
			_pSkillButton[i]->setAlpha(50);
			break;
		}
	}
	//폰트
	for (int i = 0; i < 2; i++)
	{
		_pFont[i] = new FONT;


		_pFont[i]->init(WINSIZEX / 2 - 332 + i * 54, WINSIZEY - 20);
	}
	_pFont[1]->setFrameX(1);


	_pItem = new ITEM;
	_pItem->init();

	_pItem->setX(_x + 55);
	_pItem->setY(_y);
	_pItem->setNum(188);
	_pItem->setAlpha(60);

	for (int i = 0; i < 6; i++)
	{
	_pSkillIcon[i] = new SKILLICON;
	_pSkillIcon[i]->init(OBJECT::getImage()->getFrameWidth() + (i* OBJECT::getImage()->getFrameWidth() + 3 * i)+8, WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2+8);

	}


	
	coolDownSetting();
	
	return S_OK;
}

void SKILLUI::release()
{
	OBJECT::setImage(nullptr);
}

void SKILLUI::update()
{
	coolDownUpdate();


}

void SKILLUI::render(HDC hdc)
{
	
	
	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 3:
			_frameX = 0;
			_frameY = 0;
			break;
		default:
			_frameX = 1;
			_frameY = 0;
			break;
		}
		OBJECT::getImage()->frameRender(hdc, OBJECT::getImage()->getFrameWidth() + (i* OBJECT::getImage()->getFrameWidth() + 3 * i), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, _frameX, _frameY);


		_pSkillIcon[i]->render(hdc);
		
		
		
	}

	

	for (int i = 0; i < 2; i++)
	{


		_pStatusBox[i]->render(hdc);
	}

	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 4:
			break;
		case 5:
			break;

		default:
			_pSkillButton[i]->render(hdc);
			break;
		}

	}
	for (int i = 0; i < 2; i++)
	{
		_pFont[i]->render(hdc);
	}
	_pItem->render(hdc);
	
	coolDownRender(hdc);
	
	
}

void SKILLUI::coolDownSetting()
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

void SKILLUI::coolDownUpdate()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 1:
				_poly[i].pos[j].x = cosf(_poly[i].angle[j]) * 40 + 30;
				_poly[i].pos[j].y = -sinf(_poly[i].angle[j]) * 40  + 30;
				break;
			case 2:
				_poly[i].pos[j].x = cosf(_poly[i].angle[j]) * 50 +30;
				_poly[i].pos[j].y = -sinf(_poly[i].angle[j]) * 50 +  30;
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
				_poly[i].angle[1]=PI / 2 + 0.06f;
				_poly[i].angle[2] = PI/2;
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

void SKILLUI::coolDownRender(HDC hdc)
{
	HPEN pen;
	HPEN oldPen;
	HBRUSH brush;
	HBRUSH oldBrush;
	for (int i = 0; i < 6; i++)
	{
		IMAGEMANAGER->findImage("pixelBlack")->alphaRender(hdc, 60+(i* 60 + 3 * i), WINSIZEY -90, 255);
		
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


 