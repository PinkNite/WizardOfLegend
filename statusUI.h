#pragma once
#include "object.h"
#include "statusSelect.h"
class STATUSUI:public OBJECT
{
private:
	STATUSSELECT* _pStatusSelect;
public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

