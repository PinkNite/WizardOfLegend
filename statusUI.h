#pragma once
#include "object.h"
#include "statusSelect.h"
#include "statusBox.h"
#include "explainUse.h"	
#include "statusButton.h"
#include "skillIcon.h"
#include "player.h"



class ITEM;
class STATUSUI :public OBJECT
{
public:
	//유아이는 메인 판 그림
	//안에 박스는 따로 그리고
	//셀렉트 박스 따로 그리고 
	//골드창 따로
	PLAYER* _pPlayer;

	STATUSBOX* _pStatusBox[7];
	STATUSBOX* _pTempBox;
	STATUSSELECT* _pStatusSelect;
	ITEM* _pItem[2];//2번은 맵이미지
	EXPLAINUSE* _pExplainUse;
	//SKILLICON* _pSkillIcon[6];
	STATUSBUTTON* _pStatusButton[16];
	SKILLICON* _pTempSkill;
	int _num;//변화값

	int _count;//스왑?

	int _numA;//아이템 번호

	int _x;
	int _y;
	
	int _alpha;
	RECT _rcText;

	bool _isClick;
	//스왑용 템프
	int _temp;
	int _tempX;
	
	

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
	void skillSetting();//스킬 몇개를 가지고 있을 것이냐? 스킬이 사용 가능해지는 것들을 처리하자 
public:
	//접근자
	bool getIsClick() { return _isClick; }
	void setIsClick(SELECTSTATE num) { _pStatusSelect->setSelectState(num); }
	
	
	void setPlayer(PLAYER* p) { _pPlayer = p; }
};

