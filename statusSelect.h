#pragma once
#include "object.h"

class STATUSSELECT:public OBJECT
{
	float _x, _y;
	int _alpha;
	RECT _rc;
public:
	STATUSSELECT();
	~STATUSSELECT();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
public:
	RECT getRC() { return _rc; }
};

