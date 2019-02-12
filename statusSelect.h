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
	//접근자 참조자
	RECT getRC()const { return _rc; }
	//불값 충돌
	void setIsCollision(bool num) { _isCollision = num; }
	//와이값에 따라 나오는 이미지
	float getY() { return _y; }
	
};

