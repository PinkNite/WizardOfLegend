#include "stdafx.h"
#include "statusUI.h"
#include "item.h"

STATUSUI::STATUSUI()
	:_num(0), _numA(0), _count(0), _alpha(200), _isClick(0), _temp(0),_tempX(0)
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


	for (int i = 0; i < 6; i++)
	{
		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(214 + i * 66, 150);
		_pStatusBox[i]->setSkillXY(60 + (i * 60) + 3,WINSIZEY-90);
		_pStatusBox[i]->setPlayer(_pPlayer);
		switch (i)
		{
		case 5:
			_pStatusBox[i]->_pSkillIcon->setNum(i+1);
			break;
		default:
		_pStatusBox[i]->_pSkillIcon->setNum(i);
			break;
		}
		
		_pStatusBox[i]->setSkillNum(static_cast<SKILLNUMBER> (i));
		switch (i)
		{
		case 4:
			break;
		case 5:
			break;
		default:
			
			break;
		}

	}
	for (int i = 6; i < 7; i++)
	{
		_pStatusBox[i] = new STATUSBOX;
		_pStatusBox[i]->init(214, 333);
		_pStatusBox[i]->_pSkillIcon->setNum(10);

	}


	for (int i = 0; i < 2; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init();

		_pItem[i]->update();

		_pItem[i]->setX(214);
		_pItem[i]->setY(333);
		_pItem[i]->setNum(1);

	}
	_pExplainUse = new EXPLAINUSE;
	_pExplainUse->init(214, 200);

	
	//스왑용 템프박스
	_pTempBox = new STATUSBOX;
	_pTempSkill = new SKILLICON;
	for (int i = 0; i < 6; i++)
	{

		_pStatusButton[i] = new STATUSBUTTON;
		_pStatusButton[i]->init(220 + i * 66, 118);
		_pStatusButton[i]->setFrameX(i);
		
	}
	_pStatusSelect = new STATUSSELECT;
	_pStatusSelect->init();
	

	
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
		//_pStatusBox[i]->setX(214 + i * 66);
		_pStatusBox[i]->update();
		//바뀐 번호로 엑스좌표를 가져옴 
		
		
		//_pStatusBox[i]->setX()
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

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_numA++;
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		_numA--;
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{

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
		_pStatusBox[6]->render(hdc);
	}
	_pItem[0]->setNum(_numA);


	for (int i = 0; i < 1; i++)
	{
		_pItem[i]->render(hdc);
	}
	//아이템이 범위에 들어올때만
	if (_pStatusBox[6]->getIsItem())
	{
		fontRender(hdc, "[", "Aharoni", 214, 520, 40, RGB(183, 192, 195));
		fontRender(hdc, _pItem[0]->getVItem()[_numA].name, "Aharoni", 240, 530, 20, RGB(255, 204, 0));
		fontRender(hdc, "]", "Aharoni", _rcText.right, 520, 40, RGB(183, 192, 195));
		fontRender2(hdc, _pItem[0]->getVItem()[_numA].info, "Aharoni", 214, 560, 20, RGB(183, 192, 195));
	}
	

	_pExplainUse->render(hdc);

	for (int i = 0; i < 6; i++)
	{


		_pStatusButton[i]->render(hdc);
	}

	//char str[222];

	//for (int i = 0; i < 6; i++)
	//{

	//	//sprintf_s(str, "%d,%d", _pStatusBox[i]->getX(), _pStatusBox[i]->getY());
	//	//TextOut(hdc, _pStatusBox[i]->getX(), _pStatusBox[i]->getY(), str, strlen(str));

	//	sprintf_s(str, "%d", _pStatusBox[_pStatusBox[i]->getIndex()]->getX());
	//	TextOut(hdc, _pStatusBox[i]->getX(), _pStatusBox[i]->getY(), str, strlen(str));
	//}
	//sprintf_s(str, "선택엑스좌표:%d,선택상태값:%d", (int)_pStatusSelect->getPosX(), _pStatusSelect->getSelectState());
	//TextOut(hdc, 700, 400, str, strlen(str));
	//sprintf_s(str, "count :%d temp:%d frame: %d", _count, _temp, _pStatusBox[_temp]->getFrameX());
	//TextOut(hdc, 700, 100, str, strlen(str));
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
	for (int i = 6; i < 7; i++)
	{
		if (IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))//아이템과 셀렉트 박스랑 충돌이다.
		{
			_pStatusBox[i]->setIsItem(1);
		}
		else
		{
			_pStatusBox[i]->setIsItem(0);
		}
	}
}

