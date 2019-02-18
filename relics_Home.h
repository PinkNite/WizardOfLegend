#pragma once
#include "object.h"
class RELICS_HOME :public OBJECT
{
public:
	RELICS_HOME();
	~RELICS_HOME();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

