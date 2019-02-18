#pragma once
#include "object.h"
#include "skillIcon.h"
//#pragma warning(disable:4996)
struct TAGFONT
{
	const char* str;
};

enum SKILLUSE
{
	USE,
	UN_USE
	//�׽�Ʈ�� �̳ѹ� ����� ����� ���� 
	//�÷��̾ų��� �޾ƿ������� �� �̳ѹ���
};

struct TAGPOLY //�ٰ��� ����ü
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
	int _alphaBlack;
	string _imageName;
	//��Ÿ�ӿ�

	RECT _rc;
	TAGPOLY _poly;
	float _skillCool;
	float _skillCoolMax;
	int _count;
	
public:
	SKILLICON* _pSkillIcon;
	SKILLBOX();
	~SKILLBOX();
	HRESULT init(int x, int y,string imageName,float cool);
	void release();
	void update();
	void render(HDC hdc);
	void coolDownSetting();
	void coolDownUpdate();
	void coolDownRender(HDC hdc);
	void fontSetting(float cool);
	void fontUpdate();
	void fontRender(HDC hdc);
	void fontRender(HDC hdc, float coolTime, const char* str2, int x, int y, int num, COLORREF color);
public:
	void setFrameX(int num) { _frameX = num; }
	void setAlpha(int num) { _alpha = num; }
	int getAlpha() { return _alpha; }
	void setSkillUse(SKILLUSE num) { _poly.isUse = num; }
	SKILLUSE getSkillUse() { return _poly.isUse; }
	void setImageName(string name) { _imageName = name; }
	void setX(int x) { _x = x; }
	int getX() { return _x; }
	void setY(int y) { _y= y; }
	int getY() { return _y; }

};

