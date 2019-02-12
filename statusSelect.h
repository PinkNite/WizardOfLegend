#pragma once
#include "object.h"

class STATUSSELECT:public OBJECT
{
	float _x, _y;
	int _alpha;
	RECT _rc;
	bool _isCollision;
public:
	STATUSSELECT();
	~STATUSSELECT();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void keySetting();
public:
	//������ ������
	RECT getRC()const { return _rc; }
	//�Ұ� �浹
	void setIsCollision(bool num) { _isCollision = num; }
	//���̰��� ���� ������ �̹���
	float getY() { return _y; }
	
};

