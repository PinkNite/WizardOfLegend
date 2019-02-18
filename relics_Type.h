#pragma once
#include "object.h"
#include "animation.h"
class RELICS_TYPE :public OBJECT
{
private:
	animation* _pAni;
	int _frameY;
public:
	RELICS_TYPE();
	~RELICS_TYPE();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

