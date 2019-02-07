#pragma once
#include "object.h"
class UI:public OBJECT
{
private:
	
public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

