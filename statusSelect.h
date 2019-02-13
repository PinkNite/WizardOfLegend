#pragma once
#include "object.h"
enum SELECTSTATE
{
	ITEM_STATE,//�����ۼ���?�����ۼ�������
	SKILL_STATE,//��ų���� ������
	SWAP_STATE //���ҿ�
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
	//������ ������
	RECT getRC()const { return _rc; }
	//�Ұ� �浹
	void setIsCollision(bool num) { _isCollision = num; }
	//���̰��� ���� ������ �̹���
	float getY() { return _y; }
	int getAlpha() { return _alpha; }

	SELECTSTATE getSelectState() { return _selectState; }
	void setSelectState(SELECTSTATE num) { _selectState = num; }
};

