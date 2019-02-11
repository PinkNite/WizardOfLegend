#pragma once
#include "object.h"
class STATUSBOX:public OBJECT
{
private:
	int _alpha;
	int _frameX, _frameY;
public:
	STATUSBOX();
	~STATUSBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setFrameX(int num) { _frameX = num; }
};

