#pragma once
#include "object.h"
#include "skillIcon.h"
#include "player.h"
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
	int _index;//���� ��ȣ�� ã�ƾ��ϱ⶧����

	PLAYER* _pPlayer;
public:
	SKILLICON* _pSkillIcon;
	STATUSBOX();
	~STATUSBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setSkillXY(int x, int y);
	//��ų ��ȣ
	void setSkillNum(SKILLNUMBER num);
public:
	//������ ������
	int getX(){return _x;}
	int getY(){return _y;}
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setFrameX(int num) { _frameX = num; }
	int getFrameX() { return _frameX; }
	RECT getRC() const { return _rc; }
	void setIsCollision(bool num) { _isCollision = num; }
	bool getIsCollision() { return _isCollision; }
	//���İ� ������
	int getAlpha() { return _alpha; }
	void setAlpha(int alpha) { _alpha = alpha; }
	//�ε�����ȣ �迭��ȣ ������
	int getIndex() { return _index; }
	void setIndex(int num) { _index = num; }
	//�������� ������ �ִ� ��ų ���� ������
	//SKILLNUMBER getSkillNumber() { return _skillNumber; }
	//void setSkillNumber(SKILLNUMBER num) { _skillNumber = num; }
	//���ȹڽ���ġ�� ���� ��ų�ڽ� ��ġ�� �������� x y��ǥ
	int getSkillX() { return _skillX; }
	void setSkillX(int x) { _skillX = x; }
	int getSkillY() { return _skillY; }
	void setSkillY(int y) { _skillY = y; }
	//��ų ��ȣ
	SKILLNUMBER getSkillNum() { return _skillNum; }
	




	//Ŭ������ ������
	bool getIsClick() { return _isClick; }
	void setIsClick(bool num) { _isClick = num; }
	//�׽�Ʈ Ȯ�ο�
	float xx() { return _x; }
	bool dd() { return _isCollision; }

	//��ũ������
	void setPlayer(PLAYER* p) { _pPlayer = p; }
};

