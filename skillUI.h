#pragma once
#include "object.h"

class ITEM;
class ITEMMANAGER;
class STATUSBOX;
class SKILLUI:public OBJECT
{
private:
	ITEM* _pItem[2];//2���� ���̹���
	image* _pItemImage;
	STATUSBOX* _pStatusBox[2];
	int _numA;//������ ��ȣ
	int _frameX;
	int _frameY;
	int _x;
	int _y;

	

public:
	SKILLUI();
	~SKILLUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	
public:
	//void setLinkUI(ITEM* item) { _pItem = item; }
};

