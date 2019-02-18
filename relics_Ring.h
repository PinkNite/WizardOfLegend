#pragma once
#include "object.h"
class RELICS_RING : public OBJECT
{
public:
	RELICS_RING();
	~RELICS_RING();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

