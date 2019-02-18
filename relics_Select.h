#pragma once
#include "object.h"
class RELICS_SELECT :public OBJECT
{
public:
	RELICS_SELECT();
	~RELICS_SELECT();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

