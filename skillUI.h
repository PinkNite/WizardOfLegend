#pragma once
#include "object.h"

class SKILLBUTTON;
class ITEMMANAGER;
class STATUSBOX;
class SKILLUI :public OBJECT
{
private:
	
	image* _pItemImage;
	STATUSBOX* _pStatusBox[2];
	SKILLBUTTON* _pSkillButton[8];
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

