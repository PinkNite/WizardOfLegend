#pragma once
#include "object.h"
class RELICS_HOME :public OBJECT
{
private:
	int _frameX;
public:
	RELICS_HOME();
	~RELICS_HOME();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	int getFrameX() { return _frameX; }
	void setFrameX(int num) { _frameX = num; }
};

