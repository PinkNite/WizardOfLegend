#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
#include "explainUse.h"	
#include "statusButton.h"
#include "skillIcon.h"



class PLAYER;
class ITEM;
class STATUSUI :public OBJECT
{
private:
	//�����̴� ���� �� �׸�
	//�ȿ� �ڽ��� ���� �׸���
	//����Ʈ �ڽ� ���� �׸��� 
	//���â ����
	PLAYER* _pPlayer;
	PLAYER* _pTemp;
	ITEM* _pItem[2];//2���� ���̹���
	EXPLAINUSE* _pExplainUse;
	//SKILLICON* _pSkillIcon[6];
	STATUSBUTTON* _pStatusButton[6];
	SKILLICON* _pTempSkill;
	int _num;//��ȭ��


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
	STATUSBOX* _pStatusBox[7];//�̰� �þ�� �������� �޾ƾ���
	STATUSBOX* _pTempBox;
	int _count;//����?
	STATUSSELECT* _pStatusSelect;

	STATUSUI();
	~STATUSUI();
	void setPlayer(PLAYER* p) { _pPlayer = p; }
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
	
	
};

