#pragma once
#include "object.h"
#include "skillBox.h"
#include "skillIcon.h"


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
	
	int _x;
	int _y;
	
	ITEM* _pItem;//2번은 맵이미지
	string _name;
	
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

