#pragma once
#include "object.h"
#include "animation.h"
class RELICS_RING : public OBJECT
{
private:
	animation* _pAni;
public:
	RELICS_RING();
	~RELICS_RING();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
};

