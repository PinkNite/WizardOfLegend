#pragma once
#include "object.h"

class RELICS_TYPE :public OBJECT
{
private:

	int _frameY;
public:
	RELICS_TYPE();
	~RELICS_TYPE();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	int getFrameY() { return _frameY; }
	void setFrameY(int y) { _frameY = y; }
};

