#pragma once
#include "object.h"
#include "skillBox.h"



class ITEM;
class FONT;
class SKILLBUTTON;
class STATUSBOX;
class SKILLICON;

class SKILLUI :public OBJECT
{
private:


	STATUSBOX* _pStatusBox[2];
	SKILLBUTTON* _pSkillButton[8];
	FONT* _pFont[2];
	SKILLICON* _pSkillIcon[6];
	SKILLBOX* _pSkillBox[6];
	
	int _x;
	int _y;
	
	ITEM* _pItem;//2번은 맵이미지

	
	



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

