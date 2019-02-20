#pragma once
#include "animation.h"
#include "object.h"
class ITEMWHITE :public OBJECT
{
private:
	animation* _pAni;
	int _x, _y;
	bool _isAction;
	int _count;
public:

	ITEMWHITE();
	~ITEMWHITE();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	bool getIsAction() { return _isAction; }
	void setIsAction(bool n) { _isAction = n; }
};

