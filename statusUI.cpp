#include "stdafx.h"
#include "statusUI.h"

#include "player.h"

STATUSUI::STATUSUI()
	:_num(0), _numA(0), _count(0), _alpha(200), _isClick(0), _temp(0), _tempX(0)
{
}

STATUSUI::~STATUSUI()
{
}

HRESULT STATUSUI::init()
{
	_pTemp = new PLAYER;
	_pTemp->init();

	IMAGEMANAGER->addImage("statusUI", "resource/UI/statusUI.bmp", 480, 724, true, RGB(255, 0, 255));
	OBJECT::setImage(IMAGEMANAGER->findImage("statusUI"));
	OBJECT::init(51 + (2 * 51 + 2 * 2), 51 + 25, OBJECT::getImage()->GetWidth(), OBJECT::getImage()->GetHeight());


	for (int i = 0; i < 10; i++)
	{
		_pStatusBox[i] = new STATUSBOX;
		switch (i)
		{
		case 0:case 1: case 2: case 3: case 4: case 5:
			_pStatusBox[i]->init(214 + i * 66, 150);
			_pStatusBox[i]->setSkillXY(60 + (i * 60) + 3, WINSIZEY - 90);
			break;
		default:
			_pStatusBox[i]->init(130 + i * 50, 210);
			break;
		}


		switch (i)
		{
		case 0:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::LBUTTON)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::LBUTTON)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (0));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (0), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[0]->getSkillName()));


			break;
		case 1:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_SPACE)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_SPACE)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (5));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (5), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[1]->getSkillName()));

			break;
		case 2:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (1));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (1), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[2]->getSkillName()));

			break;

		case 3:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (2));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (2), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[3]->getSkillName()));

			break;
		case 4:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (3));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (3), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[4]->getSkillName()));

			break;
		case 5:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R)));
			_pStatusBox[i]->setSkillName(static_cast<int> (_pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R)));
			_pStatusBox[i]->setSkillNum(static_cast<int> (4));
			_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (4), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[5]->getSkillName()));
			//_pStatusBox[i]->_pSkillIcon->setNum(6);
			break;
		case 6:
			_pStatusBox[i]->_pSkillIcon->setNum(2);// ������
			_pStatusBox[i]->setSkillName(static_cast<int> (2));
			break;
		case 7:
			_pStatusBox[i]->_pSkillIcon->setNum(8);//����Ⱦ��?
			_pStatusBox[i]->setSkillName(static_cast<int> (8));
			break;

		default:
			_pStatusBox[i]->_pSkillIcon->setNum(0);//���̹���
			_pStatusBox[i]->setFrameX(1);
			break;
		}




	}
	for (int i = 0; i < 12; i++)//�ӽ� ������ ����
	{

		_pItemBox[i] = new STATUSBOX;
		_pItemBox[i]->init(214 + (i % 6) * 66, 333 + (i / 6) * 60);
		_pItemBox[i]->_pSkillIcon->setNum(0);// �ƹ��͵� ����


	}


	/*for (int i = 0; i < 2; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init();



		_pItem[i]->setX(214);
		_pItem[i]->setY(333);
		_pItem[i]->setNum(1);


	}*/
	_pExplainUse = new EXPLAINUSE;
	_pExplainUse->init(214, 200);


	//���ҿ� �����ڽ�
	_pTempBox = new STATUSBOX;
	_pTempBox->init(50, 50);
	_pTempSkill = new SKILLICON;
	for (int i = 0; i < 6; i++)
	{

		_pStatusButton[i] = new STATUSBUTTON;
		_pStatusButton[i]->init(220 + i * 66, 118);
		_pStatusButton[i]->setFrameX(i);

	}
	_pStatusSelect = new STATUSSELECT;
	_pStatusSelect->init();

	for (int i = 0; i < 12; i++)
	{
		_pItem[i] = new ITEM;
		_pItem[i]->init(214 + (i % 6) * 66, 333 + (i / 6) * 60);
		_pItem[i]->setNum(0);
		_pItem[i]->setItemWhiteAction(1);
	}



	return S_OK;
}

void STATUSUI::release()
{
}

