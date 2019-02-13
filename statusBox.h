#pragma once
#include "object.h"
enum SKILLNUMBER
{
	SKILL_1,
	SKILL_2,
	SKILL_3,
	SKILL_4,
	SkILL_5,
	SKILL_6,
	SKILL_EMPTY
};
class STATUSBOX :public OBJECT
{
private:
	SKILLNUMBER _skillNumber;
	int _alpha;
	int _frameX, _frameY;
	RECT _rc;
	int _x, _y;
	bool _isCollision;
	bool _isClick;

public:
	STATUSBOX();
	~STATUSBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	//접근자 참조자
	void setFrameX(int num) { _frameX = num; }
	int getFrameX() { return _frameX; }
	RECT getRC() const { return _rc; }
	void setIsCollision(bool num) { _isCollision = num; }
	bool getIsCollision() { return _isCollision; }
	//알파값 접근자
	int getAlpha() { return _alpha; }
	void setAlpha(int alpha) { _alpha = alpha; }

	//아이템이 가지고 있는 스킬 상태 접근자
	SKILLNUMBER getSkillNumber() { return _skillNumber; }
	void setSkillNumber(SKILLNUMBER num) { _skillNumber = num; }

	//클릭상태 접근자
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }
	//테스트 확인용
	float xx() { return _x; }
	bool dd() { return _isCollision; }
};

