#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
#include "explainUse.h"	
class ITEM;

class STATUSUI :public OBJECT
{
private:
	//유아이는 메인 판 그림
	//안에 박스는 따로 그리고
	//셀렉트 박스 따로 그리고 
	//골드창 따로
	STATUSBOX* _pStatusBox[7];
	STATUSSELECT* _pStatusSelect;
	ITEM* _pItem[2];//2번은 맵이미지
	EXPLAINUSE* _pExplainUse;
	int _num;//변화값

	int _count;

	int _numA;//아이템 번호
	
	int _x;
	int _y;
	int _alpha;
	RECT _rcText;

	bool _isClick;
public:
	STATUSUI();
	~STATUSUI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void fontRender2(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void swapSetting();//스왑을 하여라
public :
	//접근자
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }

};

