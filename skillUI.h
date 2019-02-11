#pragma once
#include "object.h"

class ITEM;
class ITEMMANAGER;
class SKILLUI:public OBJECT
{
private:
	ITEM* _pItem[6];
	image* _pItemImage;
	int _numA;//아이템 번호
	int _frameX;
	int _frameY;

	

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

