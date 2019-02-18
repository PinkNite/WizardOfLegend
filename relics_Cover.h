#pragma once
#include "object.h"
class RELICS_COVER :public OBJECT
{
public:
	RELICS_COVER();
	~RELICS_COVER();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

