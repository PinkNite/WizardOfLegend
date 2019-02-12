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
	//������ ������
	void setFrameX(int num) { _frameX = num; }
	int getFrameX() { return _frameX; }
	RECT getRC() const { return _rc; }
	void setIsCollision(bool num) { _isCollision = num; }
	bool getIsCollision() { return _isCollision; }
	//���İ� ������
	int getAlpha() { return _alpha; }
	void setAlpha(int alpha) { _alpha = alpha; }

	//�׽�Ʈ Ȯ�ο�
	float xx() { return _x; }
	bool dd() { return _isCollision; }
};

