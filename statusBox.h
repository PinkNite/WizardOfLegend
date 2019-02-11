#pragma once
#include "object.h"
class STATUSBOX:public OBJECT
{
private:
	int _alpha;
	int _frameX, _frameY;
	RECT _rc;
	int _x, _y;
public:
	STATUSBOX();
	~STATUSBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setFrameX(int num) { _frameX = num; }
	RECT getRC() { return _rc; }
};

