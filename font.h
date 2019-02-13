#pragma once
#include "object.h"
class FONT:public OBJECT
{
private:
	int _x, _y;
	int _frameX;
public:
	FONT();
	~FONT();
	HRESULT init(int x ,int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	//Á¢±ÙÀÚ
	void setFrameX(int num) { _frameX = num; }
};

