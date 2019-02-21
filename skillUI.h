#pragma once
#include "object.h"
#include "skillBox.h"
#include "skillIcon.h"
#include "statusUI.h"
#include "player.h"
class ITEM;

class SKILLBUTTON;
class STATUSBOX;



class SKILLUI :public OBJECT
{
private:


	STATUSBOX* _pStatusBox[2];
	SKILLBUTTON* _pSkillButton[8];
	//FONT* _pFont[2];
	SKILLICON* _pSkillIcon;
	SKILLBOX* _pSkillBox[6];
	STATUSUI* _pStatusUI;
	int _x;
	int _y;

	ITEM* _pItem;//2���� ���̹���
	string _name;
	PLAYER* _pPlayer;

	//  �˻��� �� ��ǥ
	int _findX[6];
	int _findY[6];
	int _findUpX[6];
	int _findUpY[6];
	int _index; //�ε�����ȣ�� ã��
public:
	SKILLUI();
	~SKILLUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);


public:
	void setLinkUI(ITEM* item) { _pItem = item; }
	void setStatusUI(STATUSUI* ui) { _pStatusUI = ui; }
	void setLinkPlayer(PLAYER* p) { _pPlayer = p; }
};

