#pragma once
#include "object.h"
#include "animation.h"
#include "relics_Ring.h"
#include "relics_Type.h"
#include "button.h"

class RELICS_COVER :public OBJECT
{
private:
	int _frameY;
	int _alpha;
	animation* _pAni;
	RELICS_RING* _pRing[2];
	

	int _y;
	
public:
	RELICS_TYPE* _pType;
	RELICS_COVER();
	~RELICS_COVER();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void pixelCollision(HDC hdc);
	
	void aniStart();
	
public:
	int getFrameY() { return _frameY; }
	void setFrameY(int num) { _frameY = num; }
	
};

