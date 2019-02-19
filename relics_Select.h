#pragma once
#include "object.h"
class RELICS_SELECT :public OBJECT
{
private:
	int _frameY;
	int _alpha;
public:
	RELICS_SELECT();
	~RELICS_SELECT();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	int getFrameY() { return _frameY; }
	void setFrameY(int num) { _frameY = num; }
	int getAlpha() { return _alpha; }
	void setAlpha(int num) { _alpha = num; }
};

