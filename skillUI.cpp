#include "stdafx.h"
#include "skillUI.h"
#include "itemManager.h"
#include "statusBox.h"



SKILLUI::SKILLUI()
	: _frameX(1), _frameY(0)
{
}


SKILLUI::~SKILLUI()
{
}

HRESULT SKILLUI::init()
{
	IMAGEMANAGER->addFrameImage("skillUI", "resource/UI/skillUI.bmp", 120, 60, 2, 1, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("skillUI"));
	OBJECT::init(OBJECT::getImage()->getFrameWidth(), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());

	//���ȹڽ� �߰��ؼ� �׸�
	_x = OBJECT::getImage()->getFrameWidth() + (6 * OBJECT::getImage()->getFrameWidth() + 12 + 36);
	_y = WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2 + 10;
	for (int i = 0; i < 2; i++)
	{

		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(_x + (i * 55), _y);
		_pStatusBox[i]->setAlpha(60);

	}
	_pStatusBox[0]->setFrameX(1);

	

	return S_OK;
}

void SKILLUI::release()
{
	OBJECT::setImage(nullptr);
}

void SKILLUI::update()
{
	


}

void SKILLUI::render(HDC hdc)
{

	//OBJECT::getImage()->frameRender(hdc, 295, 95, 1, 0);
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
		OBJECT::getImage()->frameRender(hdc, OBJECT::getImage()->getFrameWidth() + (i* OBJECT::getImage()->getFrameWidth() + 2 * i), WINSIZEY - OBJECT::getImage()->getFrameHeight() - OBJECT::getImage()->getFrameHeight() / 2, _frameX, _frameY);



	}

	for (int i = 0; i < 2; i++)
	{


		_pStatusBox[i]->render(hdc);
	}

	

}


