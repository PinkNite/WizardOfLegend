#pragma once
#include "object.h"
class FONT:public OBJECT
{
public:
	FONT();
	~FONT();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

