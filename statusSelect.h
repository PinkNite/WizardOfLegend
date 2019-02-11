#pragma once
#include "object.h"

class STATUSSELECT:public OBJECT
{
	float _x, _y;
public:
	STATUSSELECT();
	~STATUSSELECT();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

