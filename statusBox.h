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
	//������ ������
	void setFrameX(int num) { _frameX = num; }
	int getFrameX() { return _frameX; }
	RECT getRC() const { return _rc; }
	void setIsCollision(bool num) { _isCollision = num; }
	bool getIsCollision() { return _isCollision; }
	//���İ� ������
	int getAlpha() { return _alpha; }
	void setAlpha(int alpha) { _alpha = alpha; }

	//�������� ������ �ִ� ��ų ���� ������
	SKILLNUMBER getSkillNumber() { return _skillNumber; }
	void setSkillNumber(SKILLNUMBER num) { _skillNumber = num; }

	//Ŭ������ ������
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }
	//�׽�Ʈ Ȯ�ο�
	float xx() { return _x; }
	bool dd() { return _isCollision; }
};