void STATUSUI::update()
{

	for (int i = 0; i < 6; i++)
	{
		switch (i)
		{
		case 0:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_0);
			break;
		case 1:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_1);
			break;
		case 2:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_2);
			break;

		case 3:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_3);
			break;
		case 4:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_4);
			break;
		case 5:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			//_pStatusBox[i]->setSkillNum(SKILL_5);
			//_pStatusBox[i]->_pSkillIcon->setNum(6);
			break;
		default:
			_pStatusBox[i]->_pSkillIcon->setNum(static_cast<int> (_pStatusBox[i]->getSkillName()));
			break;
		}
	}

	_pStatusSelect->update();
	for (int i = 0; i < 6; i++)
	{
		//_pStatusBox[i]->setX(214 + i * 66);
		_pStatusBox[i]->update();
		//�ٲ� ��ȣ�� ������ǥ�� ������ 


		//_pStatusBox[i]->setX()
		//0,1,3���İ��� �ٸ� ����
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

	_pExplainUse->alphaPlus(_pStatusSelect->getAlpha());
	_pTempBox->update();
	for (int i = 0; i < 12; i++)
	{
		_pItem[i]->update();
	}
}

void STATUSUI::render(HDC hdc)
{

	OBJECT::getImage()->alphaRender(hdc, OBJECT::getPosX(), OBJECT::getPosY(), _alpha);
	_pStatusSelect->render(hdc);
	for (int i = 0; i < 10; i++)
	{

		_pStatusBox[i]->render(hdc);



	}
	for (int i = 0; i < 12; i++)
	{
		if (_pStatusSelect->getSelectState() == ITEM_STATE && _pItemBox[i]->getIsItem() == 1)
		{
			_pItemBox[i]->render(hdc);




			fontRender(hdc, "[", "Aharoni", 214, 520, 40, RGB(183, 192, 195));
			fontRender(hdc, _pItem[i]->getVItem()[_pItem[i]->getNum()].name, "Aharoni", 240, 530, 20, RGB(255, 204, 0));
			fontRender(hdc, "]", "Aharoni", _rcText.right, 520, 40, RGB(183, 192, 195));
			fontRender2(hdc, _pItem[i]->getVItem()[_pItem[i]->getNum()].info, "Aharoni", 214, 560, 20, RGB(183, 192, 195));
			break;

		}
	}
	//_pItem[0]->setNum(_numA);

	for (int i = 0; i < 12; i++)
	{
		_pItem[i]->render(hdc);
	}
	//for (int i = 0; i < 1; i++)
	//{
	//	_pItem[i]->render(hdc);
	//}
	//�������� ������ ���ö���



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
	//	
	//	sprintf_s(str, "%d", _pStatusBox[i]->getSkillNum());
	//	TextOut(hdc, 500 + i * 50, 500, str, strlen(str));
	//	sprintf_s(str, "%d", _pStatusBox[i]->getSkillName());
	//	TextOut(hdc, 500 + i * 50, 400, str, strlen(str));
	//	
	//}
	//	sprintf_s(str, "0, %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::LBUTTON));
	//	TextOut(hdc, 400, 700, str, strlen(str));
	//	sprintf_s(str, "1,  %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_SPACE));
	//	TextOut(hdc,450, 700, str, strlen(str));
	//	sprintf_s(str, "2, %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::RBUTTON));
	//	TextOut(hdc, 500, 700, str, strlen(str));
	//	sprintf_s(str, "3,  %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_Q));
	//	TextOut(hdc, 550, 700, str, strlen(str));
	//	sprintf_s(str, "4,  %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_E));
	//	TextOut(hdc, 600, 700, str, strlen(str));
	//	sprintf_s(str, "5, %d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::BTN_R));
	//	TextOut(hdc, 650, 700, str, strlen(str));
	//sprintf_s(str, "%d", _pPlayer->getCurrentSkill(PLAYER::SKILL_KEY::LBUTTON));
	//TextOut(hdc, 900, 700, str, strlen(str));
	//sprintf_s(str, "���ÿ�����ǥ:%d,���û��°�:%d", (int)_pStatusSelect->getPosX(), _pStatusSelect->getSelectState());
	//TextOut(hdc, 700, 400, str, strlen(str));
	//sprintf_s(str, "count :%d temp:%d frame: %d", _count, _temp, _pStatusBox[_temp]->getFrameX());
	//TextOut(hdc, 700, 100, str, strlen(str));


}

