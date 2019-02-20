#pragma once
#include "object.h"
#include "skillIcon.h"

enum SKILLNUMBER
{
	SKILL_0,
	SKILL_1,
	SKILL_2,
	SKILL_3,
	SKILL_4,
	SKILL_5,
	SKILL_EMPTY
};
enum SKILLNAMES
{
	SKILL_NAME_NONE,
	SKILL_NAME_0,
	SKILL_NAME_1,
	SKILL_NAME_2,
	SKILL_NAME_3,
	SKILL_NAME_4,
	SKILL_NAME_5,
	SKILL_NAME_6,
	SKILL_NAME_7,
	SKILL_NAME_8,
	SKILL_NAME_EMPTY
};
class STATUSBOX :public OBJECT
{
private:
	int _alpha;
	int _frameX, _frameY;
	RECT _rc;
	int _x, _y;
	bool _isCollision;
	bool _isClick;

	int _skillX;
	int _skillY;
	SKILLNUMBER _skillNum;
	SKILLNAMES _skillName;
	int _index;//템프 번호로 찾아야하기때문에

	bool _isItem;//콜리젼인게 아이템이다.

	
public:
	SKILLICON* _pSkillIcon;
	STATUSBOX();
	~STATUSBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setSkillXY(int x, int y);
	//스킬 번호
	void setSkillNum(SKILLNUMBER num);

public:
	//접근자 참조자
	int getX(){return _x;}
	int getY(){return _y;}
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setFrameX(int num) { _frameX = num; }
	int getFrameX() { return _frameX; }
	RECT getRC() const { return _rc; }
	void setIsCollision(bool num) { _isCollision = num; }
	bool getIsCollision() { return _isCollision; }
	//알파값 접근자
	int getAlpha() { return _alpha; }
	void setAlpha(int alpha) { _alpha = alpha; }
	//인덱스번호 배열번호 접근자
	int getIndex() { return _index; }
	void setIndex(int num) { _index = num; }
	//아이템이 가지고 있는 스킬 상태 접근자
	//SKILLNUMBER getSkillNumber() { return _skillNumber; }
	//void setSkillNumber(SKILLNUMBER num) { _skillNumber = num; }
	//스탯박스위치에 따라 스킬박스 위치를 지정해줄 x y좌표
	int getSkillX() { return _skillX; }
	void setSkillX(int x) { _skillX = x; }
	int getSkillY() { return _skillY; }
	void setSkillY(int y) { _skillY = y; }
	//스킬 번호
	SKILLNUMBER getSkillNum() { return _skillNum; }
	//void setSkillNum(SKILLNUMBER num) { _skillNum = num; }
	//스킬네임
	SKILLNAMES getSkillName() { return _skillName; }
	void setSkillName(SKILLNAMES num) { _skillName = num; }
	//스탯박스
	//아이템 상태냐
	bool getIsItem() { return _isItem; }
	void setIsItem(bool num) { _isItem = num; }



	//클릭상태 접근자
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }
	//테스트 확인용
	float xx() { return _x; }
	bool dd() { return _isCollision; }


};

