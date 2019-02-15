#pragma once
#include "object.h"

enum SKILLUSE
{
	USE,
	UN_USE
	//�׽�Ʈ�� �̳ѹ� ����� ����� ���� 
	//�÷��̾ų��� �޾ƿ������� �� �̳ѹ���
};


class ITEM;
class FONT;
class SKILLBUTTON;
class STATUSBOX;
class SKILLICON;
struct TAGPOLY //�ٰ��� ����ü
{
	float angle[4];
	POINT pos[4];
	SKILLUSE isUse;
};
class SKILLUI :public OBJECT
{
private:


	STATUSBOX* _pStatusBox[2];
	SKILLBUTTON* _pSkillButton[8];
	FONT* _pFont[2];
	SKILLICON* _pSkillIcon[6];
	int _frameX;
	int _frameY;
	int _x;
	int _y;
	
	ITEM* _pItem;//2���� ���̹���

	//��Ÿ�ӿ�
	TAGPOLY _poly[6];
	int _testX, _testY;
	RECT _rc;
	//�׽�Ʈ��
	



public:
	SKILLUI();
	~SKILLUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void coolDownSetting();
	void coolDownUpdate();
	void coolDownRender(HDC hdc);

public:
	//void setLinkUI(ITEM* item) { _pItem = item; }

};

