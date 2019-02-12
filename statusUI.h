#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
class STATUSUI:public OBJECT
{
private:
	//유아이는 메인 판 그림
	//안에 박스는 따로 그리고
	//셀렉트 박스 따로 그리고 
	STATUSBOX* _pStatusBox[6];
	STATUSSELECT* _pStatusSelect;
	int _num;//변화값

	int _count;
	
public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
};

