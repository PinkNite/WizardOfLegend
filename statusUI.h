#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
#include "explainUse.h"	
#include "statusButton.h"
#include "skillIcon.h"
#include "item.h"


class PLAYER;

class STATUSUI :public OBJECT
{
private:
	//유아이는 메인 판 그림
	//안에 박스는 따로 그리고
	//셀렉트 박스 따로 그리고 
	//골드창 따로
	PLAYER* _pPlayer;
	PLAYER* _pTemp;

	EXPLAINUSE* _pExplainUse;
	//SKILLICON* _pSkillIcon[6];
	STATUSBUTTON* _pStatusButton[6];
	SKILLICON* _pTempSkill;

	int _num;//변화값


	int _numA;//아이템 번호

	int _x;
	int _y;

	int _alpha;
	RECT _rcText;

	bool _isClick;
	//스왑용 템프
	int _temp;
	int _tempX;

	ITEM* _pItem[12];

	STATUSBOX* _pItemBox[12];

	int _findX[6];
	//설정 바뀐 폰트를 가져올 변수
	const char* _changeFont;

public:
	STATUSBOX* _pStatusBox[10];//이게 늘어나서 아이템을 받아야함
	STATUSBOX* _pTempBox;
	int _count;//스왑?
	STATUSSELECT* _pStatusSelect;

	STATUSUI();
	~STATUSUI();
	void setPlayer(PLAYER* p) { _pPlayer = p; }
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void collision();
	void spaceKeyAndLButton();
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void fontRender2(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);
	void swapSetting();//스왑을 하여라
	void skillSetting();//스킬 몇개를 가지고 있을 것이냐? 스킬이 사용 가능해지는 것들을 처리하자 

public:
	//접근자
	bool getIsClick() { return _isClick; }
	void setIsClick(SELECTSTATE num) { _pStatusSelect->setSelectState(num); }


};