void STATUSUI::collision()
{
	RECT temp;
	for (int i = 0; i < 10; i++)
	{
		if (IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))
		{
			//�浹�ߴ� 

			_pStatusSelect->setIsCollision(true);//Ʈ�簪
			_pStatusBox[i]->setIsCollision(true);



		}
		else if (!IntersectRect(&temp, &_pStatusSelect->getRC(), &_pStatusBox[i]->getRC()))
		{

			_pStatusBox[i]->setIsCollision(false);


		}

	}

	//�̰� �ٽ� �ؾߵ�

	for (int i = 0; i < 12; i++)
	{
		if (IntersectRect(&temp, &_pStatusSelect->getRC(), &_pItemBox[i]->getRC()))//�����۰� ����Ʈ �ڽ��� �浹�̴�.
		{
			_pItemBox[i]->setIsItem(1);
			//break;
		}
		else
		{
			_pItemBox[i]->setIsItem(0);
			//break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		for (int i = 0; i < 12; i++)
		{
			if (_pItemBox[i]->getIsItem())
			{
				_pItem[i]->setIsDrop(1);

			}
		}
	}
}

void STATUSUI::spaceKeyAndLButton()
{

	for (int i = 0; i < 10; i++)
	{
		//���Ҹ�尡 �ƴҶ� �浹�����̰� �ش�ڽ��� Ű�� ���ȴ� //ī��Ʈ�� 0�϶��� ��������
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() != SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 0)
		{
			_pStatusSelect->setSelectState(SWAP_STATE);//���Ҹ�尡 �ǰ�
			_pStatusBox[i]->setIsClick(true);//Ŭ�����¸�����ְ�
			_pStatusBox[i]->setFrameX(2);//������ ������� ���ְ� 
			_count = 1;//���̵�
			_temp = i;
			break;//����
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() == SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 1 && _pStatusBox[i]->getFrameX() == 2)
		{
			// ����̹����̸� �ش�ڽ��� �浹�϶�
			_pStatusSelect->setSelectState(SKILL_STATE);//���Ҹ�尡 �ǰ�
			_pStatusBox[i]->setIsClick(false);//Ŭ�����¸�����ְ�
			_pStatusBox[i]->setFrameX(0);//������ ������� ���ְ� 
			_count = 0;//0

			break;//����
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _pStatusSelect->getSelectState() == SWAP_STATE && _pStatusBox[i]->getIsCollision() && _count == 1 && _pStatusBox[_temp]->getFrameX() == 2 && _temp != i)
		{
			//system("pause");
			//�ٸ� �ڽ��� �浹�Ҷ�
			//����
			_pStatusSelect->setSelectState(SKILL_STATE);//���´� ��ų
			_pStatusBox[_temp]->setIsClick(false);
			_pStatusBox[_temp]->setFrameX(0);//������ ������
			_count = 0;//0
			//������� ����
			/*_pTempBox = _pStatusBox[_temp];
			_pTempBox->setX(_pStatusBox[_temp]->getX());


			_pStatusBox[_temp] = _pStatusBox[i];

			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());

			_pStatusBox[i] = _pTempBox;

			_pStatusBox[i]->setX(_pTempBox->getX());*/

			_pTempBox->setX(_pStatusBox[_temp]->getX());
			_pTempBox->setSkillX(_pStatusBox[_temp]->getSkillX());

			_pTempBox->setSkillNum(_pStatusBox[_temp]->getSkillNum());
			//_pTempBox->setSkillName(_pStatusBox[_temp]->getSkillName());

			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());
			_pStatusBox[_temp]->setSkillX(_pStatusBox[i]->getSkillX());

			_pStatusBox[_temp]->setSkillNum(_pStatusBox[i]->getSkillNum());
			//_pStatusBox[_temp]->setSkillName(_pStatusBox[i]->getSkillName());



			_pStatusBox[i]->setX(_pTempBox->getX());
			_pStatusBox[i]->setSkillX(_pTempBox->getSkillX());

			_pStatusBox[i]->setSkillNum(_pTempBox->getSkillNum());
			//_pStatusBox[i]->setSkillName(_pTempBox->getSkillName());
			//�ش罺ų ��ȣ�� �����ϰ� �� ��ų ��ȣ�� ���� ��ų ��ư�� ������Ʈ �ȴ�.

			break;
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse) && _pStatusSelect->getSelectState() != SWAP_STATE && _count == 0)
		{
			//system("pause");
			_pStatusSelect->setSelectState(SWAP_STATE);//���Ҹ�尡 �ǰ�
			_pStatusBox[i]->setIsClick(true);//Ŭ�����¸�����ְ�
			_pStatusBox[i]->setFrameX(2);//������ ������� ���ְ� 
			_count = 1;//���̵�
			_temp = i;
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left - 3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top - 2);
			break;//����
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse) && _pStatusSelect->getSelectState() == SWAP_STATE && _count == 1 && _pStatusBox[i]->getFrameX() == 2)
		{
			// ����̹����̸� �ش�ڽ��� �浹�϶�
			//system("pause");
			_pStatusSelect->setSelectState(SKILL_STATE);//���Ҹ�尡 �ǰ�
			_pStatusBox[i]->setIsClick(false);//Ŭ�����¸�����ְ�
			_pStatusBox[i]->setFrameX(0);//������ ������� ���ְ� 
			_count = 0;//0
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left - 3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top - 2);
			break;//����
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && PtInRect(&_pStatusBox[i]->getRC(), _ptMouse) && _pStatusSelect->getSelectState() == SWAP_STATE && _count == 1 && _pStatusBox[_temp]->getFrameX() == 2 && _temp != i)
		{
			//system("pause");
			//�ٸ� �ڽ��� �浹�Ҷ�
			//����
			_pStatusSelect->setSelectState(SKILL_STATE);//���´� ��ų
			_pStatusBox[_temp]->setIsClick(false);
			_pStatusBox[_temp]->setFrameX(0);//������ ������
			_count = 0;//0
			//������� ����
			_pStatusSelect->setX(_pStatusBox[i]->getRC().left - 3);
			_pStatusSelect->setY(_pStatusBox[i]->getRC().top - 2);


			/*	_pTempBox = _pStatusBox[_temp];


				_pStatusBox[_temp] = _pStatusBox[i];


				_pStatusBox[i] = _pTempBox;*/

				//int tempSkillNum, tempSkillName;
				////int iSkillNum, iSkillName;
			_pTempBox->setX(_pStatusBox[_temp]->getX());
			_pTempBox->setSkillX(_pStatusBox[_temp]->getSkillX());

			_pTempBox->setSkillNum(_pStatusBox[_temp]->getSkillNum());
			//_pTempBox->setSkillName(_pStatusBox[_temp]->getSkillName());

			_pStatusBox[_temp]->setX(_pStatusBox[i]->getX());
			_pStatusBox[_temp]->setSkillX(_pStatusBox[i]->getSkillX());

			_pStatusBox[_temp]->setSkillNum(_pStatusBox[i]->getSkillNum());
			//_pStatusBox[_temp]->setSkillName(_pStatusBox[i]->getSkillName());



			_pStatusBox[i]->setX(_pTempBox->getX());
			_pStatusBox[i]->setSkillX(_pTempBox->getSkillX());

			_pStatusBox[i]->setSkillNum(_pTempBox->getSkillNum());
			//_pStatusBox[i]->setSkillName(_pTempBox->getSkillName());




			break;
		}
	}


	for (int i = 0; i < 6; i++)
	{
		_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY>(_pStatusBox[i]->getSkillNum()), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[i]->getSkillName()));
		//_pPlayer->setCurrentSkill(static_cast<PLAYER::SKILL_KEY> (0), static_cast<PLAYER::SKILL_NAME> (_pStatusBox[0]->getSkillName()));
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
	//����Ʈ�� ��ǥ�� ���� ���°� ��ȭ
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
