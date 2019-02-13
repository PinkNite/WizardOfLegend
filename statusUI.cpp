#include "stdafx.h"
#include "statusUI.h"
#include "item.h"

STATUSUI::STATUSUI()
	:_num(0), _numA(0), _count(0), _alpha(200), _isClick(0)
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
	_pStatusBox[6] = new STATUSBOX;
	_pStatusBox[6]->init(214, 333);

	for (int i = 0; i < 2; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init();

		_pItem[i]->update();

		_pItem[i]->setX(214);
		_pItem[i]->setY(333);
		_pItem[i]->setNum(1);
		switch (i)
		{
		case 1:
			_pItem[i]->setX(_x + (55));
			_pItem[i]->setY(_y);
			_pItem[i]->setNum(188);
			_pItem[i]->setAlpha(60);
			break;


		}
	}
	_pExplainUse = new EXPLAINUSE;
	_pExplainUse->init(214, 200);
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
		if (_pStatusBox[i]->getFrameX() != 2 && _pStatusSelect->getSelectState() != SWAP_STATE)
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
		else if (_pStatusSelect->getSelectState() == SWAP_STATE)
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
	swapSetting();

	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		_numA++;
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		_numA--;
	}
	_pExplainUse->alphaPlus(_pStatusSelect->getAlpha());

}

void STATUSUI::render(HDC hdc)
{

	OBJECT::getImage()->alphaRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _alpha);
	_pStatusSelect->render(hdc);
	for (int i = 0; i < 6; i++)
	{

		_pStatusBox[i]->render(hdc);
	}
	if (_pStatusSelect->getSelectState() == ITEM_STATE)
	{
		_pStatusBox[6]->render(hdc);//이게 화면에 //여기에 스킬 이미지 배열로 
	}
	_pItem[0]->setNum(_numA);


	for (int i = 0; i < 2; i++)
	{
		_pItem[i]->render(hdc);
	}
	fontRender(hdc, "[", "Aharoni", 214, 520, 40, RGB(183, 192, 195));
	fontRender(hdc, _pItem[0]->getVItem()[_numA].name, "Aharoni", 240, 530, 20, RGB(255, 204, 0));
	fontRender(hdc, "]", "Aharoni", _rcText.right, 520, 40, RGB(183, 192, 195));
	fontRender2(hdc, _pItem[0]->getVItem()[_numA].info, "Aharoni", 214, 560, 20, RGB(183, 192, 195));

	_pExplainUse->render(hdc);



	//char str[222];
	//for (int i = 0; i < 7; i++)
	//{

	//sprintf_s(str, "%d", _pStatusBox[i]->dd());
	//TextOut(hdc, 500+i*20, 500, str, strlen(str));
	//}
	//sprintf_s(str, "%d", _count);
	//TextOut(hdc, 700 , 500, str, strlen(str));
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
		else if (!IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))
		{

			_pStatusBox[i]->setIsCollision(false);

		}
	}
}

void STATUSUI::spaceKeyAndLButton()
{
	for (int i = 0; i < 6; i++)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusBox[i]->getIsCollision())//스페이스키가 눌리면
		{
			if (_isClick)
			{
				_isClick = false;

			}
			else
			{
				_isClick = true;
			}

			break;

		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && _pStatusBox[i]->getIsCollision() && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse))
		{
			if (_isClick)
			{
				_isClick = false;

			}
			else
			{
				_isClick = true;
			}

			break;
		}


	}
	for (int i = 0; i < 6; i++)
	{


		if (_isClick)
		{
			if (_pStatusBox[i]->getIsCollision() && _pStatusSelect->getSelectState() != SWAP_STATE)//한번만 들어오게하자
			{
				//충돌상태인데 눌리면 해당 박스값만 변화
				_pStatusBox[i]->setFrameX(2);//2번으로 변화하고
				_pStatusSelect->setSelectState(SWAP_STATE);

				break;
			}
		}
		else
		{
			if (_pStatusSelect->getSelectState() == SWAP_STATE && _pStatusBox[i]->getFrameX())
			{
				//충돌상태인데 눌리면 해당 박스값만 변화 
				_pStatusBox[i]->setFrameX(0);//반대는 0
				_pStatusSelect->setSelectState(SKILL_STATE);
				break;
			}
		}
	}
}
void STATUSUI::fontRender(HDC hdc, const char * str, const char * str2, int x, int y, int num, COLORREF color)
{



	_rcText = RectMake(x, y, (strlen(str))*(num - 7), num);

	//Rectangle(hdc, _rcText);

	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);

	DrawText(hdc, TEXT(str), -1, &_rcText, DT_CENTER);
	SelectObject(hdc, oldfont);

	DeleteObject(font);


}

void STATUSUI::fontRender2(HDC hdc, const char * str, const char * str2, int x, int y, int num, COLORREF color)
{

	_rcText = RectMake(x, y, 360, 100);

	//Rectangle(hdc, _rcText);

	SetTextColor(hdc, color);
	HFONT font, oldfont;
	SetBkMode(hdc, TRANSPARENT);
	font = CreateFont(num, 0, 0, 0, 300, 0, 0, 0, DEFAULT_CHARSET, OUT_STRING_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH / FF_SWISS, TEXT(str2));
	oldfont = (HFONT)SelectObject(hdc, font);

	DrawText(hdc, TEXT(str), -1, &_rcText, DT_LEFT | DT_WORDBREAK);
	SelectObject(hdc, oldfont);

	DeleteObject(font);
}

void STATUSUI::swapSetting()
{
	switch (_pStatusSelect->getSelectState())
	{
	case SWAP_STATE:
		_pExplainUse->setFrameX(1);
		break;
	case ITEM_STATE:
		_pExplainUse->setFrameX(2);
		break;
	default:
		_pExplainUse->setFrameX(0);
		break;
	}

}
