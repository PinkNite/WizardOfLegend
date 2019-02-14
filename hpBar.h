#pragma once
#include "object.h"
class HPBAR :public OBJECT
{
private:
	RECT _rc;
	int _x, _y;
	int _frameY;
	int _alpha;
	int _width;
	float _hpWidth;
	float _damageWidth;
	int _count;
	int _count2;
	int _tempHp;
	

public:
	HPBAR();
	~HPBAR();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setGauge(float currentHp, float maxHP);
	void setDamage(float currentHp,float maxHP);

public:
	void setFrameY(int num) { _frameY = num; }
	void setAlpha(int num) { _alpha = num; }
	//렉트 접근자 넓이값을 바꾸자
	RECT getRC() { return _rc; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setRcWidth(int width) { _width = width; }
	int getRcWidth() { return _width; }
	float getDamageWidth() { return _damageWidth; }
	float getHpWidth() { return _hpWidth; }
	float getTempHP() { return _tempHp; }
};

