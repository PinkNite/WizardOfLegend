#pragma once
#include "object.h"


class ITEMMANAGER;
class STATUSBOX;
class SKILLUI :public OBJECT
{
private:
	
	image* _pItemImage;
	STATUSBOX* _pStatusBox[2];

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

