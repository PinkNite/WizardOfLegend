#pragma once
#include "object.h"
#include "relics_Type.h"
class RELICS :public OBJECT
{
private:

public:
	RELICS();
	~RELICS();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

