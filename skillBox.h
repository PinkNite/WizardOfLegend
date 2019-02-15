#pragma once
#include "object.h"
enum SKILLUSE
{
	USE,
	UN_USE
	//테스트용 이넘문 지울것 까먹지 말자 
	//플레이어스킬사용 받아오기전에 쓸 이넘문임
};

struct TAGPOLY //다각형 구조체
{
	float angle[4];
	POINT pos[4];
	SKILLUSE isUse;
};
class SKILLBOX:public OBJECT
{
private:
	int _frameX;
	int _x, _y;
	int _alpha;

	//쿨타임용
	TAGPOLY _poly[6];
	int _testX, _testY;
	RECT _rc;
	//테스트용
public:
	SKILLBOX();
	~SKILLBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void coolDownSetting();
	void coolDownUpdate();
	void coolDownRender(HDC hdc);
public:
	void setFrameX(int num) { _frameX = num; }
	void setAlpha(int num) { _alpha = num; }
	int getAlpha() { return _alpha; }
};

