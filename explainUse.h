#pragma once
#include "explainUse.h"
#include "object.h"
class EXPLAINUSE :public OBJECT
{
private:
	int _x, _y;
	int _frameX;
	bool _isSelect;
	int _alpha;

public:
	EXPLAINUSE();
	~EXPLAINUSE();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void alphaPlus(int alpha);
public:
	void setFrameX(int num) { _frameX = num; }
	bool getIsSelect() { return _isSelect; }
	void setIsSelect(bool numA) { _isSelect = numA; }
};

