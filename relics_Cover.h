#pragma once
#include "object.h"
#include "animation.h"
class RELICS_COVER :public OBJECT
{
private:
	int _frameY;
	int _alpha;
	animation* _pAni;
public:
	RELICS_COVER();
	~RELICS_COVER();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	int getFrameY() { return _frameY; }
	void setFrameY(int num) { _frameY = num; }
	
};

