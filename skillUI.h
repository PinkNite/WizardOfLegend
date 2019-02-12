#pragma once
#include "object.h"

class ITEM;
class ITEMMANAGER;
class STATUSBOX;
class SKILLUI:public OBJECT
{
private:
	ITEM* _pItem[2];//2번은 맵이미지
	image* _pItemImage;
	STATUSBOX* _pStatusBox[2];
	int _numA;//아이템 번호
	int _frameX;
	int _frameY;
	int _x;
	int _y;

	int count;
	RECT _rcText;

public:
	SKILLUI();
	~SKILLUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	
public:
	//void setLinkUI(ITEM* item) { _pItem = item; }
};

