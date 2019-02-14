#pragma once
#include "object.h"
class MPBAR:public OBJECT
{
private:
	int _alpha;
	int _x, _y;
	int _mpWidth;
	int _width;
	RECT _rc;
	int _count;

public:
	MPBAR();
	~MPBAR();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setGauge(float mp, float maxMP);
	
public :
	void setAlpha(int num) { _alpha = num; }
	//렉트 접근자 넓이값을 바꾸자
	RECT getRC() { return _rc; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setRcWidth(int width) { _width = width; }
	int getRcWidth() { return _width; }
	float getMpWidth() { return _mpWidth; }
};

