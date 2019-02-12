#pragma once
#include "object.h"
class STATUSBOX :public OBJECT
{
private:
	int _alpha;
	int _frameX, _frameY;
	RECT _rc;
	int _x, _y;
	bool _isCollision;

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

	//테스트 확인용
	float xx() { return _x; }
	bool dd() { return _isCollision; }
};

