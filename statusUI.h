#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
#include "explainUse.h"	
#include "statusButton.h"
#include "skillIcon.h"
#include "player.h"



class ITEM;
class STATUSUI :public OBJECT
{
public:
	//�����̴� ���� �� �׸�
	//�ȿ� �ڽ��� ���� �׸���
	//����Ʈ �ڽ� ���� �׸��� 
	//���â ����
	PLAYER* _pPlayer;

	STATUSBOX* _pStatusBox[7];
	STATUSBOX* _pTempBox;
	STATUSSELECT* _pStatusSelect;
	ITEM* _pItem[2];//2���� ���̹���
	EXPLAINUSE* _pExplainUse;
	//SKILLICON* _pSkillIcon[6];
	STATUSBUTTON* _pStatusButton[16];
	SKILLICON* _pTempSkill;
	int _num;//��ȭ��

	int _count;//����?

	int _numA;//������ ��ȣ

	int _x;
	int _y;
	
	int _alpha;
	RECT _rcText;

	bool _isClick;
	//���ҿ� ����
	int _temp;
	int _tempX;
	
	

public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void fontRender2(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void swapSetting();//������ �Ͽ���
	void skillSetting();//��ų ��� ������ ���� ���̳�? ��ų�� ��� ���������� �͵��� ó������ 
public:
	//������
	bool getIsClick() { return _isClick; }
	void setIsClick(SELECTSTATE num) { _pStatusSelect->setSelectState(num); }
	
	
	void setPlayer(PLAYER* p) { _pPlayer = p; }
};

