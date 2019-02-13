#pragma once
#include "object.h"
class STATUSBUTTON:public OBJECT
{
private:
	int _x, _y;
	int _frameX;
public:
	STATUSBUTTON();
	~STATUSBUTTON();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	void setFrameX(int num) { _frameX = num; }
};

