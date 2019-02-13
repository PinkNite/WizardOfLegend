#pragma once
#include "skillButton.h"
#include "object.h"
class SKILLBUTTON:public OBJECT
{
private:
	int _x, _y;
	int _frameX;
	int _alpha;
public:
	SKILLBUTTON();
	~SKILLBUTTON();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	void setFrameX(int num) { _frameX = num; }
	void setAlpha(int num) { _alpha = num; }
};

