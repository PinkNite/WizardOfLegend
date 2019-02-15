#pragma once
#include "object.h"

enum SKILLUSE
{
	USE,
	UN_USE
	//테스트용 이넘문 지울것 까먹지 말자 
	//플레이어스킬사용 받아오기전에 쓸 이넘문임
};


class ITEM;
class FONT;
class SKILLBUTTON;
class STATUSBOX;
class SKILLICON;
struct TAGPOLY //다각형 구조체
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
	
	ITEM* _pItem;//2번은 맵이미지

	//쿨타임용
	TAGPOLY _poly[6];
	int _testX, _testY;
	RECT _rc;
	//테스트용
	



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

