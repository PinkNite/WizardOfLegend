#pragma once
#include "object.h"
enum SELECTSTATE
{
	ITEM_STATE,//아이템선택?아이템설명나오게
	SKILL_STATE,//스킬설명 나오게
	SWAP_STATE //스왑용
};
class STATUSSELECT :public OBJECT
{
private:
	float _x, _y;
	int _alpha;
	RECT _rc;
	bool _isCollision;
	SELECTSTATE _selectState;
public:
	STATUSSELECT();
	~STATUSSELECT();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void keySetting();
	void selectStateChange();
public:
	//접근자 참조자
	RECT getRC()const { return _rc; }
	//불값 충돌
	void setIsCollision(bool num) { _isCollision = num; }
	//와이값에 따라 나오는 이미지
	float getY() { return _y; }
	int getAlpha() { return _alpha; }

	SELECTSTATE getSelectState() { return _selectState; }
	void setSelectState(SELECTSTATE num) { _selectState = num; }
};

