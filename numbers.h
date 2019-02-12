#pragma once
#include "object.h"
class NUMBERS :public OBJECT
{
private:
	int _x, _y, _frameX;
public:
	NUMBERS();
	~NUMBERS();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

