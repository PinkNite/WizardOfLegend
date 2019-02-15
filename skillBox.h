#pragma once
#include "object.h"
class SKILLBOX:public OBJECT
{
public:
	SKILLBOX();
	~SKILLBOX();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

