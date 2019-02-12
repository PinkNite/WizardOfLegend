#include "stdafx.h"
#include "statusUI.h"

STATUSUI::STATUSUI()
	:_num(0), _count(0)
{
}

STATUSUI::~STATUSUI()
{
}

HRESULT STATUSUI::init()
{

	IMAGEMANAGER->addImage("statusUI", "resource/UI/statusUI.bmp", 480, 724, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("statusUI"));
	OBJECT::init(51 + (2 * 51 + 2 * 2), 51 + 25, OBJECT::getImage()->GetWidth(), OBJECT::getImage()->GetHeight());

	_pStatusSelect = new STATUSSELECT;
	_pStatusSelect->init();

	for (int i = 0; i < 6; i++)
	{
		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(214 + i * 66, 150);
		
	}
	return S_OK;
}

void STATUSUI::release()
{
}

void STATUSUI::update()
{
	_pStatusSelect->update();
	for (int i = 0; i < 6; i++)
	{

		_pStatusBox[i]->update();
		//0,1,3알파값이 다름 원작
		if (_pStatusBox[i]->getFrameX()!=2&&_count!=1)
		{
			switch (i)
			{
			case 0:

				_pStatusBox[i]->setAlpha(100);
				break;
			case 1:
				_pStatusBox[i]->setAlpha(100);
				break;
			case 3:
				_pStatusBox[i]->setAlpha(100);
				break;
			}
		}
		else if(_count==1)
		{
			switch (i)
			{
			case 0:

				_pStatusBox[i]->setAlpha(255);
				break;
			case 1:
				_pStatusBox[i]->setAlpha(255);
				break;
			case 3:
				_pStatusBox[i]->setAlpha(255);
				break;
			}
		}
	}
	
	collision();
	spaceKeyAndLButton();
}

void STATUSUI::render(HDC hdc)
{

	OBJECT::getImage()->render(hdc,OBJECT::getPosX(),  OBJECT::getPosY());
	_pStatusSelect->render(hdc);
	for (int i = 0; i < 6; i++)
	{

	_pStatusBox[i]->render(hdc);
	}
	char str[222];
	for (int i = 0; i < 6; i++)
	{

	sprintf_s(str, "%d", _pStatusBox[i]->dd());
	TextOut(hdc, 500+i*20, 500, str, strlen(str));
	}
	sprintf_s(str, "%d", _count);
	TextOut(hdc, 700 , 500, str, strlen(str));
}

void STATUSUI::collision()
{
	RECT temp;
	for (int i = 0; i < 6; i++)
	{
		if (IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))
		{
			//충돌했다 
			
			_pStatusSelect->setIsCollision(true);//트루값
			_pStatusBox[i]->setIsCollision(true);
			
			
		}
		else if(!IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))
		{
			
			_pStatusBox[i]->setIsCollision(false);
			
		}
	}
}

void STATUSUI::spaceKeyAndLButton()
{
	if (KEYMANAGER->isToggleKey(VK_SPACE))//스페이스키가 눌리면
	{
		for (int i = 0; i < 6; i++)
		{
			if (_pStatusBox[i]->getIsCollision()&&_count==0)//한번만 들어오게하자
			{
				//충돌상태인데 눌리면 해당 박스값만 변화
				_pStatusBox[i]->setFrameX(2);//2번으로 변화하고
				_count = 1;
				
				break;
			}
		}

	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (_count==1&&_pStatusBox[i]->getFrameX())
			{
				//충돌상태인데 눌리면 해당 박스값만 변화 
				_pStatusBox[i]->setFrameX(0);//반대는 0
				_count = 0;
				break;
			}
		}
	}
}
