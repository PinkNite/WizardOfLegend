#pragma once
#include "object.h"
class PLAYERFACE :public OBJECT
{
private:
	int _x, _y;
	int _frameY;// 혹시 플레이어 추가이미지면 필요
	int _alpha;

public:
	PLAYERFACE();
	~PLAYERFACE();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	void setAlpha(int num) { _alpha = num; }
	void setFrameY(int num) { _frameY = num; }

};