void STATUSUI::spaceKeyAndLButton()
{

	for (int i = 0; i < 6; i++)
	{
		//스왑모드가 아닐때 충돌상태이고 해당박스와 키가 눌렸다 //카운트가 0일때만 들어오세요
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() != SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 0)
		{
			_pStatusSelect->setSelectState(SWAP_STATE);//스왑모드가 되고
			_pStatusBox[i]->setIsClick(true);//클릭상태만들어주고
			_pStatusBox[i]->setFrameX(2);//프레임 녹색으로 해주고 
			_count = 1;//일이됨
			_temp = i;
			break;//나옴
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() == SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 1 && _pStatusBox[i]->getFrameX() == 2)
		{
			// 녹색이미지이면 해당박스랑 충돌일때
			_pStatusSelect->setSelectState(SKILL_STATE);//스왑모드가 되고
			_pStatusBox[i]->setIsClick(false);//클릭상태만들어주고
			_pStatusBox[i]->setFrameX(0);//프레임 녹색으로 해주고 
			_count = 0;//0

			break;//나옴
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() == SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 1 && _pStatusBox[_temp]->getFrameX() == 2 && _temp != i)
		{
			//system("pause");
			//다른 박스랑 충돌할때
			//스왑
			_pStatusSelect->setSelectState(SKILL_STATE);//상태는 스킬
			_pStatusBox[_temp]->setIsClick(false);
			_pStatusBox[_temp]->setFrameX(0);//프레임 원래색
			_count = 0;//0
			//여기부터 스왑
			/*_pTempBox = _pStatusBox[_temp];
			_pTempBox->setX(_pStatusBox[_temp]->getX());
			

			_pStatusBox[_temp] = _pStatusBox[i];
			
			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());

			_pStatusBox[i] = _pTempBox;
			
			_pStatusBox[i]->setX(_pTempBox->getX());*/


			_pTempBox->setX(_pStatusBox[_temp]->getX());
			_pTempBox->setSkillX(_pStatusBox[_temp]->getSkillX());
			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());
			_pStatusBox[_temp]->setSkillX(_pStatusBox[i]->getSkillX());
			_pStatusBox[i]->setX(_pTempBox->getX());
			_pStatusBox[i]->setSkillX(_pTempBox->getSkillX());


			break;
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse)&& _pStatusSelect->getSelectState() != SWAP_STATE && _count == 0)
		{
			//system("pause");
			_pStatusSelect->setSelectState(SWAP_STATE);//스왑모드가 되고
			_pStatusBox[i]->setIsClick(true);//클릭상태만들어주고
			_pStatusBox[i]->setFrameX(2);//프레임 녹색으로 해주고 
			_count = 1;//일이됨
			_temp = i;
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left-3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top-2);
			break;//나옴
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse) && _pStatusSelect->getSelectState() == SWAP_STATE && _count == 1 && _pStatusBox[i]->getFrameX() == 2)
		{
			// 녹색이미지이면 해당박스랑 충돌일때
			//system("pause");
			_pStatusSelect->setSelectState(SKILL_STATE);//스왑모드가 되고
			_pStatusBox[i]->setIsClick(false);//클릭상태만들어주고
			_pStatusBox[i]->setFrameX(0);//프레임 녹색으로 해주고 
			_count = 0;//0
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left-3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top-2);
			break;//나옴
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse) && _pStatusSelect->getSelectState() == SWAP_STATE && _count == 1 && _pStatusBox[_temp]->getFrameX() == 2 && _temp != i)
		{
			//system("pause");
			//다른 박스랑 충돌할때
			//스왑
			_pStatusSelect->setSelectState(SKILL_STATE);//상태는 스킬
			_pStatusBox[_temp]->setIsClick(false);
			_pStatusBox[_temp]->setFrameX(0);//프레임 원래색
			_count = 0;//0
			//여기부터 스왑
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left-3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top-2);
		

		/*	_pTempBox = _pStatusBox[_temp];
			

			_pStatusBox[_temp] = _pStatusBox[i];
		

			_pStatusBox[i] = _pTempBox;*/

			_pTempBox->setX(_pStatusBox[_temp]->getX());
			_pTempBox->setSkillX(_pStatusBox[_temp]->getSkillX());
			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());
			_pStatusBox[_temp]->setSkillX(_pStatusBox[i]->getSkillX());
			_pStatusBox[i]->setX(_pTempBox->getX());
			_pStatusBox[i]->setSkillX(_pTempBox->getSkillX());
			
			break;
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
	//셀렉트의 좌표에 따른 상태값 변화
	switch ((int)_pStatusSelect->getPosX())
	{
	default:
		break;
	}

	for (int i = 0; i < 6; i++)
	{
		
		//_pStatusBox[i]->_pSkillIcon->move(_pStatusBox[i]->getX(), _pStatusBox[i]->getY());
	}
}

void STATUSUI::skillSetting()
{
}
